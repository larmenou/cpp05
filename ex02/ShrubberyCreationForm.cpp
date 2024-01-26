/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:28:29 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 14:45:26 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	(void) copy;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::ofstream ofs;
	std::string tree = "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _";
	
	if (this->getIsSigned())
	{
		if (executor.getGrade() <= this->getGradeToExec())
		{
			ofs.open((this->_target + "_shrubbery").c_str());
			if (!ofs.is_open())
			{
				std::cerr << "Error while opening shrubbery file." << std::endl;
				return ;
			}
			std::cout << executor.getName() << " execute " << this->getName() << std::endl;
			ofs << tree << std::endl;
			ofs.close();
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
