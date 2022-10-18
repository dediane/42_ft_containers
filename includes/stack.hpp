/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:59:17 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/18 15:02:42 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		protected:
			Container c;
		public:
			typedef typename Container::value_type		value_type;
			typedef Container		container_type;
			typedef typename Container::size_type			size_type;
			
			
			//******************************//
			//Member functions              //
			//******************************//
			//constructor
			explicit stack (const Container& cc = Container()) : c(cc){}
			~stack(void) {};
			stack &operator=(const stack &other)
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
			friend bool	operator==(const stack<A, B> &lhs, const stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator!= (const stack<A, B>& lhs, const stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator<  (const stack<A, B>& lhs, const stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator<= (const stack<A, B>& lhs, const stack<A, B> &rhs);
			
			template <class A, class B>
			friend bool operator>  (const stack<A, B>& lhs, const stack<A, B> &rhs);

			template <class A, class B>
			friend bool operator>= (const stack<A, B>& lhs, const stack<A, B> &rhs);
	};
	
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};
};

#endif