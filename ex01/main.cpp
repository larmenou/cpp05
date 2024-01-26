/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:03:57 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 11:47:39 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Bob", -42);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;
		a.increment(-5);
		std::cout << a << std::endl;
		a.decrement(100);
		std::cout << a << std::endl;
		a.increment(200);
		std::cout << a << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat c("Charlie", 190);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	try
	{
		Bureaucrat a("Alice", 42);
		Form b28("b28", 50, 100);
		std::cout << a << b28 << std::endl;
		a.signForm(b28);
		a.signForm(b28);
		std::cout << a << b28 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat e;
		Form a38("a38", 1, 10);
		std::cout << e << a38 << std::endl;
		e.signForm(a38);
		std::cout << e << a38 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form bleu("bleu", 200, 5);
		std::cout << bleu << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form marron("marron", 2, 0);
		std::cout << marron << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}