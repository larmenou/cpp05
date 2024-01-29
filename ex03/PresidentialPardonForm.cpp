/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:21:58 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/29 10:13:47 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& copy)
{
	(void) copy;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() <= this->getGradeToExec())
		{
			std::cout << this->_target << ", you have been pardoned by the Great Zaphod Beeblebrox." << std::endl;
		}
		else
		{
			std::cout << executor.getName() << " couldn't execute " << this->getName() << " because ";
			throw (GradeTooLowException());
		}
	}
	else
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because the form is not signed." << std::endl;
}