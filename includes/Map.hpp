/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:59:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/09/02 13:45:08 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "utils/pair.hpp"
#include "random_access_iterator.hpp"
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
			typedef Alloc									allocator_type;
			typedef T&										reference;
			typedef const T&								const_reference;
			typedef T*										pointer;
			typedef const T*								const_pointer;
	};
}
#endif