/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:10:36 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/26 21:52:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "map.hpp"

namespace ft{

	template<typename T, typename node, class Compare>
	class map_iterator
	{
		public:
			typedef T								value_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef const value_type*				const_pointer;
			typedef const value_type& 				const_reference;
			typedef node							node_pointer;

		protected:
			node_pointer _node;

		public:
		//constructors
			map_iterator() : _node(NULL) {}
			map_iterator(node_pointer ptr) : _node(ptr) {}
			map_iterator(map_iterator const & src) : _node(src._node) {}
			map_iterator & operator=(map_iterator const & rhs) 
			{
				if (this == &rhs)
					return (*this);
				_node = rhs._node; 
				return *this;
			}

			operator map_iterator<const T, node, Compare>() const {return map_iterator<const T, node, Compare>(_node);}
		//destructor
			~map_iterator() {}
			

			map_iterator& operator++ (void) {
				if (_node && _node->right)
				{
					_node = _node->right;
					while (_node->left)
						_node = _node->left;
				}
				else if (_node && _node->parent)
				{
					node_pointer save = _node;
					node_pointer tmp = _node->parent;
					while (tmp && _node == tmp->right)
					{
						if (tmp->parent == NULL)
						{
							_node = save->parent;
							return *this;
						}
						_node = tmp;
						tmp = tmp->parent;
					}
					_node = tmp;
				}
				return *this;
			}
			map_iterator operator++ (int) 
			{
				map_iterator it(*this);
				operator++();
				return it;
			}
			map_iterator& operator-- (void) {decrease(); return *this;}
			map_iterator operator-- (int) {map_iterator it = *this; --(*this); return it;}

			reference operator*() const {return _node->data;}
			pointer operator->() const {return &_node->data;}

			node_pointer get_node() {return _node;}
			node_pointer get_node() const {return _node;}

			template<typename it2>
			bool operator==(const map_iterator<it2, node, Compare>& b) const {return _node == b.get_node();}
			template<typename it2>
			bool operator!=(const map_iterator<it2, node, Compare>& b) const {return _node != b.get_node();}

		private:
			void increase() 
			{
				if (_node && _node->right)
				{
					_node = _node->right;
					while (_node->left && _node->left != NULL)
						_node = _node->left;
				}
				else if (_node && _node->parent)
				{
					node_pointer temp = _node;
					node_pointer tmp_parent = _node->parent;
					while ( tmp_parent && _node == tmp_parent->right) 
					{
						if (_node->parent == NULL) 
						{
							_node = temp->parent;
							return ;
						}
						_node = tmp_parent;
						tmp_parent = tmp_parent->parent;
					}
					_node = tmp_parent;
				}
			}

			void decrease() 
			{
				if (_node && _node->left)
				{
					_node = _node->left;
					while (_node->right && _node->right != NULL)
						_node = _node->right;
				}
				else if (_node && _node->parent)
				{
					node_pointer temp = _node;
					node_pointer tmp_parent = _node->parent;
					while ( tmp_parent && _node == tmp_parent->left) 
					{
						if (_node->parent == NULL) 
						{
							_node = temp;
							break;
						}
						_node = tmp_parent;
						tmp_parent = tmp_parent->parent;
					}
					_node = tmp_parent;
				}
			}

	};

}

#endif
