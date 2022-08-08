/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/08 12:09:38 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main(void)
{
	/* Create mstack/list to check if they work the same */
	MutantStack<int>			mstack;
	std::list<int>				list;

	/* Push the same numbers on stack & list and print the top */
	mstack.push(5);
	mstack.push(17);
	list.push_back(5);
	list.push_back(17);
	
	std::cout << "Top for MutantStack & List must be 17:" << std::endl;
	std::cout << "MutantStack: " << mstack.top() << std::endl;
	std::cout << "List: " << list.back() << std::endl;
	std::cout << "\n-------------------------------\n";
	
	/* Pop last elements of the stack */
	mstack.pop();
	list.pop_back();

	std::cout << "After popping last element both sizes should be 1:" << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << std::endl;
	std::cout << "List size: " << list.size() << std::endl;
	std::cout << "\n-------------------------------\n";

	/* Push more elements into both stack/list */
	mstack.push(3);
	mstack.push(9);
	mstack.push(737);
	mstack.push(0);
	list.push_back(3);
	list.push_back(9);
	list.push_back(737);
	list.push_back(0);
	
	/* Create iterators for both and show the elements */
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	std::list<int>::iterator	listIt = list.begin();
	std::list<int>::iterator	listIte = list.end();

	++it;
	--it;
	
	std::cout << "MutantStack Elements:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it; 
	}
	std::cout << "\n-------------------------------\n";

	std::cout << "List Elements:" << std::endl;
	while (listIt != listIte)
	{
		std::cout << *listIt << std::endl;
		++listIt; 
	}
	std::cout << "\n-------------------------------\n";
	
	/* Create a stack from mutant stack */
	std::stack<int> s(mstack);
	std::cout << "Top is (last push) --> " << s.top() << ", and size is --> " << s.size() << std::endl;
	std::cout << "\n-------------------------------\n";

	/* Test with empty stack/list */
	MutantStack<int>	msEmpty;
	std::list<int>		lsEmpty;

	std::cout << "MutantStack Empty is (1 true / 0 false): " << msEmpty.empty() << std::endl;
	std::cout << "List Empty is (1 true / 0 false): " << lsEmpty.empty() << std::endl;
	std::cout << "\n-------------------------------\n";

	/* Also works with string stacks */
	MutantStack<std::string>	str1;
	MutantStack<std::string>	str2;

	str1.push("Tired of");
	str1.push("This tests!!");
	str1.push("Kill me!");

	std::cout << "size of str2 should be 0 ---> " << str2.size() << std::endl;
	str2 = str1;
	std::cout << "size of str2 should be 3 ---> " << str2.size() << std::endl;

	return (0);
}
