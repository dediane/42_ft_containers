/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:44:52 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/17 15:48:23 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include <iostream>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <list>


/************************************************/
/*      MAIN vector/copy_construct.cpp          */
/************************************************/


// #define TESTED_TYPE int

// int		main(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

// 	std::cout << "len: " << (ite - it) << std::endl;
// 	for (; it != ite; ++it)
// 		*it = (ite - it);

// 	 it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
// 	for (int i = 0; it != ite; ++it)
// 	 	*it = ++i * 5;

// 	it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 7;
// 	vct_copy.push_back(42);
// 	vct_copy.push_back(21);

// 	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);

// 	vct = vct_copy;
// 	vct_copy = vct_range;
// 	vct_range.clear();

// 	std::cout << "\t-- PART TWO --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);
// 	return (0);
// }





/************************************************/
/*      MAIN vector/rite_eq_ope.cpp             */
/************************************************/


#define TESTED_TYPE foo<int>

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

	 for (int i = size; it_0 != it_1; --i)
	//  	*it_0++ = i;
	// printSize(vct, 1);
	// it_0 = vct.rbegin();
	// cit_1 = vct.rend();
	// it_mid = it_0 + 3;
	// cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	// std::cout << std::boolalpha;
	// std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	// std::cout << "\t\tft_eq_ope:" << std::endl;
	// // regular it
	// ft_eq_ope(it_0 + 3, it_mid);
	// ft_eq_ope(it_0, it_1);
	// ft_eq_ope(it_1 - 3, it_mid);
	// // const it
	// ft_eq_ope(cit_0 + 3, cit_mid);
	// ft_eq_ope(cit_0, cit_1);
	// ft_eq_ope(cit_1 - 3, cit_mid);
	// // both it
	// ft_eq_ope(it_0 + 3, cit_mid);
	// ft_eq_ope(it_mid, cit_0 + 3);
	// ft_eq_ope(it_0, cit_1);
	// ft_eq_ope(it_1, cit_0);
	// ft_eq_ope(it_1 - 3, cit_mid);
	// ft_eq_ope(it_mid, cit_1 - 3);

	return (0);
}

/************************************************/
/*        MAIN vector/rite_arrow.cpp            */
/************************************************/

// #define TESTED_TYPE foo<int>

// int		main(void)
// {
// 	const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(vct.rbegin());
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(vct.rend());

// 	for (int i = 1; it != ite; ++i)
// 		*it++ = (i * 7);
	//printSize(vct, 1);

	// it = vct.rbegin();
	// ite = vct.rbegin();

	// std::cout << *(++ite) << std::endl;
	// std::cout << *(ite++) << std::endl;
	// std::cout << *ite++ << std::endl;
	// std::cout << *++ite << std::endl;

	// it->m();
	// ite->m();

	// std::cout << *(++it) << std::endl;
	// std::cout << *(it++) << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *++it << std::endl;

	// std::cout << *(--ite) << std::endl;
	// std::cout << *(ite--) << std::endl;
	// std::cout << *--ite << std::endl;
	// std::cout << *ite-- << std::endl;

	// (*it).m();
	// (*ite).m();

	// std::cout << *(--it) << std::endl;
	// std::cout << *(it--) << std::endl;
	// std::cout << *it-- << std::endl;
	// std::cout << *--it << std::endl;

// 	return (0);
// }

/**********************************************/
/*       MAIN -> vector/at_const.cpp          */
/**********************************************/

// #define TESTED_TYPE int

// int		main(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 	{
// 		vct.at(i) = (vct.size() - i) * 3;
// 		std::cout << "vct[]: " << vct[i] << std::endl;
// 	}
// 	printSize(vct);

// 	TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

// 	std::cout << "ICI -> " << vct[0] << std::endl;
// 	std::cout << "ICI-> " << vct[vct.size()- 1] << std::endl;
// 	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
// 	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

// 	for (unsigned long int i = 0; i < vct_c.size(); ++i)
// 		std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
// 	try {
// 		std::cout << vct_c.at(10) << std::endl;
// 	}
// 	catch (std::out_of_range &e) {
// 		std::cout << "Catch out_of_range exception!" << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << "Catch exception: " << e.what() << std::endl;
// 	}
// 	printSize(vct_c);
// 	return (0);
// }
