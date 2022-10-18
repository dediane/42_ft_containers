/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:58:36 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/18 16:41:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include <iostream>
#include <map_iterator.hpp>

namespace ft
{
  template <typename T, typename K, class Compare, class Alloc>
  class RedBlackTree {
    
    private:
      typedef T     value_type;
      
      struct Node 
      {
        value_type    data;
        Node          *parent;
        Node          *left;
        Node          *right;
        bool          color;

        Node(value_type const &value) : data(value), left(NULL), right(NULL), parent(NULL) {}
      };

      typedef size_t                size_type;
      typedef K                     key_type;
      typedef Compare               compare_type;
      typedef Alloc                 allocator_type;
      typedef *value_type           pointer; 
      typedef *Node                 node_ptr;
      typedef const *Node           const_node_ptr;
      typedef const &value_type     const_reference;
      typedef typename allocator_type::template rebind<Node>::other node_allocator;

      node_pointer    _root;
      node_pointer    _end;
      size_type       _size;
      node_allocator  _node_alloc;
      compare_type    _comp;

      public:
        typedef typename ft::map_iterator<typename T, typename node_pointer>  iterator;
        
  };
};

#endif