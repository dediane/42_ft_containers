/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:05:51 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/27 17:15:12 by ddecourt         ###   ########.fr       */
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
#include "utils/lexicographical_compare.hpp"
#include "utils/equal.hpp"
//#include "utils/swap.hpp"

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
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename std::size_t							size_type;
			
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
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_vector[i], value);
			};
			
			//Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			//,
			template <class InputIterator>
			// typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL:
			vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type()) :
			_alloc(allocator), _vector(0), _size(0), _capacity(0)
			{
				_vector = _alloc.allocate(0);
				assign(begin, end);
			};
			
			//Constructs a container with a copy of each of the elements in x, in the same order.
			vector(const vector &rhs)
			:  _alloc(rhs._alloc), _vector(NULL), _size(rhs._size), _capacity(rhs._size)
			{
				if(rhs._vector)
				{
					_vector = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size ; i++)
						_alloc.construct(&_vector[i], rhs._vector[i]);
				}
			};
			
			~vector(void)
			{
					clear();
					if (_vector)
						_alloc.deallocate(_vector, _capacity);
			};

			allocator_type get_allocator() const
			{
				return _alloc;
			}
			
			vector &operator=(const vector &other)
			{
				if (*this == other)
					return (*this);
				assign(other.begin(), other.end());
				return (*this);
			};
		
			template <class InputIterator>
			typename ft::enable_if<!is_integral<InputIterator>::value, void>::type
			assign(InputIterator first, InputIterator last)

			{
				size_type n = 0;
				InputIterator temp = first;
				while (temp != last)
				{
					n++;
					temp++;
				}
				this->clear();
				if(_size * 2 > n)
					reserve(_size * 2);
				else
					reserve(n);
						
				for (; first != last; ++first)
				{
					this->_alloc.construct(&this->_vector[_size], *first);
					this->_size++;
				}
				return ;
			};
			
			void assign(size_type n, const value_type& value)
			{
				if (n > _capacity) 
				{
					if(_size * 2 > n)
						reserve(_size * 2);
					else
						reserve(n);
				}
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				for (size_type i = 0; i < n ; i++)
					_alloc.construct(&_vector[i], value);
				_size = n;
			};



//___________________________________________________________________________________________________________________



		//**********************************************//
		// Iterators functions                          //
		//**********************************************//
			iterator				begin() {return iterator(_vector);};
			const_iterator			begin() const {return const_iterator(_vector);};
			
			iterator				end() {return iterator(_vector + size());};
			const_iterator			end() const {return const_iterator(_vector + size());};
			
			reverse_iterator		rbegin() {return reverse_iterator(end());};
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(end());};
			
			reverse_iterator		rend() {return reverse_iterator(begin());};
			const_reverse_iterator	rend() const {return const_reverse_iterator(begin());};


