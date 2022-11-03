/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:29:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/03 18:38:07 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "vector.hpp"

# define _BLUE "\033[0;34m"
# define _BLACK "\033[0m"
# define _CYAN "\033[0;36m"
# define _GREEN "\033[1m\033[32m"
# define _RED "\033[1m\033[31m"
# define _BBLUE "\033[1;34m"

void print_vector_ft(ft::vector<int> vec)
{
    if (vec.empty())
        std::cout << _BLUE << "namespace FT -> " << _BLACK << "Empty vector" << std::endl;
    else
    {
        ft::vector<int>::iterator it = vec.begin();
        ft::vector<int>::iterator ite = vec.end();
        std::cout << _BLUE << "namespace FT -> " << _BLACK << "Size = " << vec.size() << std::endl;
        std::cout << _BLUE << "namespace FT -> " << _BLACK << "Capacity = " << vec.capacity() << std::endl;
        for (; it != ite; it++)
            std::cout << *it << " | ";
        std::cout << std::endl;
    }
}

void    printresult(int i)
{
    std::cout << std::endl;
    if (i == 1)
        std::cout << _GREEN << "OK ✅" << _BLACK << std::endl;
    else
        std::cout << _RED << "KO ❌" << _BLACK << std::endl;
}

void print_vector_std(std::vector<int> vec)
{
    if (vec.empty())
        std::cout << _CYAN << "namespace STD -> " << _BLACK << "Empty vector" << std::endl;
    else
    {
        std::vector<int>::iterator it = vec.begin();
        std::vector<int>::iterator ite = vec.end();
        std::cout << _CYAN << "namespace STD -> " << _BLACK << "Size = " << vec.size() << std::endl;
        std::cout << _CYAN << "namespace STD -> " << _BLACK << "Capacity = " << vec.capacity() << std::endl;
        for (; it != ite; it++)
            std::cout << *it << " | ";
        std::cout << std::endl;
    }
}

void testerVectorConstructors()
{
    std::cout << std::endl << _GREEN << "                                     CONSTRUCTORS                 " << _BLACK << std::endl;
    
    ft::vector<int> vec;
    ft::vector<int> vec2 (5, 50);
    ft::vector<int> vec3 (vec2.begin(), vec2.end());
    ft::vector<int> vec4 (vec3);

    std::vector<int> vect;
    std::vector<int> vect2 (5, 50);
    std::vector<int> vect3 (vect2.begin(), vect2.end());
    std::vector<int> vect4 (vect3);

    print_vector_ft(vec);
    print_vector_std(vect);
    vec.size() == vect.size() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;
    print_vector_ft(vec2);
    print_vector_std(vect2);
    vec2.size() == vect2.size()? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;
    print_vector_ft(vec3);
    print_vector_std(vect3);
    vec3.size() == vect3.size() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;

}

void testerVectorOperator()
{
    std::cout << std::endl << _GREEN << "                                     OPERATOR =                 " << _BLACK << std::endl;
    
    ft::vector<int> vec(3,8);
    ft::vector<int> vec2(5,10);
    
    std::vector<int> vect(3,8);
    std::vector<int> vect2(5,10);
    
    std::cout << "avant operator =" << std::endl;
    print_vector_ft(vec2);
    print_vector_std(vect2);
    vec2 = vec;
    vect2 = vect;
    print_vector_ft(vec2);
    print_vector_std(vect2);

    vec2.size() == vect2.size() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;

}

void testerVectorIterator()
{
    std::cout << std::endl << _GREEN << "                                     ITERATORS                 " << _BLACK << std::endl;
    ft::vector<int> vec;
    std::vector<int> vect;
    for (int i = 0; i < 10 ; i++)
        vec.push_back(i);
    for (int i = 0; i < 10 ; i++)
        vect.push_back(i);
    print_vector_ft(vec);
    print_vector_std(vect);
    
    std::cout << std::endl;
    std::cout << _BBLUE << "** function begin() **" << _BLACK << std::endl << std::endl;
    ft::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator it2 = vect.begin();
    std::cout << _BLUE << "namespace FT -> " << _BLACK << *it << std::endl;
    std::cout << _CYAN << "namespace STD -> " << _BLACK << *it2 << std::endl;
    *it == *it2 ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;


    std::cout << std::endl;
    std::cout << _BBLUE << "** function end() **" << _BLACK << std::endl << std::endl;

    print_vector_ft(vec);
    print_vector_std(vect);
    for (ft::vector<int>::iterator t = vec.begin(); t != vec.end(); ++t)
        std::cout << ' ' << *t;
    std::cout << std::endl;
    for (std::vector<int>::iterator tt = vect.begin(); tt != vect.end(); ++tt)
        std::cout << ' ' << *tt;
    printresult(1);
    std::cout << "__________________________________________________________________________________________" << std::endl;
}


