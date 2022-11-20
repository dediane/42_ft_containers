/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:25:20 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/21 00:52:41 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_tester.hpp"
#include "vector_tester.hpp"

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
    std::cout << _BLUE << "namespace FT : " << _BLACK << std::endl;

    if (stack.empty())
        std::cout << "Empty stack";
    else
        print_stack_ft(stack);
    std::cout << std::endl << std::endl;
}

void print_std(std::stack<int> stack)
{
    std::cout << _BBLUE << "namespace STD : " << _BLACK << std::endl;
    if (stack.empty())
        std::cout << "Empty stack";
    else
        print_stack_std(stack);
    std::cout << std::endl << std::endl;
}

void stack_constructor_tester()
{
    std::cout << std::endl << _GREEN << "                                     CONSTRUCTORS                     " << _BLACK << std::endl;
    
    ft::stack<int> a;
    for (int i = 0; i < 10; i++){a.push(i);}
    ft::stack<int> b(a);
    ft::stack<int> c = b;


    std::stack<int> A;
    for (int i = 0; i < 10; i++){A.push(i);}
    std::stack<int> B(A);
    std::stack<int> C = B;

    std::cout << "Testing basic constructor:";
    a.size() == A.size() ? printresult(1) : printresult(2);
    std::cout << "Testing copy constructor:";
    b.size() == B.size() ? printresult(1) : printresult(2);
    std::cout << "Testing copy constructor:";
    c.size() == C.size() ? printresult(1) : printresult(2);
}

void stack_empty_tester()
{
    std::cout << std::endl << _GREEN << "                                     EMPTY                     " << _BLACK << std::endl;
    ft::stack<int> a;
    std::stack<int> A;

    print_ft(a);
    print_std(A);
    a.empty() == A.empty() ? printresult(1) : printresult(2);
    std::cout << std::endl;
    for (int i = 0; i < 10; i++){a.push(i);}
    for (int i = 0; i < 10; i++){A.push(i);}
    print_ft(a);
    print_std(A);
    a.empty() == A.empty() ? printresult(1) : printresult(2);
    std::cout << std::endl;
}

void stack_size_tester()
{
    std::cout << std::endl << _GREEN << "                                     SIZE                     " << _BLACK << std::endl;
    ft::stack<int> a;
    std::stack<int> A;

    print_ft(a);
    print_std(A);
    std::cout << "size de a = " << a.size() << std::endl;
    std::cout << "size de A = " << A.size() << std::endl;
    a.size() == A.size() ? printresult(1) : printresult(2);
    std::cout << std::endl;
    for (int i = 0; i < 10; i++){a.push(i);}
    for (int i = 0; i < 10; i++){A.push(i);}
    print_ft(a);
    print_std(A);
    std::cout << "size de a = " << a.size() << std::endl;
    std::cout << "size de A = " << A.size() << std::endl;
    a.size() == A.size() ? printresult(1) : printresult(2);
    std::cout << std::endl;
}

void stack_top_tester()
{
    std::cout << std::endl << _GREEN << "                                     TOP                     " << _BLACK << std::endl;
    ft::stack<int> a;
    std::stack<int> A;
    for (int i = 0; i < 100; i++){a.push(i);}
    for (int i = 0; i < 100; i++){A.push(i);}
    std::cout << "top de a = " << a.top() << std::endl;
    std::cout << "top de A = " << A.top() << std::endl;
    a.top() == A.top() ? printresult(1) : printresult(0);
    
    a.top() -= 50;
    A.top() -= 50;
    std::cout << "top de a = " << a.top() << std::endl;
    std::cout << "top de A = " << A.top() << std::endl;
    a.top() == A.top() ? printresult(1) : printresult(0);
}

void stack_push_pop_tester()
{
    std::cout << std::endl << _GREEN << "                                    PUSH & POP                     " << _BLACK << std::endl;
    ft::stack<int> a;
    std::stack<int> A;
    for (int i = 0; i < 100; i++){a.push(i);}
    for (int i = 0; i < 100; i++){A.push(i);}
    a.size() == A.size() ? printresult(1) : printresult(0);
    for (int i = 0; i < 100; i++){a.pop();}
    for (int i = 0; i < 100; i++){A.pop();}
    a.size() == A.size() ? printresult(1) : printresult(0);
}

void stack_operator_tester()
{
    std::cout << std::endl << _GREEN << "                                    RELATIONAL OPERATOR                     " << _BLACK << std::endl;
    ft::stack<int> a;
    std::stack<int> A;
    ft::stack<int> b;
    std::stack<int> B;
    for (int i = 0; i < 100; i++){a.push(i);}
    for (int i = 0; i < 100; i++){A.push(i);}
    for (int i = 0; i < 10; i++){b.push(i);}
    for (int i = 0; i < 10; i++){B.push(i);}
    
    int res_ft = 0;
    int res_std = 0;
    if (a == b)
        res_ft = 1;
    if (A == B)
        res_std = 1;
    std::cout << "test == : " << std::endl;
    res_ft == res_std ? printresult(1) : printresult(0);
    
    res_ft = 0;
    res_std = 0;
    if (a > b)
        res_ft = 1;
    if (A > B)
        res_std = 1;
    std::cout << "test > : " << std::endl;
    res_ft == res_std ? printresult(1) : printresult(0);
    
    res_ft = 0;
    res_std = 0;
    if (a < b)
        res_ft = 1;
    if (A < B)
        res_std = 1;
    std::cout << "test < : " << std::endl;
    res_ft == res_std ? printresult(1) : printresult(0);
    
    res_ft = 0;
    res_std = 0;
    if (a <= b)
        res_ft = 1;
    if (A <= B)
        res_std = 1;
    std::cout << "test <= : " << std::endl;
    res_ft == res_std ? printresult(1) : printresult(0);
    
    res_ft = 0;
    res_std = 0;
    if (a >= b)
        res_ft = 1;
    if (A >= B)
        res_std = 1;
    std::cout << "test >= : " << std::endl;
    res_ft == res_std ? printresult(1) : printresult(0);
    
    res_ft = 0;
    res_std = 0;
    if (a != b)
        res_ft = 1;
    if (A != B)
        res_std = 1;
    std::cout << "test != : " << std::endl;
    res_ft == res_std ? printresult(1) : printresult(0);
}

void testerStack()
{
    stack_constructor_tester();
    stack_empty_tester();
    stack_size_tester();
    stack_top_tester();
    stack_push_pop_tester();
    stack_operator_tester();
}