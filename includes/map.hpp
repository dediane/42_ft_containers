/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:59:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/15 15:31:47 by ddecourt         ###   ########.fr       */
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

	template <typename V>
	struct node {
		V value;
		node *left;
		node *right;
		node *parent;
		bool last;
		node(V value, node *left, node *right, node *parent, bool last = false) : value(value), left(left), right(right), parent(parent), last(last) {}
		~node() {}
	};
	
	//https://cplusplus.com/reference/map/map/
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<key_type, mapped_type>			value_type;
			typedef Compare									key_compare;
			typedef node<value_type>						node_type;
			class value_compare								//https://cplusplus.com/reference/map/map/value_comp/
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
			};
			typedef Alloc														allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::difference_type					difference_type;
			typedef map_iterator<value_type, node_type*>						iterator;
			typedef map_iterator<const value_type, node_type*>					const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		// protected:
		// 	node_allocator
	};
}
#endif