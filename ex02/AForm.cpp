/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:02:42 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 11:43:56 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	_isSigned = false;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw(GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw(GradeTooLowException());
}

AForm::AForm(AForm const& copy) :
	_name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	this->_isSigned = copy._isSigned;
}

AForm::~AForm()
{}

AForm& AForm::operator=(AForm const& copy)
{
	(void) copy;
	return (*this);
}

// GETTERS

const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

//###########

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->_gradeToSign)
	{
		if (this->_isSigned)
			std::cout << "The form is already signed." << std::endl;
		else
		{
			this->_isSigned = true;
			std::cout << b.getName() << " signed " << this->_name << std::endl;
		}
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->_name << " because ";
		throw (GradeTooLowException());
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm name :" << f.getName() << ", Grade require for Execute: " << f.getGradeToExec();
	os << ", Grade require for Sign: " << f.getGradeToSign() << ", is signed ? " << f.getIsSigned() << ".";
	return (os);
}