/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/08 12:02:45 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <stdlib.h>

int main(void)
{
	{		
		srand(time(NULL));
		std::cout << "Try with 5 numbers and get Span:" << std::endl;
		
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(17);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-------------------------------\n" << std::endl;
		std::cout << "Try to add more numbers to throw exception:" << std::endl;
		try
		{
			sp.addNumber(56);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
		std::cout << "-------------------------------\n" << std::endl;
	{
		std::cout << "Try with 1000 numbers and get Span:" << std::endl;
		Span sp2 = Span(1000);
		for (int i = 0; i < 1000; i++)
    		sp2.addNumber(rand()%1000000);
		
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
		std::cout << "-------------------------------\n" << std::endl;
	{
		std::cout << "Try with 100000 numbers and get Span:" << std::endl;
		Span sp3 = Span(100000);
		for (int i = 0; i < 100000; i++)
    		sp3.addNumber(rand()%1000000);
		
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
		std::cout << "-------------------------------\n" << std::endl;
	{
		std::cout << "Try with no elements to throw exceptions:" << std::endl;
		Span sp4 = Span(5);

		try
		{
			std::cout << sp4.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "-------------------------------\n" << std::endl;
		std::cout << "Try with 1 element to throw exceptions:" << std::endl;
		sp4.addNumber(42);
		try
		{
			std::cout << sp4.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
		std::cout << "-------------------------------\n" << std::endl;
	{
		std::cout << "Try to add range of elements:" << std::endl;
		Span sp5(100);
		std::vector<int>	v;

		v.push_back(25);
		v.push_back(5);
		v.push_back(12);
		v.push_back(90);
		v.push_back(-2);

		sp5.addRange(v.begin(), v.end());
		std::cout << sp5.shortestSpan() << std::endl;
		std::cout << sp5.longestSpan() << std::endl;

		std::cout << "-------------------------------\n" << std::endl;
		std::cout << "Try to add bigger range than space:" << std::endl;
		for (int i = 0; i < 120; i++)
    		v.push_back(rand()%10000);
		try
		{
			sp5.addRange(v.begin(), v.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}	
	return (0);
}
