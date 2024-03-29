/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:57:44 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/08 13:26:05 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>
# include <memory>

namespace ft {
	template <class T1, class T2>
	struct pair
	{
		
		typedef T1	first_type;
		typedef T2	second_type;
	
		first_type	first;
		second_type	second;
	
		pair() : first(T1()), second(T2()) {};
		
		pair(const T1& a, const T2& b) : first(a), second(b) {};
	
		template<class U, class V>
		pair(const pair< U, V >& pr) : first(pr.first), second(pr.second) {};
		
		//~pair() {};


		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		};
	};
	
	template< class T1, class T2 >
	pair<T1,T2>		make_pair( T1 t, T2 u )
	{
		return pair<T1, T2>(t, u);
	};

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) 
	{
		return ( lhs.first == rhs.first && lhs.second == rhs.second );
	};

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) 
	{
		return !(lhs==rhs);
	};

	template <class T1, class T2>
        bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {
		return ((lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	};

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) 
	{
		return !(rhs<lhs);
	};

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return rhs<lhs;
	};

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) 
	{
		return !(lhs<rhs);
	};
}

#endif