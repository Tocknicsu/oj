#ifndef STABLE_VECTOR_HPP
#define STABLE_VECTOR_HPP
 
#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <vector>
 
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
               
                stable_vector() {
                        v.push_back(new node);
                        v.back() -> datum = 1;
                        v.back() -> up = v.end() - 1;
                }
 
                explicit stable_vector(const size_type n, const T& value = T()) {
                        (*this) = stable_vector();
                        for (int i = 0; i < n; i++) push_back(value);
                }
 
                template<typename InputIterator>
                stable_vector(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr) {
                        (*this) = stable_vector();
                        for (InputIterator it = first; it != last; it++) push_back(*it);
                }
 
                stable_vector(const stable_vector& rhs) { (*this) = rhs; }
 
                stable_vector& operator=(const stable_vector& rhs) {
                        clear();
                        for (int i = 0; i < rhs.size(); i++) push_back(rhs[i]);
                        return (*this);
                }
 
                ~stable_vector() { for (int i = 0; i < v.size(); i++) delete v[i]; }
 
                void assign(const size_type n, const T& value) { (*this) = stable_vector(n, value); }
                template<typename InputIterator>
                void assign(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr) { (*this) = stable_vector(first, last); }
 
                reference at(const size_type pos) { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); }
                const_reference at(const size_type pos) const { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); }
 
                reference operator[](const size_type pos) { return v[pos] -> datum; }
                const_reference operator[](const size_type pos) const { return v[pos] -> datum; }
 
                reference front() { return v.front() -> datum; }
                const_reference front() const { return v.front() -> datum; }
 
                reference back() { return v[v.size() - 2] -> datum; }
                const_reference back() const { return v[v.size() - 2] -> datum; }
 
                iterator begin() { return iterator(v.front()); }
                const_iterator begin() const { return const_iterator(v.front()); }
                const_iterator cbegin() const { return const_iterator(v.front()); }
 
                iterator end() { return iterator(v.back()); }
                const_iterator end() const { return const_iterator(v.back()); }
                const_iterator cend() const { return const_iterator(v.back()); }
 
                bool empty() const { return v.size() == 1; }
                size_type size() const { return v.size() - 1; }
                void clear() {
                        for (int i = 0; i < v.size(); i++) delete v[i];
                        v.clear();
                        v.push_back(new node);
                        v.back() -> datum = 1;
                        v.back() -> up = v.end() - 1;
                }
 
                iterator insert(const_iterator pos, const T& value) {
                        difference_type p = pos - begin();
                        node* n = new node;
                        n -> datum = value;
                        n -> up = v.insert(v.begin() + p, n);
                        for (typename vector_type::iterator it = ((*v.begin()) -> up != v.begin() ? v.begin() : v.begin() + p); it != v.end(); it++)
                                (*it) -> up = it;
                        return iterator(v[p]);
                }
//              template<typename InputIterator>
//              iterator insert(const_iterator pos, InputIterator first, InputIterator last) {
// /**/         iterator re;
//                      for (InputIterator it = first; it != last; it++) re = insert(pos, *it);
//                      return re;
//              }
 
                template<typename InputIterator>
                iterator insert(const_iterator pos, InputIterator first, InputIterator last) {
                        difference_type p = pos - begin();
                        std::vector<T> vec;
                        for (InputIterator it = first; it != last; it++) vec.push_back(*it);
                        for (int i = 0; i < vec.size(); ++i) {
                                node* n = new node;
                                n -> datum = vec[i];
                                v.insert(v.begin() + p + i, n);
                        }
                        for (typename vector_type::iterator it = ((*v.begin()) -> up != v.begin() ? v.begin() : v.begin() + p); it != v.end(); ++it)
                                (*it) -> up = it;
                        return iterator(v[p]);
                }
 
                iterator erase(const_iterator pos) {
                        difference_type p = pos - begin();
                        delete v[p];
                        v.erase(v.begin() + p);
                        for (typename vector_type::iterator it = (*v.begin()) -> up != v.begin() ? v.begin() : v.begin() + p; it != v.end(); it++)
                                (*it) -> up = it;
                        return iterator(v[p]);
                }
 
