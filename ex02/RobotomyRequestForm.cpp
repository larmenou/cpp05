/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:49:23 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/29 10:12:57 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& copy)
{
	(void) copy;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() <= this->getGradeToExec())
		{
			std::srand(std::time(0));
			if (std::rand() % 2)
			{
				std::cout << "* Some drilling noises *" << std::endl;
				std::cout << "* More drilling noises *" << std::endl;
				std::cout << "* ... *" << std::endl;
				std::cout << "Congratulations " << this->_target << ", you have been robotomized successfully !" << std::endl;
			}
			else
			{
				std::cout << "* Some drilling noises *" << std::endl;
				std::cout << "* ... *" << std::endl;
				std::cout << "Robotomization failed for " << this->_target << ", see you next time." << std::endl;
			}
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