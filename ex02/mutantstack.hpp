/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:04:50 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/08 12:13:56 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
#include <list>
#include <string>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		typedef typename std::deque<T>::iterator iterator;

		MutantStack();
		~MutantStack();
		
		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };
};

template <typename T>

MutantStack<T>::MutantStack() {}

template <typename T>

MutantStack<T>::~MutantStack() {}

#endif
