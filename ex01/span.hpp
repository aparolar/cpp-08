/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:43:11 by aparolar          #+#    #+#             */
/*   Updated: 2022/12/18 11:17:45 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

class Span
{
	private:
		std::vector<int> _vector;
		unsigned int _length;

	public:
		Span();
		Span(Span const &toCopy);
		Span(unsigned int N);
		~Span();

		Span& operator=(Span const &toCopy);

		std::vector<int> getVector() const;
		unsigned int getLength() const;
		void addNumber(int n);
		void addRange(std::vector<int>::iterator begin,	std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		class SpanFull : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class NoSpan : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NotEnoughSpace : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
};

#endif
