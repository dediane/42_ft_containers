/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:59:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/27 20:01:22 by ddecourt         ###   ########.fr       */
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
#include "utils/lexicographical_compare.hpp"
#include "red_black_tree.hpp"

namespace ft {

	//https://cplusplus.com/reference/map/map/
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key																				key_type;
			typedef T																				mapped_type;
			typedef ft::pair<key_type, mapped_type>													value_type;
	 		typedef Compare																			key_compare;
			typedef Alloc																			allocator_type;
			typedef typename allocator_type::size_type												size_type;
			typedef typename allocator_type::difference_type										difference_type;
			typedef typename allocator_type::reference												reference;
			typedef typename allocator_type::const_reference										const_reference;
			typedef typename allocator_type::pointer												pointer;
			typedef typename allocator_type::const_pointer											const_pointer;
			typedef typename ft::RedBlackTree<value_type, key_type, key_compare, allocator_type>	tree_type;
			typedef typename tree_type::iterator													iterator;
			typedef typename tree_type::const_iterator												const_iterator;
			typedef ft::reverse_iterator<iterator>													reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>											const_reverse_iterator;

			
			class value_compare//https://cplusplus.com/reference/map/map/value_comp/
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare (key_compare c) : comp(c) {}
				public:
					bool operator() (const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
			};

		protected:
			tree_type	_tree;

		public:
		/***********************************/
		/*         Constructors            */
		/***********************************/

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			static_cast<void>(comp);
			static_cast<void>(alloc);
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			static_cast<void>(comp);
			static_cast<void>(alloc);
			insert(first, last);
		}

		map (const map& other)
		{
			insert(other.begin(), other.end());
		}
		
		~map(){}

		map& operator= (const map& other)
		{		
				clear();
				insert(other.begin(), other.end());
			return *this;
		}

		/*************************************/
		/*            Iterators              */
		/*************************************/

		iterator begin()
		{
			return _tree.begin();
		}
		
		const_iterator begin() const
		{
			return _tree.begin();
		}
			
		iterator end()
		{
			return _tree.end();
		}
		
		const_iterator end() const
		{
			return _tree.end();
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(_tree.end());
		}
		
		const_reverse_iterator  rbegin() const
		{
			return const_reverse_iterator(_tree.end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_tree.begin());
		}
		
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(_tree.begin());
		}

		/*************************************/
		/*            Capacity               */
		/*************************************/

		bool empty() const
		{
			return _tree.empty();
		}

		size_type size() const
		{
			return _tree.size();
		}

		size_type max_size() const
		{
			return _tree.max_size();
		}

		mapped_type& operator[](const key_type& key)
		{
			return (insert(ft::make_pair(key, mapped_type())).first)->second;
		}

		mapped_type& at(const key_type& key)
		{
			return (_tree.at(ft::make_pair(key, mapped_type())).first)->second;
		}

		const mapped_type& at(const key_type& key) const
		{
			return (_tree.at(ft::make_pair(key, mapped_type())).first)->second;

		}

		/*************************************/
		/*            Modifiers              */
		/*************************************/

		void clear()
		{
			if (size())
				_tree.clearAll();
		}

		ft::pair<iterator, bool> insert( const_reference value )
		{
			return _tree.insert(value);
		}

		iterator insert( iterator pos, const value_type& value )
		{
			(void)pos;
			return _tree.insert(value).first;
		}

		template< class InputIterator >
		void insert(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			for (;first != last; first++)
			{
				_tree.insert(*first);				
			}
		}

		void erase( iterator pos )
		{
			erase(pos->first);
		}

		void erase( iterator first, iterator last )
		{
			_tree.range_erase(first, last);
		}

		size_type erase( const Key& key )
		{
			return (_tree.erase_node(ft::make_pair(key, mapped_type())));
		}

		void swap( map& other )
		{
			_tree.swap_tree(other._tree);
		}

		/*************************************/
		/*              Look Up              */
		/*************************************/

		size_type count( const Key& key ) const
		{
			return (_tree.count(ft::make_pair(key, mapped_type())));
		}

		iterator find( const Key& key )
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		const_iterator find( const Key& key ) const
		{	
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		ft::pair<iterator,iterator> equal_range( const Key& key )
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}
		
		iterator lower_bound( const Key& key )
		{
			return (_tree.lower_bound(ft::make_pair(key, mapped_type())));
		}

		const_iterator lower_bound( const Key& key ) const
		{
			return (_tree.lower_bound(ft::make_pair(key, mapped_type())));
		}

		iterator upper_bound( const Key& key )
		{
			return (_tree.upper_bound(ft::make_pair(key, mapped_type())));
		}

		const_iterator upper_bound( const Key& key ) const
		{
			return (_tree.upper_bound(ft::make_pair(key, mapped_type())));
		}

		allocator_type get_allocator() const
		{
				return allocator_type();
		}


		/*************************************/
		/*            Observers              */
		/*************************************/

		key_compare key_comp() const
		{
			return key_compare();
		}

		value_compare value_comp() const
		{
			return value_compare(_tree.comp());
		}
	};

	/*************************************/
	/*       Non-member functions        */
	/*************************************/

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		typename map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
		
		if (lhs.size() != rhs.size())
			return false;
		while (it != lhs.end())
		{
			if (*it != *it2)
				return false;
			it++;
			it2++;
		}
		return true;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end() );
	}

	template< class Key, class T, class Compare, class Alloc > 
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs > rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs) && lhs != rhs;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs.swap(rhs));
	}
 }
#endif