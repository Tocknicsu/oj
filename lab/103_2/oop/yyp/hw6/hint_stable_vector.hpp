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
		
		stable_vector();		//stage1
		/* ======= stage6 after start ======= */
		explicit stable_vector(const size_type n, const T& value = T());

		template<typename InputIterator>
		stable_vector(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr);

		stable_vector(const stable_vector& rhs);

		stable_vector& operator=(const stable_vector& rhs);

		~stable_vector();

		void assign(const size_type n, const T& value);
		template<typename InputIterator>
		void assign(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = nullptr);
		/* ======= stage6 after end ======= */
		reference at(const size_type pos) { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); }
		const_reference at(const size_type pos) const { return pos < size() ? (*this)[pos] : throw std::range_error("stable_vector: out of range"); }

		reference operator[](const size_type pos);				//stage2
		const_reference operator[](const size_type pos) const;	//stage2

		reference front();										//stage2
		const_reference front() const;							//stage2

		reference back();										//stage2
		const_reference back() const;							//stage2

		iterator begin();										//stage4
		const_iterator begin() const;							//stage4
		const_iterator cbegin() const;							//stage4

		iterator end();											//stage4
		const_iterator end() const;								//stage4
		const_iterator cend() const;							//stage4

		bool empty() const;										//stage1

		size_type size() const;									//stage1

		void clear();											//stage6 after

		iterator insert(const_iterator pos, const T& value);	//stage5
		template<typename InputIterator>						//stage5 after
		iterator insert(const_iterator pos, InputIterator first, InputIterator last);

		iterator erase(const_iterator pos);						//stage6
		iterator erase(const_iterator first, const_iterator last);	//stage8

		void push_back(const T& value);							//stage5 after
		void pop_back();										//stage6

		void resize(size_type count, const T& value = T());		//stage10

		void swap(stable_vector& other);						//stage10
		/* stage9 start */
		friend bool operator==(const stable_vector& lhs, const stable_vector& rhs);
		friend bool operator!=(const stable_vector& lhs, const stable_vector& rhs);
		friend bool operator< (const stable_vector& lhs, const stable_vector& rhs);
		friend bool operator<=(const stable_vector& lhs, const stable_vector& rhs);
		friend bool operator> (const stable_vector& lhs, const stable_vector& rhs);
		friend bool operator>=(const stable_vector& lhs, const stable_vector& rhs);
		/* stage9 end */
		class iterator {
			friend class stable_vector;

			public:
				typedef stable_vector::difference_type difference_type;
				typedef stable_vector::value_type value_type;
				typedef stable_vector::pointer pointer;
				typedef stable_vector::reference reference;
				typedef std::random_access_iterator_tag iterator_category;
				/* stage3 start */
				explicit iterator(node* const n_ = nullptr);
				iterator(const iterator& rhs);
				iterator& operator=(const iterator& rhs);
				~iterator();

				reference operator*() const;						//stage3
				pointer operator->() const { return std::addressof(operator*()); }
				/* stage3 end */
				/* stage7 start */
				friend iterator operator+(iterator it, const difference_type n);
				friend iterator operator+(const difference_type n, iterator it);
				friend iterator operator-(iterator it, const difference_type n);
				friend difference_type operator-(const iterator lhs, const iterator rhs);

				iterator& operator+=(const difference_type n);
				iterator& operator-=(const difference_type n);
				
				iterator& operator++();
				iterator operator++(int);

				iterator& operator--();
				iterator operator--(int);

				reference operator[](const difference_type n);
				const_reference operator[](const difference_type n) const;
				/* stage7 end */
				operator const_iterator() const;		//before stage5
				/* stage9 start */
				friend bool operator==(const iterator lhs, const iterator rhs);
				friend bool operator!=(const iterator lhs, const iterator rhs);
				friend bool operator< (const iterator lhs, const iterator rhs);
				friend bool operator<=(const iterator lhs, const iterator rhs);
				friend bool operator> (const iterator lhs, const iterator rhs);
				friend bool operator>=(const iterator lhs, const iterator rhs);
				/* stage9 end */
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
				/* stage3 start */
				explicit const_iterator(const node* const n_);
				const_iterator(const const_iterator& rhs);
				const_iterator& operator=(const const_iterator& rhs);
				~const_iterator();
				/* stage3 end */
				/* stage7 start */
				friend const_iterator operator+(const_iterator it, const difference_type n);
				friend const_iterator operator+(const difference_type n, const_iterator it);
				friend const_iterator operator-(const_iterator it, const difference_type n);
				friend difference_type operator-(const const_iterator lhs, const const_iterator rhs);

				const_iterator& operator+=(const difference_type n);
				const_iterator& operator-=(const difference_type n);
				
				const_reference operator*() const;	//stage 3
				const_pointer operator->() const { return std::addressof(operator*()); }

				const_iterator& operator++();
				const_iterator operator++(int);

				const_iterator& operator--();
				const_iterator operator--(int);

				const_reference operator[](const difference_type n) const;
				/* stage7 end */
				/* stage9 start */
				friend bool operator==(const const_iterator lhs, const const_iterator rhs);
				friend bool operator!=(const const_iterator lhs, const const_iterator rhs);
				friend bool operator< (const const_iterator lhs, const const_iterator rhs);
				friend bool operator<=(const const_iterator lhs, const const_iterator rhs);
				friend bool operator> (const const_iterator lhs, const const_iterator rhs);
				friend bool operator>=(const const_iterator lhs, const const_iterator rhs);
				/* stage9 end */
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
