/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:05:51 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/10 16:04:21 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <memory>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cmath>

#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"
#include "iterator_traits.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"

namespace ft
{
 	template <class T> class random_access_iterator;
	template <class T> class reverse_iterator;
}

//https://cplusplus.com/reference/vector/vector/
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
			typedef value_type*										pointer_type;
			typedef value_type&										reference_type;
			typedef Alloc											allocator_type;
			
			//reference & pointer
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			
			//iterators
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const iterator>			const_reverse_iterator;
			
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type				size_type;
			
		private:
			Alloc				_alloc;
			pointer_type		_vector;
			size_type			_size;
			size_type			_capacity;

		
		public:
		//**********************************************//
		// Constructors and destructors                 //
		//**********************************************//

		
			//Constructs an empty container, with no elements.
			explicit vector(const allocator_type &allocator = allocator_type()) : 
			_alloc(allocator), _vector(NULL), _size(0), _capacity(0){};
			
			//Constructs a container with n elements. Each element is a copy of val.
			explicit vector(size_type n, const value_type &value = value_type(), const allocator_type &allocator = allocator_type())
			: _alloc(allocator), _vector(NULL), _size(n), _capacity(n)
			{
				_vector = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_vector[i], value);
			};
			
			//Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator>
			vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL):  _alloc(allocator), _vector(0), _size(0), _capacity(0)
			{
				_vector = _alloc.allocate(0);
				assign(begin, end);
			};
			
			//Constructs a container with a copy of each of the elements in x, in the same order.
			vector(const vector &rhs)
			:  _alloc(rhs._alloc), _vector(0), _size(0), _capacity(0)
			{
				*this = rhs;
			};
			
			~vector(void)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				_alloc.deallocate(_vector, _capacity);
			};
			
			vector &operator=(const vector &other)
			{
				if (_alloc != 0)
					_alloc.deallocate(_alloc, _capacity);
				_alloc = other._alloc;
				_capacity = 0;
				_size = 0;
				_vector = _alloc.allocate(0);
				assign(other.begin(), other.end());
				return (*this);
			};
		
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				clear();
				insert(this->begin(), first, last);
			};
			
			void assign(size_type n, const value_type &value)
			{
				clear();
				insert(begin(), n, value);
			};



//___________________________________________________________________________________________________________________



		//**********************************************//
		// Iterators functions                          //
		//**********************************************//
			iterator				begin() {return iterator(_vector);};
			const_iterator			begin() const {return const_iterator(_vector);};
			
			iterator				end() {return iterator(_vector + _size);};
			const_iterator			end() const {return const_iterator(_vector + _size);};
			
			reverse_iterator		rbegin() {return reverse_iterator(_vector + _size - 1);};
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(_vector + _size - 1);};
			
			reverse_iterator		rend() {return reverse_iterator(_vector - 1);};
			const_reverse_iterator	rend() const {return const_reverse_iterator(_vector - 1);};


//___________________________________________________________________________________________________________________



			//**********************************************//
			// Capacity functions                           //
			//**********************************************//
			
			//Functionnal memory part
			unsigned int			size() const   //Returns the number of elements in the vector.
			{
				return _size;
			};
			
			//Returns the maximum number of elements that the vector can hold.
			unsigned int			max_size() const   
			{
				return(_alloc.max_size());
			};
			
			//Function in case the memory allocated is not sufficient to add the new element, we need to reallocate.
			//First, we check if we are able to resize by checking max capacity.
			//If we want to resize smaller we just have to remove extra space.
			//Otherwise we need to insert it.
			//Resizes the container so that it contains alloc_size elements.
			void					resize(size_type alloc_size, value_type value)
			{
				while (alloc_size < _size)
					pop_back();
				while (alloc_size > _size)
					push_back(value);
			};
			
			
			//Returns the size of the storage space currently allocated 
			//for the vector, expressed in terms of elements.
			unsigned int			capacity()
			{
				return (_capacity);
			};
			
			
			 //Returns whether the vector is empty 
			bool					empty()
			{
				return (_size == 0);
			};
			
			
			//Requests that the vector capacity be 
			//at least enough to contain alloc_size elements.
			void					reserve(size_type alloc_size) 
			{
				if (alloc_size > _capacity)
				{

					pointer_type newvector = _alloc.allocate(alloc_size);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(&newvector[i], _vector[i]);
						_alloc.destroy(&_vector[i]);
					}
					_alloc.deallocate(_vector, _capacity = alloc_size);
					_vector = newvector;
					_capacity = alloc_size;
				}
			};

