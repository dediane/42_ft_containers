/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:59:10 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/19 15:45:34 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR
# define RANDOM_ACCESS_ITERATOR

#include <cstddef>
#include <iterator>
#include <algorithm>

namespace ft {
	template<typename T>class random_access_iterator
	{

		public:
			typedef std::ptrdiff_t					difference_type;
			typedef T 								value_type;
			typedef value_type* 					pointer;
			typedef const value_type* 				const_pointer;
			typedef value_type& 					reference;
			typedef const value_type& 				const_reference;
			typedef std::random_access_iterator_tag iterator_category;

		protected:
			pointer _ptr;

		public:
			random_access_iterator() : _ptr(NULL) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const random_access_iterator& src) : _ptr(src._ptr) {}
			random_access_iterator & operator=(random_access_iterator const &rhs) {_ptr = rhs._ptr; return *this;}
			~random_access_iterator() {}
			
			reference operator*() {return *_ptr;};
			const_reference operator*() const {return *_ptr;};
			pointer	operator->() {return *(&_ptr);};
			const_pointer operator->() const {return *(&_ptr);};
			reference operator[](difference_type n) const{return *(_ptr + n);};	
			
			pointer get_ptr() const {return _ptr;};
			operator random_access_iterator<const T>() const { return random_access_iterator<const T>(_ptr);}
			
			random_access_iterator& operator++(void) {*this += 1;return *this;};
			random_access_iterator operator++(int) {random_access_iterator<T>	copy = *this;++*this;return copy;};
			random_access_iterator&	operator--(void) {*this -= 1;return *this;};
			random_access_iterator operator--(int) {random_access_iterator<T>	copy = *this;--*this;return copy;};
			random_access_iterator& operator+=(const difference_type n) {_ptr += n;return *this;};
			random_access_iterator& operator-=(const difference_type n) {_ptr -= n;return *this;};
			
			random_access_iterator operator+(difference_type n) 
			{
				random_access_iterator<T>	copy = *this;
				copy += n;
				return copy;
			};
			
			friend random_access_iterator operator+(difference_type n, random_access_iterator<T> it) 
			{
				random_access_iterator<T>	copy = it._ptr;
				copy += n;
				return copy;
			};

			random_access_iterator operator-(difference_type n) 
			{
				random_access_iterator<T>	copy = *this;
				copy -= n;
				return copy;
			};

			difference_type operator-(const random_access_iterator &other) const
			{
				return this->_ptr - other._ptr;
			};
	};

	template <typename T1, typename T2>
	bool operator==(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs) 
	{return lhs.get_ptr() == rhs.get_ptr();}

	template <typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{return !(lhs.get_ptr() == rhs.get_ptr());}

	template <typename T1, typename T2>
	bool operator<(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{return !(lhs.get_ptr() > rhs.get_ptr()) && !(lhs.get_ptr() == rhs.get_ptr());}

	template <typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{return !(lhs.get_ptr() > rhs.get_ptr());}

	template <typename T1, typename T2>
	bool operator>(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{return lhs.get_ptr() > rhs.get_ptr();}

	template <typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{return !(lhs.get_ptr() < rhs.get_ptr());}

	template <typename T1, typename T2>
	typename random_access_iterator<T1>::difference_type
	operator-(random_access_iterator<T1> const &lhs, random_access_iterator<T2> const &rhs)
	{
		return lhs.get_ptr() - rhs.get_ptr();
	}

}

#endif