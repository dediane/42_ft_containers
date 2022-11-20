/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:30:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/21 00:40:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tester.hpp"
#include "map_tester.hpp"
#include "stack_tester.hpp"
#include <stdio.h>
#include <string.h>

int main(int ac, char**av)
{
    if (ac == 1)
    {
        printheader("VECTOR");
        testerVector();
        printheader("MAP");
        testerMap();
        printheader("STACK");
        testerStack();
    }
    if (av[1] && strcmp(av[1],"vector") == 0)
    {
        printheader("VECTOR");
        testerVector();
    }
    if (av[1] && strcmp(av[1],"map") == 0)
    {
        printheader("MAP");
        testerMap();
    }
    if (av[1] && strcmp(av[1],"stack") == 0)
    {
        printheader("STACK");
        testerStack();
    }
    if (av[1] && strcmp(av[1],"all") == 0)
    {
        printheader("VECTOR");
        testerVector();
        printheader("MAP");
        testerMap();
        printheader("STACK");
        testerStack();
    }

    
}