//_______________________________________________________________________________________________________________


			
			//**********************************************//
			// Element access                               //
			//**********************************************//
			reference			at(size_type pos)
			{
				if (pos >= _size)
					throw std::out_of_range("vector");
				return (_vector[pos]);
			};

			const_reference		at(size_type pos) const
			{
				if (pos >= _size)
					throw std::out_of_range("vector");
				return (_vector[pos]);
			};
			
			reference			operator[](size_type pos) 
			{
				return (_vector[pos]);
			};
			
			const_reference		operator[](size_type pos) const 
			{
				return (_vector[pos]);
			};

			reference			front() 
			{
				return (_vector[0]);
			};
			
			const_reference		front() const 
			{
				return (_vector[0]);
			};
			
			reference			back() 
			{
				return (_vector[_size - 1]);
			};
			
			const_reference		back() const 
			{
				return (_vector[_size - 1]);
			};
			
			
			//*****************************************//
			//Modifiers                                //
			//*****************************************//


			void push_back (const value_type& value)
			{
				if (_size == _capacity)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				_alloc.construct(&_vector[_size], value);
				_size++;
			};
			
			void pop_back()
			{
				--_size;
				_alloc.destroy(&_vector[_size]);
			};
			
			iterator insert (iterator position, const value_type& val)
			{
				size_type n_to_pos = position - this->begin();
				if (this->_size + 1 > this->_capacity)
				{
					if (this->_capacity == 0)
						reserve(1);
					else
						reserve(this->_capacity * 2);
				}
				this->_size++;
				for (size_type i = this->_size - 1; i > n_to_pos; i--)
				{
					this->_alloc.construct(&(this->_vector[i]), (this->_vector[i - 1]));
					this->_alloc.destroy(&(this->_vector[i - 1]));
				}
				this->_alloc.construct(&(this->_vector[n_to_pos]), (val));
				return (iterator(&this->_vector[n_to_pos]));
			};
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				if (this->_size + n > this->_capacity)
				{
					size_type	backup = position - this->begin();
					if (this->_capacity == 0)
						reserve(n);
					else
					{
						if (this->_size * 2 >= this->_size + n)
							reserve(this->_size * 2);
						else
							reserve(this->_size + n);
					}
					position = this->begin() + backup;
				}
				for (size_type i = 0; i < n; i++)
					position = insert(position, val);
				return;
			};
			
			// typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL
			template <class InputIterator>
			void insert(iterator position, InputIterator begin, InputIterator end, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_type n = 0;
				InputIterator temp = begin;
				while (temp != end)
				{
					temp++;
					n++;
				}
				if (this->_size + n > this->_capacity)
				{
					size_type	backup = position - this->begin();
					if (this->_capacity == 0)
						reserve(n);
					else
					{
						if (this->size * 2 >= this->_size + n)
							reserve(this->_size * 2);
						else
							reserve(this->_size + n);
					}
					position = this->begin() + backup;
				}
				for (; begin != end; ++begin, ++position)
					insert(position, *begin);
				return;
			};
			
			iterator erase (iterator position)
			{
				iterator tmp = position;
				while (tmp + 1 != end())
				{
					*tmp = *(position + 1);
					tmp++;
				}
				_size--;
				return (iterator(position));
			};
			
			iterator erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					last--;
				}
				return (iterator(first));
			};
			
			// void swap (vector& x)
			// {
				
			// }
			
			void clear()
			{
				erase(begin(), end());
			};
	};
	
	//*****************************************//
	//Operators                                //
	//*****************************************//
	
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
			if (lhs.size() != rhs.size())
					return false;
				return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs < rhs);
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs > rhs);
	}
		
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}	

#endif