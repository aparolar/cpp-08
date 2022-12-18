/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:43:04 by aparolar          #+#    #+#             */
/*   Updated: 2022/12/18 11:21:27 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
	: _length(0)
{}

Span::Span(Span const &toCopy)
{
	*this = toCopy;
}

Span::Span(unsigned int N)
	: _length(N) {}

Span::~Span() {}

Span& Span::operator=(Span const &toCopy)
{
	this->_length = toCopy._length;
	this->_vector = toCopy._vector;
	return *this;
}

unsigned int Span::getLength(void) const
{
	return (_length);
}

std::vector<int> Span::getVector(void) const
{
	return (_vector);
}

void Span::addNumber(int n)
{
	if (_vector.size() >= _length)
		throw SpanFull();
	_vector.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int		spaceLeft;
	std::vector<int>	tmp(begin, end);

	spaceLeft = _length - static_cast<int>(_vector.size());
	if (tmp.size() > spaceLeft)
		throw NotEnoughSpace();
	copy(tmp.begin(), tmp.end(), std::back_inserter(_vector));
}

int Span::shortestSpan(void)
{
	int min;
	int minIndex;
	int secondMin;

	if (_length <= 1 || _vector.size() <= 1)
		throw NoSpan();
	min = *std::min_element(_vector.begin(), _vector.end());
	minIndex = std::min_element(_vector.begin(), _vector.end()) - _vector.begin();
	_vector[minIndex] = INT_MAX;
	secondMin = *std::min_element(_vector.begin(), _vector.end());
	_vector[minIndex] = min;
	return (secondMin - min);
}

int Span::longestSpan(void)
{
	int min;
	int max;

	if (_length <= 1 || _vector.size() <= 1)
		throw NoSpan();
	min = *std::min_element(_vector.begin(), _vector.end());
	max = *std::max_element(_vector.begin(), _vector.end());
	return (max - min);
}

const char *Span::SpanFull::what() const throw()
{
	return ("Error: can't add more numbers");
}

const char *Span::NoSpan::what() const throw()
{
	return ("Error: there's not enough numbers to find span");
}

const char *Span::NotEnoughSpace::what() const throw()
{
	return ("Error: there's not enough space for the range");
}
