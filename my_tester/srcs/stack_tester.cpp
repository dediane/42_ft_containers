/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:25:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/18 17:26:50 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_tester.hpp"

void print_stack_ft(ft::stack<int> stack)
{
    if (stack.empty())
    {        
        return;
    }
    else
    {
        int x = stack.top();
        stack.pop();
        std::cout << x << " | ";
        print_stack_ft(stack);
        stack.push(x);
    }
}

void print_stack_std(std::stack<int> stack)
{
    if (stack.empty())
    {        
        return;
    }
    else
    {
        int x = stack.top();
        stack.pop();
        std::cout << x << " | ";
        print_stack_std(stack);
        stack.push(x);
    }
}

void print_ft(ft::stack<int> stack)
{
    std::cout << "NAMESPACE FT:" << std::endl;
    if (stack.empty())
        std::cout << "Empty stack";
    else
        print_stack_ft(stack);
    std::cout << std::endl << std::endl;
}

void print_std(std::stack<int> stack)
{
    std::cout << "NAMESPACE STD:" << std::endl;
    if (stack.empty())
        std::cout << "Empty stack";
    else
        print_stack_std(stack);
    std::cout << std::endl << std::endl;
}

void stack_constructor_tester()
{
    std::cout << _BBLUE << "** constructors **" << _BLACK << std::endl << std::endl;
    
    ft::stack<int> a;
    ft::stack<int> b();
    ft::stack<int> c();
    ft::stack<int> d();

    std::stack<int> A;
    std::stack<int> B;
    std::stack<int> C;
    std::stack<int> D;


    
}

void testerStack()
{
    stack_constructor_tester();
    // stack_operator_tester();
    // stack_iterator_test();
    // stack_max_capacity();
    // stack_element_access();
    // stack_modifiers();
}