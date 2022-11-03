/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:30:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/03 15:20:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

#include <vector>
#include <stack>
#include <map>


#include <iostream>
#include <string>
#include <list>
# define _BLUE "\033[0;34m"
# define _BLACK "\033[0m"
# define _CYAN "\033[0;36m"
#define _GREEN "\033[1m\033[32m"
#define _RED "\033[1m\033[31m"

int printheader(std::string container)
{
    for (int i = 0; i < ( 90); i++)
        std::cout  << "*";
    std::cout << std::endl;
    for (int a = 0; a < 35; a++)
        std::cout << " ";
    std::cout << "\033[1;34m" << "testeur: "  << container << _BLACK << std::endl;
    for (int c = 0; c < ( 90); c++)
        std::cout << "*";
    std::cout << std::endl;
    return 0;
}

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

void print_vector_std(std::vector<int> vec)
{
    if (vec.empty())
        std::cout << _CYAN << "namespace STD -> " << _BLACK << "Empty vector" << std::endl;
    else
    {
        std::vector<int>::iterator it = vec.begin();
        std::vector<int>::iterator ite = vec.end();
        std::cout << _CYAN << "namespace STD ->" << _BLACK << "Size = " << vec.size() << std::endl;
        std::cout << _CYAN << "namespace STD -> " << _BLACK << "Capacity = " << vec.capacity() << std::endl;
        for (; it != ite; it++)
            std::cout << *it << " | ";
        std::cout << std::endl;
    }
}

void testerVectorConstructors()
{
    std::cout << _GREEN << "                                     CONSTRUCTORS                 " << _BLACK << std::endl;
    
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
    std::cout << std::endl;
    if (vec.size() == vect.size())
        std::cout << _GREEN << "OK ✅" << _BLACK << std::endl;
    else
        std::cout << "KO ❌" << std::endl;
    std::cout << std::endl;
    print_vector_ft(vec2);
    print_vector_std(vect2);
    std::cout << std::endl;
    if (vec2.size() == vect2.size())
        std::cout << _GREEN << "OK ✅" << _BLACK << std::endl;
    else
        std::cout << _RED << "KO ❌" << _BLACK << std::endl;
    std::cout << std::endl;
    print_vector_ft(vec3);
    print_vector_std(vect3);
    std::cout << std::endl;
    if (vec3.size() == vect3.size())
        std::cout << _GREEN << "OK ✅" << _BLACK << std::endl;
    else
        std::cout << _GREEN << "KO ❌" << _BLACK << std::endl;
}

void testerVectorOperator()
{
    std::cout << _GREEN << "                                     OPERATOR =                 " << _BLACK << std::endl;
    
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

    std::cout << std::endl;
    if (vec2.size() == vect2.size())
        std::cout << _GREEN << "OK ✅" << _BLACK << std::endl;
    else
        std::cout << _GREEN << "KO ❌" << _BLACK << std::endl;
}

void testerVectorIterator()
{
    std::cout << _GREEN << "                                     ITERATORS                 " << _BLACK << std::endl;
    std::cout << _BLUE << "function begin()" << _BLACK << std::endl;
    ft::vector<int> vec;
    std::vector<int> vect;
    for (int i = 0; i < 10 ; i++)
        vec.push_back(i);
    for (int i = 0; i < 10 ; i++)
        vect.push_back(i);
    print_vector_ft(vec);
    print_vector_std(vect);

}

int main(void)
{
    printheader("VECTOR");
    testerVectorConstructors();
    testerVectorOperator();
    testerVectorIterator();

    printheader("MAP");
    printheader("STACK");
    
}