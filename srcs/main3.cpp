/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:44:52 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/03 13:23:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include <iostream>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "red_black_tree.hpp"
#include "utils/enable_if.hpp"
#include "utils/equal.hpp"
#include "utils/pair.hpp"
#include "utils/lexicographical_compare.hpp"
#include <list>

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, lst_size - i));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end()), mp2;
	TESTED_NAMESPACE::map<T1, T2>::iterator it;

	lst.clear();
	is_empty(mp);
	printSize(mp);

	is_empty(mp2);
	mp2 = mp;
	is_empty(mp2);

	it = mp.begin();
	for (unsigned long int i = 3; i < mp.size(); ++i)
		it++->second = i * 7;

	printSize(mp);
	printSize(mp2);

	mp2.clear();
	is_empty(mp2);
	printSize(mp2);
	return (0);
}
