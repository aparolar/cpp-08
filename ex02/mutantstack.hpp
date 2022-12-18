/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:04:50 by aparolar          #+#    #+#             */
/*   Updated: 2022/12/18 20:20:08 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		typedef typename std::deque<T>::iterator iterator;

		MutantStack(void);
		MutantStack(MutantStack const &toCopy);
		~MutantStack(void);
		MutantStack &operator = (MutantStack const &toCopy);
		
		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };
};

template <typename T>
MutantStack<T>::MutantStack(void)
{

}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &toCopy)
{
	*this = toCopy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator = (MutantStack const &toCopy)
{
	this->c = toCopy.c;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{

}

#endif