//              iterator erase(const_iterator first, const_iterator last) {
// /**/         iterator re = erase(iterator(*(first.n -> up)));
//                      while (re != last)
//                              re = erase(iterator(*(re.n -> up)));
//                      return re;
//              }
 
                iterator erase(const_iterator first, const_iterator last) {
                        difference_type p = first - begin();
                        difference_type n = last - first;
                        for (int i = 0; i < n; i++) delete *(v.begin() + p), v.erase(v.begin() + p);
                        for (int i = p; i < v.size(); i++) v[i] -> up = v.begin() + i;
                        return iterator(v[p]);
                }
 
                void push_back(const T& value) { insert(end(), value); }
                void pop_back() { erase(end() - 1); }
 
                void resize(size_type count, const T& value = T()) {
                        while (size() != count)
                                size() > count ? pop_back() : push_back(value);
                }
 
                void swap(stable_vector& other) {
                        std::swap((*this).v, other.v);
                }
 
                friend bool operator==(const stable_vector& lhs, const stable_vector& rhs) { return std::equal(lhs.begin(), lhs.end(), rhs.begin()); }
                friend bool operator!=(const stable_vector& lhs, const stable_vector& rhs) { return !(lhs == rhs); }
                friend bool operator< (const stable_vector& lhs, const stable_vector& rhs) { return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }
                friend bool operator<=(const stable_vector& lhs, const stable_vector& rhs) { return lhs == rhs || lhs < rhs; }
                friend bool operator> (const stable_vector& lhs, const stable_vector& rhs) { return !(lhs <= rhs); }
                friend bool operator>=(const stable_vector& lhs, const stable_vector& rhs) { return !(lhs < rhs); }
 
                class iterator {
                        friend class stable_vector;
 
                        public:
                                typedef stable_vector::difference_type difference_type;
                                typedef stable_vector::value_type value_type;
                                typedef stable_vector::pointer pointer;
                                typedef stable_vector::reference reference;
                                typedef std::random_access_iterator_tag iterator_category;
 
                                explicit iterator(node* const n_ = nullptr) : n(n_) {}
                                iterator(const iterator& rhs) { n = rhs.n; }
                                iterator& operator=(const iterator& rhs) {
                                        n = rhs.n;
                                        return (*this);
                                }
                                ~iterator() {}
 
                                reference operator*() const { return n -> datum; }
                                pointer operator->() const { return std::addressof(operator*()); }
 
                                friend iterator operator+(iterator it, const difference_type n) { return iterator(*(it.n -> up + n)); }
                                friend iterator operator+(const difference_type n, iterator it) { return it + n; }
                                friend iterator operator-(iterator it, const difference_type n) { return it + (-n); }
                                friend difference_type operator-(const iterator lhs, const iterator rhs) {
                                        return lhs.n -> up > rhs.n -> up ? lhs.n -> up - rhs.n -> up : rhs.n -> up - lhs.n -> up;
                                }
 
                                iterator& operator+=(const difference_type n) { return (*this) = (*this) + n; }
                                iterator& operator-=(const difference_type n) { return (*this) = (*this) - n; }
                               
                                iterator& operator++() { return (*this) += 1; }
                                iterator operator++(int) {
                                        iterator it = (*this);
                                        (*this) += 1;
                                        return it;
                                }
 
                                iterator& operator--() { return (*this) = (*this) - 1; }
                                iterator operator--(int) {
                                        iterator it = (*this);
                                        (*this) -= 1;
                                        return it;
                                }
 
                                reference operator[](const difference_type n) { return *((*this) + n); }
                                const_reference operator[](const difference_type n) const { return *((*this) + n); }
 
                                operator const_iterator() const { return const_iterator(n); }
 
                                friend bool operator==(const iterator lhs, const iterator rhs) { return lhs.n -> up == rhs.n -> up; }
                                friend bool operator!=(const iterator lhs, const iterator rhs) { return lhs.n -> up != rhs.n -> up; }
                                friend bool operator< (const iterator lhs, const iterator rhs) { return lhs.n -> up <  rhs.n -> up; }
                                friend bool operator<=(const iterator lhs, const iterator rhs) { return lhs.n -> up <= rhs.n -> up; }
                                friend bool operator> (const iterator lhs, const iterator rhs) { return lhs.n -> up >  rhs.n -> up; }
                                friend bool operator>=(const iterator lhs, const iterator rhs) { return lhs.n -> up >= rhs.n -> up; }
 
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
 
                                explicit const_iterator(const node* const n_) : n(n_) {}
                                const_iterator(const const_iterator& rhs) { n = rhs.n; }
                                const_iterator& operator=(const const_iterator& rhs) {
                                        n = rhs.n;
                                        return (*this);
                                }
                                ~const_iterator() {}
 
                                friend const_iterator operator+(const_iterator it, const difference_type n) { return const_iterator(*(it.n -> up + n)); }
                                friend const_iterator operator+(const difference_type n, const_iterator it) { return it + n; }
                                friend const_iterator operator-(const_iterator it, const difference_type n) { return it + (-n); }
                                friend difference_type operator-(const const_iterator lhs, const const_iterator rhs) { return lhs.n -> up - rhs.n -> up; }
 
                                const_iterator& operator+=(const difference_type n) { return (*this) = (*this) + n; }
                                const_iterator& operator-=(const difference_type n) { return (*this) = (*this) + n; }
                               
                                const_reference operator*() const { return n -> datum; }
                                const_pointer operator->() const { return std::addressof(operator*()); }
 
                                const_iterator& operator++() { return (*this) += 1; }
                                const_iterator operator++(int) {}
 
                                const_iterator& operator--() { return (*this) -= 1; }
                                const_iterator operator--(int) {}
 
                                const_reference operator[](const difference_type n) const { return *((*this) + n); }
 
                                friend bool operator==(const const_iterator lhs, const const_iterator rhs) { return lhs.n -> up == rhs.n -> up; }
                                friend bool operator!=(const const_iterator lhs, const const_iterator rhs) { return lhs.n -> up != rhs.n -> up; }
                                friend bool operator< (const const_iterator lhs, const const_iterator rhs) { return lhs.n -> up <  rhs.n -> up; }
                                friend bool operator<=(const const_iterator lhs, const const_iterator rhs) { return lhs.n -> up <= rhs.n -> up; }
                                friend bool operator> (const const_iterator lhs, const const_iterator rhs) { return lhs.n -> up >  rhs.n -> up; }
                                friend bool operator>=(const const_iterator lhs, const const_iterator rhs) { return lhs.n -> up >= rhs.n -> up; }
 
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
