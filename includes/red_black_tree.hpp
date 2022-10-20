/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:58:36 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/20 18:11:37 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include <iostream>
#include <map_iterator.hpp>



namespace ft
{
	template <typename T, typename K, class Compare, class Alloc>
	class RedBlackTree 
	{
		private:
			typedef T value_type;

			
			struct Node 
			{
			  value_type		data;
			  bool				color; //  black = 0  | red = 1
			  Node				*left;
			  Node				*right;
			  Node				*parent;

			  //constructor for each node
			  Node(value type const &data = value_type()) : data(data), left(NULL), right(NULL), parent(NULL){}
			};
  
			typedef size_t				size_type;
			typedef K					key_type;
			typedef Compare				compare_type;
			typedef Alloc				allocator_type;
			typedef value_type*			pointer;
			typedef Node*				node_pointer;
			typedef const Node*			const_node_pointer;
			typedef &value_type			reference;
			typedef const &value_type	const_reference;
			typedef typename allocator_type::template rebind<Node>::other node_allocator;

			node_pointer	_root;
			node_pointer	_end;
			size_type		_size;
			node_allocator	_node_alloc;
			compare_type	_comp;

		public:

			typedef typename ft::map_iterator<value_type, node_pointer>				iterator;
			typedef typename ft::map_iterator<const value_type, node_pointer>		const_iterator;
		  
		  
			red_black_tree(const compare_type& comp = compare_type(), const node_allocator& node_alloc = node_allocator())
			{
				_node_alloc = node_alloc;
				_end = create_node();
				_root = _end();
				_size = 0;
				_comp = comp;
			}
		
			~red_black_tree()
			{
				if (_size)
					clear();
				_destroy_node(_root);
			}

			node_pointer	create_node(const_reference value = value_type())
			{
				node_pointer node = _node_alloc.allocate(1);

				_node_alloc.construct(node, Node(value));
				node->color = 1; //black
				node->left = NULL;
				node->right = NULL;
				node->parent = NULL;
				return node;
			}

			bool	empty() const
			{
				return _size == 0;
			}

			size_type	size() const
			{
				return _size;
			}

			size_type	max_size() const
			{
				return _node_alloc.max_size();
			}

			iterator	begin()
			{
				return iterator(_min_node());
			}

			const_iterator	begin() const
			{
				return const_iterator(_min_node());
			}

			iterator	end()
			{
				return iterator(_end());
			}

			const_iterator	end() const
			{
				return const_iterator(_end());
			}

			compare_type	comp() const
			{
				return _comp;
			}

			/*************************************************/
			/*                  Operations                   */
			/*************************************************/

			iterator	find(const_reference value)
			{
				node_pointer pos = tree_search_helper(value);
				if (!pos)
					return (end());
				return iterator(pos);
			}

			const_iterator	find(const_reference value)
			{
				node_pointer pos = tree_search_helper(value);
				if (!pos)
					return (end());
				return const_iterator(pos);
			}

			size_type	count(const_reference value) const
			{
				node_pointer pos = tree_search_helper(value);
				if(!ret)
					return 0;
				return 1;
			}

			iterator lower_bound(const_reference value)
			{
				iterator it = begin();
				iterator ite = end();
				
				for (; it != ite; it++)
				{
					if (!(_comp(it->first, value->first)))
						return it;
				}
				return it;
			}

			const_iterator lower_bound(const_reference value) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				
				for (; it != ite; it++)
				{
					if (!(_comp(it->first, value->first)))
						return it;
				}
				return it;
			}

			iterator upper_bound(const_reference value)
			{
				iterator it = begin();
				iterator ite = end();
				
				for (; it != ite; it++)
				{
					if (!(_comp(value->first, it->first)))
						return it;
				}
				return it;
			}

