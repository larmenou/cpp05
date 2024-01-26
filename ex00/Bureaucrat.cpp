/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:04:02 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 10:23:30 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw(GradeTooHighException());
	else if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy) : _name(copy._name), _grade(copy._grade)
{}

Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& copy)
{
	this->_grade = copy._grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::increment(int i)
{
	if (this->_grade - i < 1)
		throw(GradeTooHighException());
	else
		this->_grade -= i;
}

void Bureaucrat::decrement(int i)
{
	if (this->_grade + i > 150)
		throw(GradeTooLowException());
	else
		this->_grade += i;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
