/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:39:05 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/21 00:44:28 by ddecourt         ###   ########.fr       */
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
    std::cout << std::endl;

    std::cout << _BBLUE << "** function end() **" << _BLACK << std::endl << std::endl;
    
    ft::map<T1, T2>::iterator ite = map.end();
    std::map<T1, T2>::iterator ite2 = maap.end();
    std::cout << _BLUE << "FT test:" << _BLACK << std::endl;
    for (; ite != map.begin(); --ite)
        std::cout << "first: " << ite->first << " | second: " << ite->second << std::endl; 
    std::cout << _BLUE << "STD test:" << _BLACK << std::endl;
    for (; ite2 != maap.begin(); --ite2)
        std::cout << "first: " << ite2->first << " | second: " << ite2->second << std::endl;
    map['x'] == maap['x'] ? printresult(1) : printresult(0);
    map['y'] == maap['y'] ? printresult(1) : printresult(0);
    map['z'] == maap['z'] ? printresult(1) : printresult(0);
    std::cout << std::endl;

    std::cout << _BBLUE << "** function rbegin() & rend() **" << _BLACK << std::endl << std::endl;
    
    ft::map<T1, T2>::reverse_iterator rit = map.rbegin();
    std::map<T1, T2>::reverse_iterator rit2 = maap.rbegin();
    ft::map<T1, T2>::reverse_iterator rite = map.rend();
    std::map<T1, T2>::reverse_iterator rite2 = maap.rend();
    
    std::cout << _BLUE << "FT test:" << _BLACK << std::endl;
    for (; rit != rite; ++rit)
        std::cout << "first: " << rit->first << " | second: " << rit->second << std::endl;
    std::cout << _BLUE << "STD test:" << _BLACK << std::endl;
        for (; rit2 != rite2; ++rit2)
    std::cout << "first: " << rit2->first << " | second: " << rit2->second << std::endl;
    map['x'] == maap['x'] ? printresult(1) : printresult(0);
    map['y'] == maap['y'] ? printresult(1) : printresult(0);
    map['z'] == maap['z'] ? printresult(1) : printresult(0);
}

void map_max_capacity()
{
    std::cout << std::endl << _GREEN << "                                     MAX CAPACITY                " << _BLACK << std::endl;

    std::cout << _BBLUE << "** function empty() **" << _BLACK << std::endl << std::endl;
    ft::map<T1, T2> map;
    std::map<T1, T2> maap;
    
    std::cout << "les maps sont vides" << std::endl;
    map.empty() ? printresult(1) : printresult(0);
    maap.empty() ? printresult(1) : printresult(0);
    map['w'] = 4;
    map['x'] = 8;
    map['y'] = 16;
    map['z'] = 32;

    maap['w'] = 4;
    maap['x'] = 8;
    maap['y'] = 16;
    maap['z'] = 32;
    std::cout << std::endl;
    std::cout << "les maps sont remplies" << std::endl;
    !map.empty() ? printresult(1) : printresult(0);
    !maap.empty() ? printresult(1) : printresult(0);
    std::cout << std::endl;

    std::cout << _BBLUE << "** function size() **" << _BLACK << std::endl << std::endl;
    std::cout << "checking size for map with ft & std:";
    map.size() == maap.size() ? printresult(1) : printresult(0);
    std::cout << std::endl;
    
    std::cout << _BBLUE << "** function max_size() **" << _BLACK << std::endl << std::endl;
    std::cout << "checking max_size for map with ft & std:";
    map.max_size() == maap.max_size() ? printresult(1) : printresult(0);
    std::cout << std::endl;
    map.clear();
    maap.clear();
    std::cout << "checking max_size for map with ft & std after clear function called:";
    map.max_size() == maap.max_size() ? printresult(1) : printresult(0);
    std::cout << std::endl;
}

void map_element_access()
{
    std::cout << std::endl << _GREEN << "                                     ELEMENT ACCESS                " << _BLACK << std::endl;

    std::cout << _BBLUE << "** function operator[] **" << _BLACK << std::endl;
    ft::map<T1, T2> map;
    std::map<T1, T2> maap;
    
    map['w'] = 114;
    map['x'] = 578;
    map['y'] = 37816;
    map['z'] = 3732;

    maap['w'] = 114;
    maap['x'] = 578;
    maap['y'] = 37816;
    maap['z'] = 3732;
    
    map['y'] == maap['y'] ? printresult(1) : printresult(0);
    map['x'] == maap['x'] ? printresult(1) : printresult(0);
    std::cout << std::endl;

}

