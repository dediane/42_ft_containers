/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:44:57 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/07 23:06:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTER_HPP
#define VECTOR_TESTER_HPP

#include "../../includes/vector.hpp"
#include <vector>

#include <iostream>
#include <string>
#include <list>
# define _BLUE "\033[0;34m"
# define _BLACK "\033[0m"
# define _CYAN "\033[0;36m"
# define _GREEN "\033[1m\033[32m"
# define _RED "\033[1m\033[31m"
# define _BBLUE "\033[1;34m"

int     printheader(std::string container);
void    printresult(int i);
void    print_vector_ft(ft::vector<int> vec);
void    print_vector_std(std::vector<int> vec);
void    testerVectorConstructors();
void    testerVectorOperator();
void    testerVectorIterator();
void    testerVectorCapacity();
void    testerVectorElementAccess();
void    testerVectorModifier();
void    testerVector();




#endif