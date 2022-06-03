/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:54:53 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/03 23:05:18 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
    template<typename T>
    class random_access_iterator
    {
        public:
            typedef T value_type;
            typedef value_type &reference;
            typedef const value_type &const_reference;
            typedef value_type *pointer;
            typedef const value_type *const_pointer;
            typedef std::ptrdiff_t difference_type;
            typedef std::random_access_iterator_tag iterator_category;
    
            random_access_iterator() : _ptr(NULL){}
            random_access_iterator(const random_access_iterator &rhs){*this = rhs}
            random_access_iterator(pointer ptr) : _ptr(ptr) {}
            ~random_access_iterator(){}

    };
}

#endif