#include <iostream>
#include <vector>
#include "../../includes/vector.hpp"

void print_line(int res, std::string container_name, std::string test_name)
{
    if (res == 0)
    {
        std::cout << "[\033[1;32m ["<< container_name  << "] \033[0;37m " << test_name  << " [\033[1;32m[V]\033[0;37m";
    }
    else 
    {
        std::cout << "[\033[1;31m ["<< container_name  << "] \033[0;37m " <<  test_name << " [\033[1;31m[X]\033[0;37m";
    }
}

int test_assign()
{
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    ft::vector<int> first_ft;
    ft::vector<int> second_ft;
    ft::vector<int> third_ft;

    // 7 ints with a value of 100
    first.assign (7,100);
    first_ft.assign (7,100);   
             
    std::vector<int>::iterator it;
    ft::vector<int>::iterator it_ft;

    it=first.begin()+1;
    it_ft=first_ft.begin()+1;

    second.assign (it,first.end()-1); // the 5 central values of first
    second_ft.assign (it_ft,first_ft.end()-1);

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.
    third_ft.assign (myints,myints+3);

    int res = 0;
    if ((int (first.size()) == int (first_ft.size())) && (int (second.size()) == int (second_ft.size())) && (int (third.size()) == int (third_ft.size())))
        res = 0;
    else
        res = 1;
     print_line(res, "vector", "assign test n°1");
     return (0);
}

void test_constructor()
{

}

void test_overload_operator()
{

}

void test_iterators_functions()
{

}

void test_capacity_functions()
{

}

void test_element_access()
{

}

void test_assign()
{

}

void test_push_and_popback()
{

}

int main()
{

   
    test_constructor();
    test_overload_operator();
    test_iterators_functions();
    test_capacity_functions();
    test_element_access();
    test_assign();
    test_push_and_popback();
    test_insert();
    test_erase_clear();
    test_operators();
    return (0);
}