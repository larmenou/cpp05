/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:43:51 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/29 10:09:54 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		AForm *shrub = new ShrubberyCreationForm("");
		try
		{
			Bureaucrat a("Alice", 130);
			std::cout << a << std::endl;
			std::cout << *shrub << std::endl;
			
			a.signForm(*shrub);
			std::cout << *shrub << std::endl;

			a.executeForm(*shrub);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete shrub;
	}
	
	std::cout << std::endl;
	
	{
		AForm *shrub = new ShrubberyCreationForm("home");
		try
		{
			Bureaucrat a("Alice", 150);
			std::cout << a << std::endl;
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
		delete shrub;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	{
		AForm *robot = new RobotomyRequestForm("Bob");
		try
		{
			Bureaucrat a("Alice", 40);
			std::cout << a << std::endl;
			std::cout << *robot << std::endl;
			
			a.signForm(*robot);
			std::cout << *robot << std::endl;

			a.executeForm(*robot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete robot;
	}

	std::cout << std::endl;
	
	{
		AForm *robot = new RobotomyRequestForm("Bob");
		try
		{
			Bureaucrat a("Alice", 65);
			std::cout << a << std::endl;
			std::cout << *robot << std::endl;
			
			a.signForm(*robot);
			std::cout << *robot << std::endl;

			a.executeForm(*robot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete robot;
	}

	std::cout << std::endl;

	{
		AForm *robot = new RobotomyRequestForm("Bob");
		try
		{
			Bureaucrat a("Alice", 1);
			std::cout << a << std::endl;
			std::cout << *robot << std::endl;

			a.executeForm(*robot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete robot;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	{
		AForm *pardon = new PresidentialPardonForm("Charlie");
		try
		{
			Bureaucrat a("Alice", 1);
			std::cout << a << std::endl;
			std::cout << *pardon << std::endl;
			
			a.signForm(*pardon);
			std::cout << *pardon << std::endl;

			a.executeForm(*pardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pardon;
	}

	std::cout << std::endl;
	
	{
		AForm *pardon = new PresidentialPardonForm("Bob");
		try
		{
			Bureaucrat a("Alice", 65);
			std::cout << a << std::endl;
			std::cout << *pardon << std::endl;
			
			a.signForm(*pardon);
			std::cout << *pardon << std::endl;

			a.executeForm(*pardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete pardon;
	}
	
	return (0);
}