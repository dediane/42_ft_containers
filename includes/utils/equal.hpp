/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:46:32 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/21 17:32:41 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

//https://cplusplus.com/reference/algorithm/equal/
namespace ft{

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 ) 
{
	while (first1!=last1) {
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
	}
	return true;
}
}

#endif