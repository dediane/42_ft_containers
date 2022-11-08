/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:39:32 by ddecourt          #+#    #+#             */
/*   Updated: 2022/11/08 17:07:17 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTER_HPP
#define MAP_TESTER_HPP

#include "../../includes/map.hpp"
#include <map>

#include <iostream>
#include <string>
#include <list>
# define _BLUE "\033[0;34m"
# define _BLACK "\033[0m"
# define _CYAN "\033[0;36m"
# define _GREEN "\033[1m\033[32m"
# define _RED "\033[1m\033[31m"
# define _BBLUE "\033[1;34m"

#define T1 char
#define T2 int

void    print_map_ft(ft::map<T1, T2> map);
void    print_map_std(std::map<T1, T2> map);
void map_constructor_tester();
void testerMap();

#endif