			const_iterator upper_bound(const_reference value) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				
				for (; it != ite; it++)
				{
					if (!(_comp(value->first, it->first)))
						return it;
				}
				return it;
			}
			
			/*************************************************/
			/*                  Modifiers                    */
			/*************************************************/
			
			ft::pair<Iterator, bool>	insert(const_reference value)
			{
				node_pointer node = create_node(value);
				node_pointer tmp = _root;
				node_pointer parent = NULL;

				if (empty())
					return (insert_node(node));
				while (tmp != NULL && tmp != _end)
				{
					parent = tmp;
					if (comp(value.first, tmp->data.first))
					{
						tmp = tmp->left;
					}
					else if (comp(tmp->data.first, val.first))
					{
						tmp = tmp->right;
					}
					else
					{
						destroy_node(node);
						update_end();
						return (ft::make_pair(iteraator(tmp), false));
					}
				}

				node->parent = parent;
				if (parent != NULL && parent!= _end)
				{
					root = node;
				}
				else if (comp(val.first, parent->data.first))
				{
					parent->left = node;
				}
				else
				{
					parent->right = node;
				}

				if(node->parent == NULL)
				{
					node->color = 0;
					return;
				}

				if (node->parent->parent == NULL)
				{
					return;
				}
				node_insert_fix(node);
				update_end();
				_size++;
				return (ft::make_pair(iterator(node), true));
			}

			
			



			/*************************************************/
			/*                    Helpers                    */
			/*************************************************/


			//function to find in the tree
			node_pointer	tree_search_helper(const_reference _to_find) const
			{
				node_pointer tmp = _root;

				while (tmp != NULL && tmp != _end)
				{
					if (comp(tmp->data.first, to_find.first))
						tmp = tmp->right;
					else if (comp(to_find.first, tmp->data.first))
						tmp = tmp->left;
					else
						return tmp;
				}
				return NULL;
			}

			//insert empty node
			ft::pair<iterator, bool>	insert_node(node_pointer node)
			{
				_root = node;
				_root->left = NULL;
				_root->right = _end;
				_end->parent = _root;
				_root->color = 0; //black
				_size++;
				return ft::make_pair(iterator(_root), true);
			}

			// For balancing the tree after insertion
			void	node_insert_fix(node_pointer node)
			{
				node_pointer tmp;
				
				while (node->parent && node->parent->color == 1)
				{
					if (node->parent->parent->right == node->parent)
					{
						tmp = node->parent->parent->left;
						if (tmp->color == 1)
						{
							tmp->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								rotateRight(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							rotateLeft(node->parent->parent);
						}
					}
					else
					{
						tmp = node->parent->parent->right;
						if (tmp->color == 1)
						{
							tmp->color = 0;
							node->parent->color = 0;
							node->parent->parent->color = 1;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								rotateLeft(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = 1;
							rotateRight(node->parent->parent);
						}
					}
					// if ( node == root)
					// {
					// 	break;
					// }
				}
				root->color = 0;
			}




		node_pointer minimum(node_pointer node) 
		{
			node_pointer tmp = node;
			while (node->left != NULL && node->left != _end) 
			{
				tmp = node->left;
			}
			return tmp;
		}

		node_pointer maximum(node_pointer node) 
		{
			node_pointer tmp = node;
			while (node->right != NULL && node->right != _end) 
			{
				tmp = node->right;
			}
			return tmp;
		}


		void destroy_node(node_pointer node)
		{
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}


		void update_end()
		{
			node_pointer max = maximum();
			max->right = _end;
			_end->parent = max;
			_end->right = NULL;
			_end->color = 0;
		}


			void rotateLeft(node_pointer node) 
			{
				node_pointer parent = node->right;
				node->right = parent->left;
				if (parent->left != end()) 
				{
					parent->left->parent = node;
				}
				parent->parent = node->parent;
				if (node->parent == 0) 
				{
					this->root = parent;
				} 
				else if (node == node->parent->left) 
				{
					node->parent->left = parent;
				} 
				else 
				{
					node->parent->right = parent;
				}
				parent->left = node;
				node->parent = parent;
			}

			void rotateRight(node_pointer node) 
			{
				node_pointer parent = node->left;
				node->left = parent->right;
				if (parent->right != end()) 
				{
					parent->right->parent = node;
				}
				parent->parent = node->parent;
				if (node->parent == 0) 
				{
					this->root = parent;
				} 
				else if (node == node->parent->right) 
				{
					node->parent->right = parent;
				} 
				else 
				{
					node->parent->left = parent;
				}
				parent->right = node;
				node->parent = parent;
			}


			node_pointer successor(node_pointer node) 
			{
				if (node->right != NULL && node->right != _end) 
				{
					return minimum(node->right);
				}
				node_pointer child = node->parent;
				while (child != NULL && child != _end && node == child->right) 
				{
					node = child;
					child = child->parent;
				}
				return child;
			}

			node_pointer predecessor(node_pointer node) 
			{
				if (node->left != NULL && node->left != _end) 
				{
					return maximum(node->left);
				}

				node_pointer child = node->parent;
				while (child != NULL && child != _end && node == child->left) 
				{
					node = child;
					child = child->parent;
				}

				return child;
			}

			

			
		  


		  // Preorder
		  void preOrderHelper(NodePtr node) {
			if (node != TNULL) {
			  std::cout << node->data << " ";
			  preOrderHelper(node->left);
			  preOrderHelper(node->right);
			}
		  }

		  // Inorder
		  void inOrderHelper(NodePtr node) {
			if (node != TNULL) {
			  inOrderHelper(node->left);
			  std::cout << node->data << " ";
			  inOrderHelper(node->right);
			}
		  }

		  // Post order
		  void postOrderHelper(NodePtr node) {
			if (node != TNULL) {
			  postOrderHelper(node->left);
			  postOrderHelper(node->right);
			  std::cout << node->data << " ";
			}
		  }

		  NodePtr searchTreeHelper(NodePtr node, int key) {
			if (node == TNULL || key == node->data) {
			  return node;
			}

			if (key < node->data) {
			  return searchTreeHelper(node->left, key);
			}
			return searchTreeHelper(node->right, key);
		  }

		  // For balancing the tree after deletion
		  void deleteFix(NodePtr x) {
			NodePtr s;
			while (x != root && x->color == 0) {
			  if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == 1) {
				  s->color = 0;
				  x->parent->color = 1;
				  leftRotate(x->parent);
				  s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0) {
				  s->color = 1;
				  x = x->parent;
				} else {
				  if (s->right->color == 0) {
					s->left->color = 0;
					s->color = 1;
					rightRotate(s);
					s = x->parent->right;
				  }

				  s->color = x->parent->color;
				  x->parent->color = 0;
				  s->right->color = 0;
				  leftRotate(x->parent);
				  x = root;
				}
			  } else {
				s = x->parent->left;
				if (s->color == 1) { void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1); void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1); void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1); void clear() 
	  {
		if (_size == 0)
		  return ; void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1); void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else {  void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1); void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1); void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
				  s->color = 0;
				  x->parent->color = 1;
				  rightRotate(x->parent);
				  s = x->parent->left;
				} void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}

				if (s->right->color == 0 && s->right->color == 0) {
				  s->color = 1;
				  x = x->parent;
				} else {
				  if (s->left->color == 0) {
					s->right->color = 0;
					s->color = 1;
					leftRotate(s);
					s = x->parent->left;
				  }

				  s->color = x->parent->color;
				  x->parent->color = 0;
				  s->left->color = 0;
				  rightRotate(x->parent);
				  x = root;
				}
			  }
			}
			x->color = 0;
		  }

		  void rbTransplant(NodePtr u, NodePtr v) {
			if (u->parent == 0) {
			  root = v;
			} else if (u == u->parent->left) {
			  u->parent->left = v;
			} else {
			  u->parent->right = v;
			}
			v->parent = u->parent;
		  }

		  void deleteNodeHelper(NodePtr node, int key) {
			NodePtr z = TNULL;
			NodePtr x, y;
			while (node != TNULL) {
			  if (node->data == key) {
				z = node;
			  }

			  if (node->data <= key) {
				node = node->right;
			  } else {
				node = node->left;
			  }
			}

			if (z == TNULL) {
			  std::cout << "Key not found in the tree" << std::endl;
			  return;
			}

			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL) {
			  x = z->right;
			  rbTransplant(z, z->right);
			} else if (z->right == TNULL) {
			  x = z->left;
			  rbTransplant(z, z->left);
			} else { void clear() 
	  {
		if (_size == 0)
		  return ;
		NodePtr n = begin()._node;
		while (n != TNULL) {
			if (n->left != TNULL) n = n->left;
			else if (n->right != TNULL) n = n->right;
			else { 
				//delete n, its a childless node
				alloc.destroy(n->data);
				alloc.deallocate(n->data, 1);
				NodePtr aux = n->parent;
				nalloc.deallocate(n, 1);
				if (!aux) break ;
				if (aux->left == n) aux->left = TNULL;
				else aux->right = TNULL;
				n = aux;
			}
		}
		_size = 0;
	}
			  y = minimum(z->right);
			  y_original_color = y->color;
			  x = y->right;
			  if (y->parent == z) {
				x->parent = y;
			  } else {
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			  }

			  rbTransplant(z, y);
			  y->left = z->left;
			  y->left->parent = y;
			  y->color = z->color;
			}
			delete z;
			if (y_original_color == 0) {
			  deleteFix(x);
			}
		  }

		  // For balancing the tree after insertion
		  

		  void printHelper(NodePtr root, std::string indent, bool last) {
			if (root != TNULL) {
			  std::cout << indent;
			  if (last) {
				std::cout << "R----";
				indent += "   ";
			  } else {
				std::cout << "L----";
				indent += "|  ";
			  }

			  std::string sColor = root->color ? "RED" : "BLACK";
			  std::cout << root->data << "(" << sColor << ")" << std::endl;
			  printHelper(root->left, indent, false);
			  printHelper(root->right, indent, true);
			}
		  }

   public:
		RedBlackTree() {
		  TNULL = new Node;
		  TNULL->color = 0;
		  TNULL->left = 0;
		  TNULL->right = 0;
		  root = TNULL;
		}

		void preorder() {
		  preOrderHelper(this->root);
		}

		void inorder() {
		  inOrderHelper(this->root);
		}

		void postorder() {
		  postOrderHelper(this->root);
		}

		NodePtr searchTree(int k) {
		  return searchTreeHelper(this->root, k);
		}




		// Inserting a node
		void insert(int key) {
		  NodePtr node = new Node;
		  node->parent = 0;
		  node->data = key;
		  node->left = TNULL;
		  node->right = TNULL;
		  node->color = 1;

		  NodePtr y = 0;
		  NodePtr x = this->root;

		  while (x != TNULL) {
			y = x;
			if (node->data < x->data) {
			  x = x->left;
			} else {
			  x = x->right;
			}
		  }

		  node->parent = y;
		  if (y == 0) {
			root = node;
		  } else if (node->data < y->data) {
			y->left = node;
		  } else {
			y->right = node;
		  }

		  if (node->parent == 0) {
			node->color = 0;
			return;
		  }

		  if (node->parent->parent == 0) {
			return;
		  }

		  insertFix(node);
		}

		NodePtr getRoot() {
		  return this->root;
		}

		void deleteNode(int data) {
		  deleteNodeHelper(this->root, data);
		}

	  void printTree() {
		if (root) {
		  printHelper(this->root, "", true);
		}
	  }


	};
};

#endif