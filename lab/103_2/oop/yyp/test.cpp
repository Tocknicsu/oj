#ifndef STABLE_VECTOR_HPP
#define STABLE_VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <vector>
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

        stable_vector(){
            v.push_back(new node);
            v[0]->up = v.end()-1;
            v[0]->datum = 1;
        }

        explicit stable_vector(const size_type n, const T& value = T()){
            stable_vector();
            for(int i = 0 ; i < n ; i++){
                push_back(value);
            }
        }

        template<typename InputIterator>
            stable_vector(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr){
                stable_vector();
                iterator iter(*(v.begin()));
                insert(iter,first,last);
            }

        stable_vector(const stable_vector& rhs){
            *this = rhs;  
        }

        stable_vector& operator=(const stable_vector& rhs){
            for(int i = 0 ; i < rhs.v.size() ; i++){
                iterator iter(rhs.v[i]);
                insert(iter,rhs.v[i]->datum);
            }
            return *this;
        }

        ~stable_vector(){
            clear();
            delete *(v.end()-1);
            v.pop_back();
        }

        void assign(const size_type n, const T& value){
            clear();
            *this = stable_vector(n,value);
        }
        template<typename InputIterator>
            void assign(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr){
                clear();
                *this = stable_vector(first,last);
            }

        reference at(const size_type pos) { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); }
        const_reference at(const size_type pos) const { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); }

        reference operator[](const size_type pos){
            return v[pos]->datum;
        }
        const_reference operator[](const size_type pos) const{
            return v[pos]->datum;
        }

        reference front(){
            return v[0]->datum;
        }
        const_reference front() const{
            return v[0]->datum;    
        }

        reference back(){
            return (*(v.end()-2))->datum;
        }
        const_reference back() const{
            return (*(v.end()-2))->datum;
        }

        iterator begin(){
            iterator iter(v[0]);
            return iter;
        }
        const_iterator begin() const{
            const_iterator citer(v[0]);
            return citer;
        }
        const_iterator cbegin() const{
            const_iterator cciter(v[0]);
            return cciter;
        }

        iterator end(){
            iterator iter(*(v.end()-1));
            return iter;
        }
        const_iterator end() const{
            const_iterator citer(*(v.end()-1));
            return citer;
        }
        const_iterator cend() const{
            const_iterator cciter(*(v.end()-1));
            return cciter;
        }

        bool empty() const{
            return v.size() == 1;
        }

        size_type size() const{
            return v.size()-1;
        }

        void clear(){
            for(int i = 0 ; i < v.size()-1; i++){
                delete v[v.size()-1-i];
                v.pop_back();
            }
        }

        iterator insert(const_iterator pos, const T& value){
            typename vector<node*>::iterator p = pos.n->up;
            v.insert(pos.n->up,new node);
            (*p)->up = p;
            if((*v.begin())->up == v.begin() ){
                for(int i = 0; p+i != v.end(); i++ ){
                    (*(p+i))->up = p+i;
                }
            }
            else if ((*v.begin())->up != v.begin()){
                for(int i = 0; i < v.size(); i++){
                    (*(v.begin()+i))->up = (v.begin()+i);
                }
            }
            return iterator(*p);
        }
        template<typename InputIterator>
            iterator insert(const_iterator pos, InputIterator first, InputIterator last){
                for(int i = 0; (first+i) != last; i++){
                    insert(pos,*(first+i));
                }
            }

        iterator erase(const_iterator pos){
            typename vector<node*>::iterator p = pos.n->up;
            delete pos;
            v.erase(p);
            for(int i = 0; p+i != v.end(); i++){
                (*(p+i))->up = p+i;
            }
            return p;
        }
        iterator erase(const_iterator first, const_iterator last){
            for(int i = 0; (first+i) != last ; i++){
                erase(first+i);
            }
        }

        void push_back(const T& value){
            iterator iter(*(v.end()-1));
            insert(iter,value);
        }
        void pop_back(){
            iterator iter(*(v.end()-1));
            erase(iter);
        }

        void resize(size_type count, const T& value = T()){
            if(size() > count){

            }
            else if (size() < count){

            }
        }

        void swap(stable_vector& other){

        }

        friend bool operator==(const stable_vector& lhs, const stable_vector& rhs){
            return std::equal(lhs.begin(),lhs.end(),rhs.begin());
        }
        friend bool operator!=(const stable_vector& lhs, const stable_vector& rhs){
            return !(lhs == rhs);
        }
        friend bool operator< (const stable_vector& lhs, const stable_vector& rhs){
            return std::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());      
        }
        friend bool operator<=(const stable_vector& lhs, const stable_vector& rhs){
            return lhs == rhs || lhs < rhs;
        }
        friend bool operator> (const stable_vector& lhs, const stable_vector& rhs){
            return !(lhs < rhs);
        }
        friend bool operator>=(const stable_vector& lhs, const stable_vector& rhs){
            return !(lhs < rhs) || lhs == rhs;
        }

        class iterator {
            friend class stable_vector;

            public:
            typedef stable_vector::difference_type difference_type;
            typedef stable_vector::value_type value_type;
            typedef stable_vector::pointer pointer;
            typedef stable_vector::reference reference;
            typedef std::random_access_iterator_tag iterator_category;

            explicit iterator(node* const n_ = nullptr):n(n_){}
            iterator(const iterator& rhs){
                n = rhs.n;
            }
            iterator& operator=(const iterator& rhs){
                n = rhs.n;
                return *this;
            }
            ~iterator(){}

            reference operator*() const{
                return (*this).n -> datum;
            }
            pointer operator->() const { return std::addressof(operator*()); }

            friend iterator operator+(iterator it, const difference_type n){
                return iterator(*((it.n->up)+n));
            }
            friend iterator operator+(const difference_type n, iterator it){
                return iterator(*((it.n->up)+n));      
            }
            friend iterator operator-(iterator it, const difference_type n){
                return iterator(*((it.n->up)-n));
            }
            friend difference_type operator-(const iterator lhs, const iterator rhs){
                return (rhs.n->up)-(lhs.n->up);
            }

            iterator& operator+=(const difference_type n){
                return *this = (*this)+n;
            }
            iterator& operator-=(const difference_type n){
                return *this = (*this)-n;
            }

            iterator& operator++(){
                return *this = (*this)+1;
            }
            iterator operator++(int){
                iterator it(*this);
                *this = (*this)+1;
                return it;
            }

            iterator& operator--(){
                return *this = (*this)-1;
            }
            iterator operator--(int){
                iterator it(*this);
                *this = (*this)-1;
                return it;
            }

            reference operator[](const difference_type n){
                return ((*this)+n).n->datum;    
            }
            const_reference operator[](const difference_type n) const{
                return ((*this)+n).n->datum;
            }

            operator const_iterator() const{
                return const_iterator(n);
            }

            friend bool operator==(const iterator lhs, const iterator rhs){
                return std::equal(lhs.begin(),lhs.end(),rhs.begin());
            }
            friend bool operator!=(const iterator lhs, const iterator rhs){
                return !(lhs == rhs);
            }
            friend bool operator< (const iterator lhs, const iterator rhs){
                return std::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
            }
            friend bool operator<=(const iterator lhs, const iterator rhs){
                return lhs == rhs || lhs < rhs;
            }
            friend bool operator> (const iterator lhs, const iterator rhs){
                return !(lhs < rhs);
            }
            friend bool operator>=(const iterator lhs, const iterator rhs){
                return !(lhs < rhs) || lhs == rhs;
            }

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

            explicit const_iterator(const node* const n_):n(n_){}
            const_iterator(const const_iterator& rhs){
                n = rhs.n;     
            }
            const_iterator& operator=(const const_iterator& rhs){
                n = rhs.n;
                return *this;
            }
            ~const_iterator(){}

            friend const_iterator operator+(const_iterator it, const difference_type n){
                return const_iterator(*((it.n->up)+n));
            }
            friend const_iterator operator+(const difference_type n, const_iterator it){
                return const_iterator(*((it.n->up)+n));
            }
            friend const_iterator operator-(const_iterator it, const difference_type n){
                return const_iterator(*((it.n->up)-n));
            }
            friend difference_type operator-(const const_iterator lhs, const const_iterator rhs){
                return (rhs.n->up)-(lhs.n->up);
            }

            const_iterator& operator+=(const difference_type n){
                return *this = (*this)+n;
            }
            const_iterator& operator-=(const difference_type n){}

            const_reference operator*() const{
                return (*this)->datum;
            }
            const_pointer operator->() const { return std::addressof(operator*()); }

            const_iterator& operator++(){
                return *this = (*this)+1;
            }
            const_iterator operator++(int){
                iterator it(*this);
                *this = (*this)+1;
                return it;
            }

            const_iterator& operator--(){
                return *this = (*this)-1;
            }
            const_iterator operator--(int){
                iterator it(*this);
                *this = (*this)-1;
                return it;
            }

            const_reference operator[](const difference_type n) const{}

            friend bool operator==(const const_iterator lhs, const const_iterator rhs){
                return std::equal(lhs.begin(),lhs.end(),rhs.begin());
            }
            friend bool operator!=(const const_iterator lhs, const const_iterator rhs){
                return !(lhs == rhs);
            }
            friend bool operator< (const const_iterator lhs, const const_iterator rhs){
                return std::equal(lhs.begin(),lhs.end(),rhs.begin());
            }
            friend bool operator<=(const const_iterator lhs, const const_iterator rhs){
                return lhs == rhs || lhs < rhs;
            }
            friend bool operator> (const const_iterator lhs, const const_iterator rhs){
                return !(lhs < rhs);
            }
            friend bool operator>=(const const_iterator lhs, const const_iterator rhs){
                return !(lhs < rhs) || lhs == rhs;
            }

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


#include <iostream>
using namespace std;

int main(){
    stable_vector<int> vec;
    vec.insert(vec.begin(), 3);
}
