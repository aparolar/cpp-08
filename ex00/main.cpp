/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/08 10:57:39 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <list>

template <typename T>
void test(T &container, int n)
{
	if (easyfind(container, n))
		std::cout << "The number " << n << " is in the container" << std::endl;
	else
		std::cout << "The number " << n << " is not in the container" << std::endl;
}

int main(void)
{
	std::cout << "------ TEST VECTOR ------" << std::endl;

	std::vector<int> v;

	for (int i = 0; i < 100; i++)
		v.push_back(i * 2);

	test(v, 3);
	test(v, 32);
	test(v, 48);
	test(v, -42);

	std::cout << "------ TEST LIST ------" << std::endl;

	std::list<int> l;

	for (int i = 0; i < 100; i++)
		l.push_back(i * 2);

	test(l, 1);
	test(l, 32);
	test(l, 48);
	test(l, -42);

	return (0);
}