void map_modifiers()
{
    std::cout << std::endl << _GREEN << "                                     MODIFIERS                " << _BLACK << std::endl;

    
    std::cout << _BBLUE << "** function insert(single element) **" << _BLACK << std::endl << std::endl;
    ft::map<T1, T2> map;
    std::map<T1, T2> maap;

    map.insert(ft::pair<T1, T2> ('A', 1));
    map.insert(ft::pair<T1, T2> ('B', 10));
    map.insert(ft::pair<T1, T2> ('C', 100));
    map.insert(ft::pair<T1, T2> ('D', 1000));

    maap.insert(std::pair<T1, T2> ('A', 1));
    maap.insert(std::pair<T1, T2> ('B', 10));
    maap.insert(std::pair<T1, T2> ('C', 100));
    maap.insert(std::pair<T1, T2> ('D', 1000));

    print_map_ft(map);
    print_map_std(maap);

    map['A'] == maap['A'] ? printresult(1) : printresult(0);
    map['D'] == maap['D'] ? printresult(1) : printresult(0);

    std::cout << std::endl;
    std::cout << _BBLUE << "** function insert(position and element) **" << _BLACK << std::endl << std::endl;

    ft::map<T1, T2> mp;
    std::map<T1, T2> mpp;
    ft::map<T1, T2>::iterator it = mp.begin();
    std::map<T1, T2>::iterator it2 = mpp.begin();

    mp.insert(it, ft::pair<T1, T2>('A', 1));
    mpp.insert(it2, std::pair<T1, T2>('A', 1));
    it = mp.begin();
    it2 = mpp.begin();
    mp.insert(it, ft::pair<T1, T2>('B', 10));
    mpp.insert(it2, std::pair<T1, T2>('B', 10));
    it++;
    it2++;
    mp.insert(it, ft::pair<T1, T2>('C', 100));
    mpp.insert(it2, std::pair<T1, T2>('C', 100));
    
    print_map_ft(map);
    print_map_std(maap);

    map['A'] == maap['A'] ? printresult(1) : printresult(0);
    map['C'] == maap['C'] ? printresult(1) : printresult(0);
    std::cout << std::endl;
    
    std::cout << _BBLUE << "** function insert(range) **" << _BLACK << std::endl << std::endl;

    {
        ft::map<T1, T2>  map;
        std::map<T1, T2> maap;
        ft::map<T1, T2>  map2;
        std::map<T1, T2> maap2;
        ft::map<T1, T2>::iterator it = map.end();
        std::map<T1, T2>::iterator it2 = maap.end();

        map.insert(ft::pair<T1, T2> ('A', 1));
        map.insert(ft::pair<T1, T2> ('B', 10));
        map.insert(ft::pair<T1, T2> ('C', 100));
        map.insert(ft::pair<T1, T2> ('D', 1000));
        map.insert(ft::pair<T1, T2> ('E', 10000));

        maap.insert(std::pair<T1, T2> ('A', 1));
        maap.insert(std::pair<T1, T2> ('B', 10));
        maap.insert(std::pair<T1, T2> ('C', 100));
        maap.insert(std::pair<T1, T2> ('D', 1000));
        maap.insert(std::pair<T1, T2> ('E', 10000));
        --(--it);
        --(--it2);
        map2.insert(map.begin(), it);
        maap2.insert(maap.begin(), it2);

        print_map_ft(map2);
        print_map_std(maap2);

        map2['A'] == maap2['A'] ? printresult(1):printresult(0);
        map2['C'] == maap2['C'] ? printresult(1):printresult(0);
    }
    std::cout << std::endl;
    std::cout << _BBLUE << "** function erase(position) **" << _BLACK << std::endl << std::endl;
    {
        ft::map<T1, T2>  map;
        std::map<T1, T2> maap;

        map.insert(ft::pair<T1, T2> ('A', 1));
        map.insert(ft::pair<T1, T2> ('B', 10));
        map.insert(ft::pair<T1, T2> ('C', 100));
        map.insert(ft::pair<T1, T2> ('D', 1000));
        map.insert(ft::pair<T1, T2> ('E', 10000));

        maap.insert(std::pair<T1, T2> ('A', 1));
        maap.insert(std::pair<T1, T2> ('B', 10));
        maap.insert(std::pair<T1, T2> ('C', 100));
        maap.insert(std::pair<T1, T2> ('D', 1000));
        maap.insert(std::pair<T1, T2> ('E', 10000));

        std::cout << _BLUE << "before erase called:" << _BLACK << std::endl;
        print_map_ft(map);
        print_map_std(maap);

        ft::map<T1, T2>::iterator it = map.begin();
        std::map<T1, T2>::iterator it2 = maap.begin();
        map.erase(it);
        it = map.begin();
        maap.erase(it2);
        it2 = maap.begin();
        map.erase(it);
        it = map.begin();
        maap.erase(it2);
        it2 = maap.begin();
        
        std::cout << _BLUE << "before erase called 2 times:" << _BLACK << std::endl;
        print_map_ft(map);
        print_map_std(maap);
        map.size() == maap.size() ? printresult(1):printresult(0);
    }
    std::cout << std::endl;
    std::cout << _BBLUE << "** function erase(key) **" << _BLACK << std::endl << std::endl;
    {
        ft::map<T1, T2>  map;
        std::map<T1, T2> maap;

        map.insert(ft::pair<T1, T2> ('A', 1));
        map.insert(ft::pair<T1, T2> ('B', 10));
        map.insert(ft::pair<T1, T2> ('C', 100));
        map.insert(ft::pair<T1, T2> ('D', 1000));
        map.insert(ft::pair<T1, T2> ('E', 10000));

        maap.insert(std::pair<T1, T2> ('A', 1));
        maap.insert(std::pair<T1, T2> ('B', 10));
        maap.insert(std::pair<T1, T2> ('C', 100));
        maap.insert(std::pair<T1, T2> ('D', 1000));
        maap.insert(std::pair<T1, T2> ('E', 10000));

        std::cout << _BLUE << "before erase called:" << _BLACK << std::endl;
        print_map_ft(map);
        print_map_std(maap);

        map.erase('C');
        maap.erase('C');

        map.erase('A');
        maap.erase('A');

        std::cout << _BLUE << "before erase called:" << _BLACK << std::endl;
        print_map_ft(map);
        print_map_std(maap);
        map.size() == maap.size() ? printresult(1):printresult(0);
    }

    {
        std::cout << _BBLUE << "** function erase(range) **" << _BLACK << std::endl << std::endl;
        ft::map<T1, T2>  map;
        std::map<T1, T2> maap;

        map.insert(ft::pair<T1, T2> ('A', 1));
        map.insert(ft::pair<T1, T2> ('B', 10));
        map.insert(ft::pair<T1, T2> ('C', 100));
        map.insert(ft::pair<T1, T2> ('D', 1000));
        map.insert(ft::pair<T1, T2> ('E', 10000));

        maap.insert(std::pair<T1, T2> ('A', 1));
        maap.insert(std::pair<T1, T2> ('B', 10));
        maap.insert(std::pair<T1, T2> ('C', 100));
        maap.insert(std::pair<T1, T2> ('D', 1000));
        maap.insert(std::pair<T1, T2> ('E', 10000));
        print_map_ft(map);
        print_map_std(maap);
        ft::map<T1, T2>::iterator it = map.begin();
        std::map<T1, T2>::iterator it2 = maap.begin();
        ft::map<T1, T2>::iterator ite = map.end();
        std::map<T1, T2>::iterator ite2 = maap.end();
        map.erase(++it, --ite);
        maap.erase(++it2, --ite2);
        map.size() == maap.size() ? printresult(1) : printresult(0);
    }

    std::cout << _BBLUE << "** function erase(range) **" << _BLACK << std::endl << std::endl;
    
    std::cout << _BBLUE << "** function swap(member function) **" << _BLACK << std::endl << std::endl;
    {
        ft::map<T1, T2>  foo;
        ft::map<T1, T2>  bar;
        std::map<T1, T2> fooo;
        std::map<T1, T2> baar;
        
        foo['1'] = 10;
		foo['2'] = 20;
		bar['7'] = 70;
		bar['8'] = 80;
		bar['9'] = 90;
        
        fooo['1'] = 10;
		fooo['2'] = 20;
		baar['7'] = 70;
		baar['8'] = 80;
		baar['9'] = 90;
        
        std::cout << "Print foo before swap\n";
		print_map_ft(foo);
		std::cout << "Print bar before swap\n";
		print_map_ft(bar);
		foo.swap(bar);
		std::cout << "Print foo after swap\n";
		print_map_ft(foo);
		std::cout << "Print bar after swap\n";
		print_map_ft(bar);
        
        std::cout << "Print fooo before swap\n";
		print_map_std(fooo);
		std::cout << "Print baar before swap\n";
		print_map_std(baar);
		fooo.swap(baar);
		std::cout << "Print fooo after swap\n";
		print_map_std(fooo);
		std::cout << "Print baar after swap\n";
		print_map_std(baar);
        
        foo['7'] == fooo['7'] ? printresult(1) : printresult(0);
        bar['1'] == baar['1'] ? printresult(1) : printresult(0);
        std::cout << std::endl;
        std::cout << _BBLUE << "** function swap(function template) **" << _BLACK << std::endl << std::endl;
        swap(foo, bar);
        swap(fooo, baar);
        
        foo['1'] == fooo['1'] ? printresult(1) : printresult(0);
        bar['7'] == baar['7'] ? printresult(1) : printresult(0);
    }
}

void testerMap()
{
    map_constructor_tester();
    map_operator_tester();
    map_iterator_test();
    map_max_capacity();
    map_element_access();
    map_modifiers();
}