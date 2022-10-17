/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:59:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/17 17:42:55 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "utils/pair.hpp"
#include "random_access_iterator.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils/equal.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"

namespace ft {
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
	{
		public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef ft::pair<key_type, mapped_type>								value_type;
			typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			typedef size_t														size_type;
			typedef ptrdiff_t													difference_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::red_black_tree<value_type, key_type, key_compare, allocator_type> tree_type;
			typedef tree_type::iterator											iterator;
			typedef tree_type::const_iterator									const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			
			class value_compare								//https://cplusplus.com/reference/map/map/value_comp/
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare (key_compare c) : comp(c) {}
				public:
					bool operator() (const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
			};

		protected:
		 	node_allocator _alloc_type;
			key_compare _key_compare;
			size_type _size_type;
			node_type *_base;

		public:
			/***********************************/
			/*         Constructors            */
			/***********************************/

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc_type(alloc), _key_compare(comp), _size(0), _base(NULL){};

			template <class InputIterator>
			map (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc_type(alloc), _key_compare(comp), _size(0), _base(NULL)
			{insert(first, last);};

			map (const map& x) : _alloc_type(x._alloc_type), _key_compare(x._key_compare), _size(0), _root(NULL){*this = x;};

			~map()
			{
				
			}

			map& operator= (const map& x)
			{
				
			}

			/*************************************/
			/*            Iterators              */
			/*************************************/

			iterator begin();const_iterator begin() const
			{
				
			}
			
			iterator end();const_iterator end() const
			{
				
			}
			 
	};
}
#endif