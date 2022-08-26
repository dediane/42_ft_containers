/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:05:51 by ddecourt          #+#    #+#             */
/*   Updated: 2022/08/26 02:56:50 by ddecourt         ###   ########.fr       */
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
			//first template parameter (T)
			typedef T											value_type;
			//second template parameter (Alloc)
			typedef Alloc										allocator_type;
			
			//reference & pointer
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			
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
			
			reverse_iterator		rbegin() {return reverse_iterator(_vector + _size - 1)};
			const_reverse_iterator	rbegin() {return const_reverse_iterator(_vector + _size - 1)};
			
			reverse_iterator		rend();
			const_reverse_iterator	rend();
			
			unsigned int			size() const;
			unsigned int			max_size() const;
			void					resize();
			unsigned int			capacity();
			bool					empty();
			void					reserve();
			
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