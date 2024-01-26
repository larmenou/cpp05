/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:03:59 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 15:18:22 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(Bureaucrat const& copy);
		~Bureaucrat();
		Bureaucrat& operator=(Bureaucrat const& copy);

		const std::string getName() const;
		int getGrade() const;
		
		void increment(int i);
		void decrement(int i);
		void signForm(AForm& f);
		void executeForm(AForm const& form);

		class GradeTooHighException : public std::exception
		{
			const char * what() const throw()
			{
				return ("Bureaucrat::GradeTooHighException: Grade Too High ! Value must be include between 1 & 150");
			}
		};

		class GradeTooLowException : public std::exception
		{
			const char * what() const throw()
			{
				return ("Bureaucrat::GradeTooLowException: Grade Too Low ! Value must be include between 1 & 150");
			}
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);