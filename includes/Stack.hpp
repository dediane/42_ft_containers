/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:59:17 by ddecourt          #+#    #+#             */
/*   Updated: 2022/09/03 22:51:44 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class Stack
	{
		protected:
			Container c;
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef	size_t			size_type;
			
			
			//******************************//
			//Member functions              //
			//******************************//
			//constructor
			explicit Stack (const Container& cc = Container()) : c(cc){}
			~Stack(void) {};
			Stack &operator=(const Stack &other)
			{
				c = other.c;
				return (*this);
			};
			
			bool empty() const
			{
				return c.empty();
			}
			
			size_type size() const
			{
				return c.size();
			}
			
			value_type& top()
			{
				return c.back();
			}
			
			const value_type& top() const
			{
				return c.back();
			}
			
			void push (const value_type& val)
			{
				return c.push_back(val);
			}
			
			void pop()
			{
				return c.pop_back();
			}


			//******************************//
			//Relational operators          //
			//******************************//
			template <class A, class B>
			friend bool	operator==(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator!= (const Stack<A, B>& lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator<  (const Stack<A, B>& lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator<= (const Stack<A, B>& lhs, const Stack<A, B> &rhs);
			
			template <class A, class B>
			friend bool operator>  (const Stack<A, B>& lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator>= (const Stack<A, B>& lhs, const Stack<A, B> &rhs);
	};
	
	template <class T, class Container>
	bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};
	template <class T, class Container>
	bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};
	template <class T, class Container>
	bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};
};

#endif