/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_Iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:00:35 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/22 00:38:01 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <memory>

namespace ft
{
	template<typename Iterator>
	class reverse_iterator
	{
		private:
			Iterator _iter;

		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			
			reverse_iterator() : _iter(NULL){};
			explicit reverse_iterator(iterator_type type) : _iter(type) {};
			
			template<class Iter>
			reverse_iterator (const reverse_iterator<Iter> &reverse_iterator) : _iter(reverse_iterator.base()){};
			
			iterator_type base() const {return(_iter);};
			
			reference			operator*() const {Iterator i = _iter; return (*--i);};
			pointer				operator->() const {return (std::addressof(operator*()));};
			reverse_iterator	&operator++() const {--_iter; return (*this);};
			reverse_iterator	&operator--() const {++_iter; return (*this);};
			reverse_iterator	operator++(int) const {reverse_iterator i = *this; --(*this); return(i);};
			reverse_iterator	operator--(int) const {reverse_iterator i = *this; ++(*this); return(i);};
			reverse_iterator	operator+(difference_type n) const {return (reverse_iterator(base() - n));};
			reverse_iterator	operator-(difference_type n) const {return (reverse_iterator(base() + n));};
			reverse_iterator	&operator+=(difference_type n) const {_iter -= n; return(*this);};
			reverse_iterator	&operator-=(difference_type n) const {_iter += n; return(*this);};
			reference			operator[](difference_type n) const {return (base()[-n -1]);};
			
	};
			
			
		template <typename T1, typename T2>
	bool operator==(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs) 
	{
		return lhs.base() == rhs.base();
	}

	template <typename T1, typename T2>
	bool operator!=(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename T1, typename T2>
	bool operator<(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename T1, typename T2>
	bool operator<=(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename T1, typename T2>
	bool operator>(const reverse_iterator<T1> &lhs, const
	reverse_iterator<T2> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename T1, typename T2>
	bool operator>=(const reverse_iterator<T1> &lhs, const
	reverse_iterator<T2> &rhs)
	{
		return lhs.base() <= rhs.base();
	}
	
	template <class Iterator>
	reverse_iterator<Iterator>operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
			return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
			return lhs.base() - rhs.base();
	}
}

#endif