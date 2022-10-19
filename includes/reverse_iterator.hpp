/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:00:35 by ddecourt          #+#    #+#             */
/*   Updated: 2022/10/19 15:41:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"
#include <memory>

namespace ft
{
	template<typename Iterator>
	class reverse_iterator
	{
		private:
			Iterator _iter;

		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			
			reverse_iterator() : _iter(NULL){};
			explicit reverse_iterator(iterator_type type) : _iter(type) {};
			~reverse_iterator() {}
			
			template<class Iter>
			reverse_iterator (const reverse_iterator<Iter> &reverse_iterator) : _iter(reverse_iterator.base()){};
			
			operator reverse_iterator<random_access_iterator<value_type const> > () const { return reverse_iterator<random_access_iterator<value_type const> >(_iter);}
			operator reverse_iterator<random_access_iterator<value_type > > () { return reverse_iterator<random_access_iterator<value_type> >(_iter);}

			iterator_type base() const {return(_iter);};
			
			reference			operator*() const {Iterator i = _iter; return (*--i);};
			pointer				operator->() const {return &(operator*());};
			
			reverse_iterator	&operator=(reverse_iterator const &lhs)
			{
				if (*this == lhs)
					return *this;
				_iter = lhs._iter;
				return *this;
			};
			reverse_iterator	&operator++() {_iter--; return (*this);};
			reverse_iterator	&operator--() {_iter++; return (*this);};
			reverse_iterator	operator++(int) {reverse_iterator i = *this; _iter--; return(i);};
			reverse_iterator	operator--(int) {reverse_iterator i = *this; _iter++; return(i);};
			reverse_iterator	operator+(difference_type n) const {return (reverse_iterator(base() - n));};
			reverse_iterator	operator-(difference_type n) const {return (reverse_iterator(base() + n));};
			reverse_iterator	&operator+=(difference_type n) {_iter -= n; return(*this);};
			reverse_iterator	&operator-=(difference_type n) {_iter += n; return(*this);};
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
		return !(lhs.base() > rhs.base()) && !(lhs.base() == rhs.base() );
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

	template <typename T1, typename T2>
	typename reverse_iterator<T1>::difference_type 
	operator- (const reverse_iterator<T1> & lhs, const reverse_iterator<T2> & rhs)
	{
			return rhs.base() - lhs.base();
	}
}

#endif