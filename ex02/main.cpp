/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:43:51 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 15:28:36 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 130);
		std::cout << a << std::endl;
		AForm *shrub = new ShrubberyCreationForm("");
		std::cout << *shrub << std::endl;
		
		a.signForm(*shrub);
		std::cout << *shrub << std::endl;

		a.executeForm(*shrub);

		delete shrub;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat a("Alice", 150);
		std::cout << a << std::endl;
		AForm *shrub = new ShrubberyCreationForm("home");
		std::cout << *shrub << std::endl;
		
		a.signForm(*shrub);
		std::cout << *shrub << std::endl;

		a.executeForm(*shrub);

		delete shrub;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	try
	{
		Bureaucrat a("Alice", 40);
		std::cout << a << std::endl;
		AForm *robot = new RobotomyRequestForm("Bob");
		std::cout << *robot << std::endl;
		
		a.signForm(*robot);
		std::cout << *robot << std::endl;

		a.executeForm(*robot);

		delete robot;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat a("Alice", 65);
		std::cout << a << std::endl;
		AForm *robot = new RobotomyRequestForm("Bob");
		std::cout << *robot << std::endl;
		
		a.signForm(*robot);
		std::cout << *robot << std::endl;

		a.executeForm(*robot);

		delete robot;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;
		AForm *robot = new RobotomyRequestForm("Bob");
		std::cout << *robot << std::endl;

		a.executeForm(*robot);

		delete robot;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;
		AForm *pardon = new PresidentialPardonForm("Charlie");
		std::cout << *pardon << std::endl;
		
		a.signForm(*pardon);
		std::cout << *pardon << std::endl;

		a.executeForm(*pardon);

		delete pardon;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat a("Alice", 65);
		std::cout << a << std::endl;
		AForm *pardon = new PresidentialPardonForm("Bob");
		std::cout << *pardon << std::endl;
		
		a.signForm(*pardon);
		std::cout << *pardon << std::endl;

		a.executeForm(*pardon);

		delete pardon;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}