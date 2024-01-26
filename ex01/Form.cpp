/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:02:42 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 12:45:36 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	_isSigned = false;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw(GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw(GradeTooLowException());
}

Form::Form(Form const& copy) :
	_name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	this->_isSigned = copy._isSigned;
}

Form::~Form()
{}

Form& Form::operator=(Form const& copy)
{
	(void) copy;
	return (*this);
}

// GETTERS

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

//###########

/* void Form::beSigned(Bureaucrat& b)
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
} */

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form name :" << f.getName() << ", Grade require for Execute: " << f.getGradeToExec();
	os << ", Grade require for Sign: " << f.getGradeToSign() << ", is signed ? " << f.getIsSigned() << ".";
	return (os);
}