void testerVectorCapacity()
{
    std::cout << std::endl << _GREEN << "                                     CAPACITY                 " << _BLACK << std::endl;
    std::cout << std::endl;
    std::cout << _BBLUE << "** function size() **" << _BLACK << std::endl << std::endl;
    ft::vector<int> vec;
    std::vector<int> vect;
    for (int i = 0; i < 92; i++)
    {
        vec.push_back(i);
        vect.push_back(i);
    }
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.size() == vect.size() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;


    std::cout << std::endl;
    std::cout << _BBLUE << "** function max_size() **" << _BLACK << std::endl << std::endl;
    std::cout << _BLUE << "namespace FT -> " << _BLACK << vec.max_size() << std::endl;
    std::cout << _CYAN << "namespace STD -> " << _BLACK << vect.max_size() << std::endl;
    vec.max_size() == vect.max_size() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;

    std::cout << std::endl;
    std::cout << _BBLUE << "** function resize() **" << _BLACK << std::endl << std::endl;
    vec.resize(10);
    vect.resize(10);
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.size() == vect.size() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;

    std::cout << std::endl;
    std::cout << _BBLUE << "** function capacity() **" << _BLACK << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        vect.push_back(i);
    }
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.capacity() == vect.capacity() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;


    std::cout << std::endl;
    std::cout << _BBLUE << "** function empty() **" << _BLACK << std::endl << std::endl;
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.empty() == vect.empty() ? printresult(1) : printresult(2);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;

    while (!vec.empty())
        vec.pop_back();
    while (!vect.empty())
        vect.pop_back();
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.empty() == vect.empty() ? printresult(1) : printresult(2);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;

    std::cout << _BBLUE << "** function reserve() **" << _BLACK << std::endl << std::endl;
    ft::vector<int>::size_type a;
    ft::vector<int>::size_type d;
    ft::vector<int> b;
    ft::vector<int> c;
    a = b.capacity();
    for (int i = 0; i < 20; i++)
    {
        b.push_back(i);
        if (a != b.capacity())
        {
            a = b.capacity();
        }
    }
    d = c.capacity();
    for (int i = 0; i < 20; i++)
    {
        c.push_back(i);
        if (d != c.capacity())
        {
            d = c.capacity();
        }
    }
    std::vector<int>::size_type e;
    std::vector<int>::size_type f;
    std::vector<int> j;
    std::vector<int> ii;
    e = j.capacity();
    for (int i = 0; i < 20; i++)
    {
        j.push_back(i);
        if (e != j.capacity())
        {
            e = j.capacity();
        }
    }
    f = ii.capacity();
    for (int i = 0; i < 20; i++)
    {
        ii.push_back(i);
        if (f != ii.capacity())
        {
            f = ii.capacity();
        }
    }
    print_vector_ft(c);
    print_vector_std(ii);
    c.capacity() == ii.capacity() ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;
    
}

void    testerVectorElementAccess()
{
    std::cout << std::endl << _GREEN << "                                  ELEMENT ACCESS                " << _BLACK << std::endl;
    std::cout << std::endl;
    std::cout << _BBLUE << "** operateur[] **" << _BLACK << std::endl << std::endl;
    ft::vector<int> vec;
    std::vector<int> vect;
    
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i);
        vect.push_back(i);
    }
    print_vector_ft(vec);
    print_vector_std(vect);
    std::cout << std::endl;
    std::cout << _BLUE << "namespace FT -> " << _BLACK << "vec[4] = " << vec[4] << std::endl;
    std::cout << _CYAN << "namespace STD -> " << _BLACK << "vect[4] = " << vect[4] << std::endl;
    vec[4] == vect[4] ? printresult(1) : printresult(0);

    std::cout << _BLUE << "namespace FT -> " << _BLACK << "vec[19] = " << vec[19] << std::endl;
    std::cout << _CYAN << "namespace STD -> " << _BLACK << "vect[19] = " << vect[19] << std::endl;
    vec[19] == vect[19] ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;

    std::cout << _BBLUE << "** function at() **" << _BLACK << std::endl << std::endl;
    std::cout << "Changing 5th value by 100\n";
    vec.at(5) = 100;
    vect.at(5) = 100;
    print_vector_ft(vec);
    print_vector_std(vect);
    vec[5] == 100 && vect[5] == 100 ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;

    std::cout << _BBLUE << "** function front() **" << _BLACK << std::endl << std::endl;
    vec.front();
    vect.front();
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.front() = 300;
    vect.front()= 300;
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.front() == vect.front()? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;

    std::cout << _BBLUE << "** function back() **" << _BLACK << std::endl << std::endl;
    vec.back();
    vect.back();
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.back() = 600;
    vect.back()= 600;
    print_vector_ft(vec);
    print_vector_std(vect);
    vec.back() == vect.back()? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;

}

void testerVectorModifier()
{
    std::cout << std::endl << _GREEN << "                                  MODIFIERS                " << _BLACK << std::endl;
    std::cout << std::endl;
    std::cout << _BBLUE << "** function assign() **" << _BLACK << std::endl << std::endl;
    ft::vector<int> vec;
    std::vector<int> vect;
    ft::vector<int> vec2;
    std::vector<int> vect2;

    vec.assign(5,100);
    vect.assign(5,100);
    vec2.assign(vec.begin() + 1, vec.end() - 1);
    vect2.assign(vect.begin() + 1, vect.end() - 1);
    print_vector_ft(vec);
    print_vector_std(vect);
    vec[0] == vect[0] ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;
    print_vector_ft(vec2);
    print_vector_std(vect2);
    vec2[0] == vect2[0] ? printresult(1) : printresult(0);
    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;

    std::cout << _BBLUE << "** function push_back() **" << _BLACK << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        vect.push_back(i);
    }
    print_vector_ft(vec);
    print_vector_std(vect);
    vec[vec.size() - 1] == vect[vect.size() - 1] ? printresult(1) : printresult(0);

    std::cout << "__________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;
    std::cout << _BBLUE << "** function pop_back() **" << _BLACK << std::endl << std::endl;

    for (int i = 0; i < 10; i++)
    {
        vec.pop_back();
        vect.pop_back();
    }
    print_vector_ft(vec);
    print_vector_std(vect);
    vec[vec.size() - 1] == vect[vect.size() - 1] ? printresult(1) : printresult(0);
}