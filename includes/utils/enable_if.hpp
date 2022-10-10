/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:46:21 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/10 18:23:34 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {

	template <bool B, class T = void> 
		struct enable_if {};

	template <class T> struct enable_if<true, T> 
	{ 
		typedef T type; 
	};
};

#endif