//___________________________________________________________________________________________________________________



			//**********************************************//
			// Capacity functions                           //
			//**********************************************//
			
			//Functionnal memory part
			size_type	size() const   //Returns the number of elements in the vector.
			{
				return _size;
			};
			
			//Returns the maximum number of elements that the vector can hold.
			size_type	max_size() const   
			{
				return(_alloc.max_size());
			};
			
			//Function in case the memory allocated is not sufficient to add the new element, we need to reallocate.
			//First, we check if we are able to resize by checking max capacity.
			//If we want to resize smaller we just have to remove extra space.
			//Otherwise we need to insert it.
			//Resizes the container so that it contains alloc_size elements.
			void					resize(size_type alloc_size, value_type value = value_type())
			{

				if (alloc_size > max_size())
					throw(std::length_error("vector::resize"));

				if(_size >= alloc_size) 
				{
					while(_size > alloc_size)
					{
						_alloc.destroy(&_vector[_size - 1]);
						_size--;
					}
				}
				else
				{
					if (alloc_size > _size * 2)
						reserve(alloc_size);
					else
						reserve(_size * 2);
					while (_size < alloc_size)
					{
						_alloc.construct(_vector + _size, value);
						_size++;
					}
				}

				
				// while (alloc_size < _size)
				// 	pop_back();
				// while (alloc_size > _size)
				// 	push_back(value);
				// // _capacity = alloc_size;
			};
			
			
			//Returns the size of the storage space currently allocated 
			//for the vector, expressed in terms of elements.
			size_type			capacity() const
			{
				return (_capacity);
			};
			
			
			 //Returns whether the vector is empty 
			bool					empty() const
			{
				return (_size == 0);
			};
			
			
			//Requests that the vector capacity be 
			//at least enough to contain alloc_size elements.
			void					reserve(size_type alloc_size) 
			{		
				if (alloc_size > max_size()) {
					throw std::length_error("vector::reserve");
				}
				
				if (alloc_size > _capacity)
				{
					size_type saved = _capacity;
					pointer_type newvector = _alloc.allocate(alloc_size);
					_capacity = alloc_size;
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(&newvector[i], _vector[i]);
						_alloc.destroy(&_vector[i]);
					}
					if (_vector)
						_alloc.deallocate(_vector, saved);
					_vector = newvector;
				}
			};

//_______________________________________________________________________________________________________________
			
			//**********************************************//
			// Element access                               //
			//**********************************************//
			reference			at(size_type pos)
			{
				if (pos >= this->_size)
					throw std::out_of_range("out of range");
				return (_vector[pos]);
			};

			const_reference		at(size_type pos) const
			{
				if (pos >= this->_size)
					throw std::out_of_range("out of range");
				return (_vector[pos]);
			};
			
			reference			operator[](size_type pos) 
			{
				if (pos >= this->_size)
					throw std::out_of_range("out of range");
				return (_vector[pos]);
			};
			
			const_reference		operator[](size_type pos) const 
			{
				if (pos >= this->_size)
					throw std::out_of_range("out of range");
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
				if(_size + 1 > _capacity)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_size * 2);
				}
				_alloc.construct(&_vector[_size], value);
				_size++;
			};
			
			void pop_back()
			{
				--_size;
				_alloc.destroy(&_vector[_size]);
			};
			
			iterator insert(iterator position, const value_type& val)
			{
				size_type n_to_pos = position - begin();
				if (_size + 1 > _capacity)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_size * 2);
				}
				_size++;
				for (size_type i = _size - 1; i > n_to_pos; i--)
				{
					_alloc.construct(&(_vector[i]), (_vector[i - 1]));
					_alloc.destroy(&(_vector[i - 1]));
				}
				_alloc.construct(&(_vector[n_to_pos]), (val));
				return (iterator(&_vector[n_to_pos]));
			};
			
			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type	backup = position - this->begin();
				if (this->_size + n > this->_capacity)
				{
					if (this->_capacity == 0)
						reserve(n);
					else
					{
						// if (this->_size * 2 >= this->_size + n)
						if(_size + n < _size * 2) 
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
			
			template <class InputIterator>
			void insert(iterator position, InputIterator begin, InputIterator end, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
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
						if (this->_size * 2 >= this->_size + n)
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
					*tmp = *(tmp + 1);
					_alloc.destroy(tmp.get_ptr());
					_alloc.construct(tmp.get_ptr(), *(tmp + 1));
					tmp++;
				}
				_alloc.destroy(tmp.get_ptr());
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
			
			void swap (vector& a)
			{	
				pointer_type x_vector = _vector;
				size_type	 x_capacity = _capacity;
				size_type	 x_size = _size;
				allocator_type x_alloc = _alloc;
				_vector = a._vector;
				_capacity = a._capacity;
				_size = a._size;
				_alloc = a._alloc;
				a._vector = x_vector;
				a._capacity = x_capacity;
				a._size = x_size;
				a._alloc = x_alloc;
			}
			
			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				_size = 0;
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
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end() );
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs) && lhs != rhs;
	}
		
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
}	

#endif