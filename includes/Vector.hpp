/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:05:51 by ddecourt          #+#    #+#             */
/*   Updated: 2022/09/02 02:50:29 by ddecourt         ###   ########.fr       */
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


// namespace ft
// {
// 	template <class T, bool B> class random_access_iterator;
// 	template <class T, bool B> class reverse_iterator;
// }

//https://cplusplus.com/reference/vector/vector/
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
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
			Alloc		_alloc;
			pointer		_vector;
			size_type	_size;
			size_type	_capacity;
			
		
		public:
		//**********************************************//
		// Constructors and destructors                 //
		//**********************************************//
		
			// vector();
			// ~vector();
			// vector &operator=(const vector &rhs);
			
			explicit vector(const allocator_type &allocator = allocator_type()) : 
			_alloc(allocator), _vector(0), _size(0), _capacity(0)
			{
				_vector = _alloc.allocate(0);
			};
			
			template <class InputIterator>
			vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type())
			:  _alloc(allocator), _vector(0), _size(0), _capacity(0)
			{
				_vector = _alloc.allocate(0);
				assign(begin, end);
			};
			
			vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type())
			: _alloc(allocator), _vector(0), _size(0), _capacity(0)
			{
				_vector = _alloc.allocate(0);
				assign(n, value);
			};
			
			vector(const vector &other)
			:  _alloc(other._allocator), _vector(0), _size(0), _capacity(0)
			{
				*this = other;
			};
			
			~vector(void)
			{
				_alloc.deallocate(_alloc, _capacity);
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
			
			// reverse_iterator		rbegin() {return reverse_iterator(end());};
			// const_reverse_iterator	rbegin() const {return const_reverse_iterator(end());};
			
			// reverse_iterator		rend() {return reverse_iterator(begin());};
			// const_reverse_iterator	rend() const {return const_reverse_iterator(begin());};
			
			

			//**********************************************//
			// Capacity functions                           //
			//**********************************************//
			
			//Functionnal memory part
			unsigned int			size() const 
			{
				return _size;
			};
			
			//Max size stack overflow answer
			//https://stackoverflow.com/questions/3813124/c-vector-max-size#:~:text=max_size()%20is%20the%20theoretical,or%202%5E29%20double%20values.
			unsigned int			max_size() const 
			{
				if (sizeof(value_type) == 1)
					return (pow(2.0, 64.0) / 2.0) - 1;
				return (pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1;
			};
			
			//Function in case the memory allocated is not sufficient to add the new element, we need to reallocate.
			//First, we check if we are able to resize by checking max capacity.
			//If we want to resize smaller we just have to remove extra space.
			//Otherwise we need to insert it.
			void					resize(size_type alloc_size, value_type value)
			{
				while (alloc_size < _size)
					pop_back();
				while (alloc_size > _size)
					push_back(value);
			};
			
			unsigned int			capacity()
			{
				return (_capacity);
			};
			
			
			bool					empty()
			{
				return (_size == 0);
			};
			
			
			void					reserve(size_type alloc_size)
			{
				if (alloc_size > max_size())
					throw std::length_error("vector::reserve");
				if (alloc_size > _capacity)
				{
					size_type i = -1;
					pointer tmp;
					
					tmp = _alloc.allocate(alloc_size);
					_capacity = alloc_size;
					while (++i < _size)
					{
						tmp[i] = _alloc[i];
					}
					_alloc.deallocate(_alloc, _size);
					_alloc = tmp;
				}
			};

			
			//**********************************************//
			// Element access                               //
			//**********************************************//
			reference			operator[](size_type pos) 
			{
				return (_vector[pos]);
			};
			
			const_reference		operator[](size_type pos) const 
			{
				return (_vector[pos]);
			};

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
			
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			};

			void assign(size_type n, const value_type &value)
			{
				clear();
				insert(begin(), n, value);
			};
			
			void push_back (const value_type& val)
			{
				if (_size + 1 > _capacity)
					reserve(_size + 1);
				_vector[_size++] = val;
			};
			
			void pop_back()
			{
				if (_size())
					_size--;
			};
			
			iterator insert (iterator position, const value_type& val)
			{
				size_type i = 0;
				iterator j = begin();
				while (j + i != position && i < _size)
					i++;
				if (_capacity < _size + 1)
					reserve(_size + 1);
				size_type k = _capacity - 1;
				while (k > i)
				{
					_vector[k] = _vector[k - 1];
					k--;
				}
				_vector[i] = val;
				_size++;
				return (iterator (&_vector[i]));
			};
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				while (n--)
					position = insert(position, val);
			};
			
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first + 1);
					first++;
				}
			};
			
			iterator erase (iterator position)
			{
				iterator cursor = position;
				while (cursor + 1 != end())
				{
					*cursor = *(cursor + 1);
					cursor++;
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
}

#endif