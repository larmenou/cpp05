/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:19:17 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/29 11:09:58 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const& copy)
{
	(void) copy;
}

Intern& Intern::operator=(Intern const& copy)
{
	(void) copy;
	return (*this);
}

Intern::~Intern()
{}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int i;

	i = 0;
	std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	while (i < 3)
	{
		if (name == tab[i])
			break;
		i++;
	}
	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << name << std ::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << name << std ::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << name << std ::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Intern cannot creates this form." << std ::endl;
			return (NULL);
	}
	
}