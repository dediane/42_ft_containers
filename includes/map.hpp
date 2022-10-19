/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:59:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/19 18:56:48 by ddecourt         ###   ########.fr       */
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

	template <typename Data>
	struct node {
		Data data;
		node *left;
		node *right;
		node *parent;
		bool last;
		node(Data data, node *left, node *right, node *parent, bool last = false) : data(data), left(left), right(right), parent(parent), last(last) {}
		~node() {}
	};
	
	//https://cplusplus.com/reference/map/map/
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef ft::pair<key_type, mapped_type>								value_type;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::difference_type					difference_type;
	 		typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef map_iterator<value_type, node_type*>						iterator;
			typedef map_iterator<const value_type, node_type*>					const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			// typedef node<value_type>											node_type;
			// typedef typename allocator_type::template rebind<node_type>::other	node_allocator;
			
			class value_compare	//https://cplusplus.com/reference/map/map/value_comp/
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare (key_compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
			};

		protected:
			node_allocator	_alloc_type;
			key_compare 	_key_compare;
			size_type		_size_type;
			node_type		*_root;

		public:
		/***********************************/
		/*         Constructors            */
		/***********************************/

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc_type(alloc), _key_compare(comp), _size(0), _base(NULL){};

		template <class InputIterator>
		map (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc_type(alloc), _key_compare(comp), _size(0), _base(NULL)
		{insert(first, last);};

		map (const map& other) : _alloc_type(other._alloc_type), _key_compare(other._key_compare), _size(0), _root(NULL){*this = other;};

		~map()
		{
				
		}

		map& operator= (const map& other) : _alloc_type(other._alloc_type), _key_compare(other._key_compare), _size(0), _root(NULL)
		{*this = other;};


		/*************************************/
		/*          Element access           */
		/*************************************/

		T& at( const Key& key )
		{
			
		}

		const T& at( const Key& key ) const
		{
			
		}

		/*************************************/
		/*            Iterators              */
		/*************************************/

		iterator begin()
		{
			
		}
		
		const_iterator begin() const
		{
				
		}
			
		iterator end()
		{
			
		}
		
		const_iterator end() const
		{
				
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		
		const_reverse_iterator  rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		/*************************************/
		/*            Capacity               */
		/*************************************/

		bool empty() const
		{
			
		}

		size_type size() const
		{
			
		}

		size_type max_size() const
		{
			
		}

		/*************************************/
		/*            Modifiers              */
		/*************************************/

		void clear()
		{
			
		}

		std::pair<iterator, bool> insert( const value_type& value )
		{
			
		}

		iterator insert( iterator pos, const value_type& value )
		{
			
		}

		iterator erase( iterator pos )
		{
			
		}

		iterator erase( iterator first, iterator last )
		{
			
		}

		size_type erase( const Key& key )
		{
			
		}

		void swap( map& other )
		{
			
		}

		/*************************************/
		/*              Look Up              */
		/*************************************/

		size_type count( const Key& key ) const
		{
			
		}

		iterator find( const Key& key )
		{
			
		}

		const_iterator find( const Key& key ) const
		{
			
		}

		ft::pair<iterator,iterator> equal_range( const Key& key )
		{
			
		}

		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			
		}
		
		iterator lower_bound( const Key& key )
		{
			
		}

		const_iterator lower_bound( const Key& key ) const
		{
			
		}

		iterator upper_bound( const Key& key )
		{
			
		}

		const_iterator upper_bound( const Key& key ) const
		{
			
		}

		/*************************************/
		/*            Observers              */
		/*************************************/

		key_compare key_comp() const
		{
			
		}

		std::map::value_compare value_comp() const
		{
			
		}
	};
 }
#endif