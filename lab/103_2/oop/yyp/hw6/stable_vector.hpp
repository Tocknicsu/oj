#ifndef STABLE_VECTOR_HPP
#define STABLE_VECTOR_HPP

#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <vector>

#include <iostream>
using namespace std;

template<typename T>
class stable_vector {
    private:
        struct node;
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef std::size_t size_type; 
        typedef std::ptrdiff_t difference_type; 
        class iterator;
        class const_iterator;
        stable_vector(){		//stage1
            node* now = new node();
            now->up = v.insert(v.end(), now);
        }
        explicit stable_vector(const size_type n, const T& value = T()) {
            (*this) = stable_vector();
            for(int i = 0 ; i < n ; i++)
                push_back(value);
        }
        template<typename InputIterator>
            stable_vector(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr){
                (*this) = stable_vector();
                for(InputIterator now = first ; now != last ; ++now)
                    push_back(*now);
            }
        stable_vector(const stable_vector& rhs){
            (*this) = rhs;
        }
        stable_vector& operator=(const stable_vector& rhs){
            if( this == &rhs ) return *this;
            while(v.size())
                pop_back();
            node* now = new node();
            now->up = v.insert(v.end(), now);
            for(int i = 0 ; i < rhs.size() ; i++)
                push_back(rhs[i]);
        }
        ~stable_vector() {
            clear();
            pop_back();
        }
        void assign(const size_type n, const T& value) {
            (*this) = stable_vector(n, value);
        }
        template<typename InputIterator>
            void assign(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr){
                (*this) = stable_vector(first, last);
            }
        reference at(const size_type pos) { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); } const_reference at(const size_type pos) const { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); }
        reference operator[](const size_type pos) { return v[pos]->datum; }					//stage2
        const_reference operator[](const size_type pos) const { return v[pos]->datum;}		//stage2
        reference front() { return v.front()->datum; }										//stage2
        const_reference front() const { return v.front()->datum; }							//stage2
        reference back() { return v[v.size()-2]->datum; }									//stage2
        const_reference back() const { return v[v.size()-2]->datum; }						//stage2
        iterator begin() { return iterator(*v.begin()); }									//stage4
        const_iterator begin() const { return const_iterator(*v.begin()); }					//stage4
        const_iterator cbegin() const { return const_iterator(*v.begin()); }				//stage4
        iterator end() { return iterator(v.back()); }										//stage4
        const_iterator end() const { return const_iterator(v.back()); }						//stage4
        const_iterator cend() const { return const_iterator(v.back()); }					//stage4
        bool empty() const { return size() == 0; }											//stage1
        size_type size() const { return v.size() - 1; }										//stage1
        void clear() { while(size()) pop_back(); }											//stage6 after
        iterator insert(const_iterator pos, const T& value) {								//stage5
            node* now = new node();
            now->datum = value;
            now->up = v.insert(pos.n->up, now);
            for(typename std::vector<node* >::iterator it = (*v.begin())->up != v.begin() ? v.begin() : now->up ; it != v.end() ; ++it)
                (*it)->up = it;
            return iterator(now);
        }
        template<typename InputIterator>													//stage8
            iterator insert(const_iterator pos, InputIterator first, InputIterator last) {
                vector<node*> tmp;
                for(auto it = first ; it != last ; ++it){
                    node* now = new node();
                    now->datum = *it;
                    tmp.push_back(now);
                }
                int sz = pos-begin();
                v.insert(pos.n->up, tmp.begin(), tmp.end());
                for(auto it = (*v.begin())->up != v.begin() ? v.begin() : v.begin()+sz ; it != v.end() ; ++it)
                    (*it)->up = it;
                return iterator(*(v.begin()+sz));
            }
        iterator erase(const_iterator pos) {												//stage6
            return erase(pos, pos+1);
        }
        iterator erase(const_iterator first, const_iterator last) {							//stage8
            auto start = first.n->up, end = last.n->up;
            for(auto it = first.n->up ; it != last.n->up ; ++it)
                delete *it;
            auto re = v.erase(start, end);
            for(auto it = (*v.begin())->up != v.begin() ? v.begin() : re ; it != v.end() ; ++it)
                (*it)->up = it;
            return iterator(*re);
        }
        void push_back(const T& value) { insert(end(), value); }							//stage5 after
        void pop_back() {																	//stage6
            node* now = v.back();
            v.erase(v.end()-1);
            delete now;
        }
        void resize(size_type count, const T& value = T()) {								//stage10
            while(size() > count) pop_back();
            while(size() < count) push_back(value);
        }
        void swap(stable_vector& other) {													//stage10
            std::swap(v, other.v);
        }
        friend bool operator==(const stable_vector& lhs, const stable_vector& rhs) { return std::equal(lhs.begin(), lhs.end(), rhs.begin());}
        friend bool operator!=(const stable_vector& lhs, const stable_vector& rhs) { return !(lhs == rhs);}
        friend bool operator< (const stable_vector& lhs, const stable_vector& rhs) { return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}
        friend bool operator<=(const stable_vector& lhs, const stable_vector& rhs) { return lhs == rhs || lhs < rhs; }
        friend bool operator> (const stable_vector& lhs, const stable_vector& rhs) { return rhs < lhs; }
        friend bool operator>=(const stable_vector& lhs, const stable_vector& rhs) { return !(lhs < rhs); }
        class iterator {
            friend class stable_vector;
            public:
            typedef stable_vector::difference_type difference_type;
            typedef stable_vector::value_type value_type;
            typedef stable_vector::pointer pointer;
            typedef stable_vector::reference reference;
            typedef std::random_access_iterator_tag iterator_category;
            explicit iterator(node* const n_ = nullptr) : n(n_) {}			//stage3
            iterator(const iterator& rhs) : n(rhs.n) {}						//stage3
            iterator& operator=(const iterator& rhs){						//stage3
                n = rhs.n;
                return (*this);
            }
            ~iterator(){}
            reference operator*() const { return n->datum; }				//stage3
            pointer operator->() const { return std::addressof(operator*()); }
            friend iterator operator+(iterator it, const difference_type n){ return iterator(*(it.n->up+n)); }
            friend iterator operator+(const difference_type n, iterator it){ return it + n; }
            friend iterator operator-(iterator it, const difference_type n){ return it + (-n); }
            friend difference_type operator-(const iterator lhs, const iterator rhs){ return lhs.n->up - rhs.n->up; }
            iterator& operator+=(const difference_type n) {return (*this) = (*this) + n;}
            iterator& operator-=(const difference_type n) {return (*this) = (*this) - n;}
            iterator& operator++() { return (*this) += 1;}
            iterator operator++(int) { iterator re = (*this); ++(*this); return re;}
            iterator& operator--() { return (*this) -= 1;}
            iterator operator--(int) { iterator re = (*this); --(*this); return re;}
            reference operator[](const difference_type n){ return *((*this)+n); }
            const_reference operator[](const difference_type n) const { return (*this+n).n->datum; }
            operator const_iterator() const{								//!!!!before stage5
                return const_iterator(n);
            }
            friend bool operator==(const iterator lhs, const iterator rhs) { return lhs.n->up == rhs.n->up; }
            friend bool operator!=(const iterator lhs, const iterator rhs) { return !(lhs==rhs); }
            friend bool operator< (const iterator lhs, const iterator rhs) { return lhs.n->up < rhs.n->up; }
            friend bool operator<=(const iterator lhs, const iterator rhs) { return lhs < rhs || lhs == rhs; }
            friend bool operator> (const iterator lhs, const iterator rhs) { return rhs < lhs; }
            friend bool operator>=(const iterator lhs, const iterator rhs) { return lhs > rhs || lhs == rhs; }
            private:
            node* n;
        };
        class const_iterator {
            friend class stable_vector;
            public:
            typedef stable_vector::difference_type difference_type;
            typedef stable_vector::value_type value_type;
            typedef stable_vector::pointer pointer;
            typedef stable_vector::reference reference;
            typedef std::random_access_iterator_tag iterator_category;
            explicit const_iterator(const node* const n_) : n(n_) {}			//stage3
            const_iterator(const const_iterator& rhs) : n(rhs.n) {}				//stage3
            const_iterator& operator=(const const_iterator& rhs){				//stage3
                n = rhs.n;
                return (*this);
            }
            ~const_iterator(){}
            friend const_iterator operator+(const_iterator it, const difference_type n){ return const_iterator(*(it.n->up+n)); }
            friend const_iterator operator+(const difference_type n, const_iterator it){ return it + n; }
            friend const_iterator operator-(const_iterator it, const difference_type n){ return it + (-n); }
            friend difference_type operator-(const const_iterator lhs, const const_iterator rhs){ return lhs.n->up - rhs.n->up;}
            const_iterator& operator+=(const difference_type n){ return (*this) = (*this) + n; }
            const_iterator& operator-=(const difference_type n){ return (*this) = (*this) - n; }
            const_reference operator*() const{ return n->datum; }				//stage3
            const_pointer operator->() const { return std::addressof(operator*()); }
            const_iterator& operator++(){ return (*this) += 1;}
            const_iterator operator++(int){ const_iterator re = (*this); (*this) += 1; return re; }
            const_iterator& operator--(){ return (*this) -= 1; }
            const_iterator operator--(int){ const_iterator re = (*this); (*this) -= 1; return re; }
            const_reference operator[](const difference_type n) const { return ((*this)+n).n->datum; }
            friend bool operator==(const const_iterator lhs, const const_iterator rhs) { return lhs.n->up == rhs.n->up; }
            friend bool operator!=(const const_iterator lhs, const const_iterator rhs) { return !(lhs==rhs); }
            friend bool operator< (const const_iterator lhs, const const_iterator rhs) { return lhs.n->up < rhs.n->up; }
            friend bool operator<=(const const_iterator lhs, const const_iterator rhs) { return lhs < rhs || lhs == rhs; }
            friend bool operator> (const const_iterator lhs, const const_iterator rhs) { return rhs < lhs; }
            friend bool operator>=(const const_iterator lhs, const const_iterator rhs) { return lhs > rhs || lhs == rhs; }
            private:
            const node* n;
        };
    private:
        typedef std::vector<node*> vector_type;
        vector_type v;
        struct node {
            T datum;
            typename vector_type::iterator up;
        };
};
#endif
