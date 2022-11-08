/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:39:05 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/08 17:14:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tester.hpp"
#include "vector_tester.hpp"

void    print_map_ft(ft::map<T1, T2> map)
{
    if (map.empty())
    {
        std::cout << _BLUE << "namespace FT -> " << _BLACK << "Empty vector" << std::endl;
    }
    else
    {
        ft::map<T1, T2>::iterator it = map.begin();
        ft::map<T1, T2>::iterator ite = map.end();
    	std::cout << "Size : " << map.size() << std::endl;
		std::cout << "Max size : " << map.max_size() << std::endl;
		for (; it != ite; it++)
			std::cout << it->second << " | ";
        std::cout << std::endl << "____________________________" << std::endl;
    }
    
}

void    print_map_std(std::map<T1, T2> map)
{
    if (map.empty())
    {
        std::cout << _BLUE << "namespace STD -> " << _BLACK << "Empty vector" << std::endl;
    }
    else
    {
        std::map<T1, T2>::iterator it = map.begin();
        std::map<T1, T2>::iterator ite = map.end();
    	std::cout << "Size : " << map.size() << std::endl;
		std::cout << "Max size : " << map.max_size() << std::endl;
		for (; it != ite; it++)
			std::cout << it->second << " | ";
        std::cout << std::endl << "____________________________" << std::endl;
    }
    
}

void map_constructor_tester()
{
        std::cout << std::endl << _GREEN << "                                     CONSTRUCTORS                 " << _BLACK << std::endl;
        
        ft::map<T1, T2> first;

        first['a']=10;
		first['b']=20;
		first['c']=30;
		first['d']=40;
        
        ft::map<T1, T2> second(first.begin(), first.end());
        ft::map<T1, T2> third(second);

        std::map<T1, T2> stdfirst;

        stdfirst['a']=10;
		stdfirst['b']=20;
		stdfirst['c']=30;
		stdfirst['d']=40;
        
        std::map<T1, T2> stdsecond(stdfirst.begin(), stdfirst.end());
        std::map<T1, T2> stdthird(stdsecond);
        print_map_ft(first);
        print_map_ft(second);
        print_map_ft(third);
        print_map_std(stdfirst);
        print_map_std(stdsecond);
        print_map_std(stdthird);
        first.size() == stdfirst.size() ? printresult(1): printresult(0);
        second.size() == stdsecond.size() ? printresult(1): printresult(0);
        third.size() == stdthird.size() ? printresult(1): printresult(0);
}

void testerMap()
{
    map_constructor_tester();
}