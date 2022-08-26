/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:05:51 by ddecourt          #+#    #+#             */
/*   Updated: 2022/08/26 03:42:52 by ddecourt         ###   ########.fr       */
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

#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"
#include "iterator_traits.hpp"


namespace ft
{
	template <class T, bool B> class random_access_iterator;
	template <class T, bool B> class reverse_iterator;
}

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
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
			
			typedef ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type				size_type;
			
		private:
			Alloc		_alloc;
			pointer		_vector;
			size_type	_size;
			size_type	_capacity:
		
		public:
			Vector();
			~Vector();
			Vector &operator=(const Vector &rhs);
			
			//Iterators functions
			iterator				begin() {return iterator(_vector);};
			const_iterator			begin() {return const_iterator(_vector);};
			
			iterator				end() {return iterator(_vector + _size);};
			const_iterator			end() {return const_iterator(_vector + _size);};
			
			reverse_iterator		rbegin() {return reverse_iterator(_vector + _size - 1);};
			const_reverse_iterator	rbegin() {return const_reverse_iterator(_vector + _size - 1);};
			
			reverse_iterator		rend() {return reverse_iterator(_vector - 1);};
			const_reverse_iterator	rend() {return const_reverse_iterator(_vector - 1);};
			
			
			
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
				if (alloc_size > max_size())
					throw (std::length_error("vector::resize"));
				else if (alloc_size < this.size())
				(
					while (this.size() > alloc_size)
					{
						_end--;
						_alloc.destroy(_end);
					}
				)
				else
				{
					this->insert(this->_end(), alloc_size - this->size(), value);
				}
			};
			
			unsigned int			capacity()
			{
				return (_capacity);
			};
			
			
			bool					empty()
			{
				return (_size == 0);
			};
			
			
			void					reserve(size_type alloc_size);
			{
				if (alloc_size > max_size())
					throw std::length_error("vector::reserve");
				if (alloc_size > _capacity)
				{
					pointer old_start = _start;
					pointer old_end = _end;
					size_type old_size_type = _size;
					size_type old_capacity = _capacity;
				}
            }

			
			reference			operator[](unsigned int size);
			const_reference		operator[](unsigned int size) const;
			
			reference			at();
			const_reference		at() const;
			reference			front();
			const_reference		front() const;
			reference			end();
			const_reference		end() const;
			value_type*			data();
			const value_type*	data();
			
	};
}

#endif