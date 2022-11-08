/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:39:05 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/08 23:19:08 by ddecourt         ###   ########.fr       */
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

void map_operator_tester()
{
    std::cout << std::endl << _GREEN << "                                     OPERATORS                 " << _BLACK << std::endl;

    ft::map<T1, T2> map;
    std::map<T1, T2> maap;

    ft::map<T1, T2> map2;
    std::map<T1, T2> maap2;

    map['x'] = 1;
    map['y'] = 2;
    map['z'] = 3;

    maap['x'] = 1;
    maap['y'] = 2;
    maap['z'] = 3;

    map2 = map;
    maap2 = maap;
    map = ft::map<T1, T2>();
    maap = std::map<T1, T2>();

    std::cout << "PRINT MAP2 et MAP (FT functions)" <<std::endl;
    print_map_ft(map2);
    print_map_ft(map);
    std::cout << "PRINT MAAP2 et MAAP (STD functions)" <<std::endl;
    print_map_std(maap2);
    print_map_std(maap);

    map['x'] == maap['x'] ? printresult(1) : printresult(0);
    map2['x'] == maap2['x'] ? printresult(1) : printresult(0);
    map2['z'] == maap2['z'] ? printresult(1) : printresult(0);

}

void map_iterator_test()
{
    std::cout << std::endl << _GREEN << "                                     ITERATORS                " << _BLACK << std::endl;

    std::cout << _BBLUE << "** function begin() **" << _BLACK << std::endl << std::endl;
    ft::map<T1, T2> map;
    std::map<T1, T2> maap;

    map['x'] = 10;
    map['y'] = 20;
    map['z'] = 30;

    maap['x'] = 10;
    maap['y'] = 20;
    maap['z'] = 30;

    ft::map<T1, T2>::iterator it = map.begin();
    std::map<T1, T2>::iterator it2 = maap.begin();
    std::cout<< "it begin = " << it->first << std::endl;
    std::cout<< "it2 begin = " << it2->first << std::endl;

    std::cout << _BLUE << "FT test:" << _BLACK << std::endl;
    for (; it != map.end(); it++)
        std::cout << "first: " << it->first << " | second: " << it->second << std::endl; 
    std::cout << _BLUE << "STD test:" << _BLACK << std::endl;
    for (; it2 != maap.end(); it2++)
        std::cout << "first: " << it2->first << " | second: " << it2->second << std::endl; 

    map['x'] == maap['x'] ? printresult(1) : printresult(0);
    map['y'] == maap['y'] ? printresult(1) : printresult(0);
    map['z'] == maap['z'] ? printresult(1) : printresult(0);

    std::cout << _BBLUE << "** function end() **" << _BLACK << std::endl << std::endl;
    
}

void testerMap()
{
    map_constructor_tester();
    map_operator_tester();
    map_iterator_test();
}