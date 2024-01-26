/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:42:57 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/26 11:36:06 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExec);
		Form(Form const& copy);
		~Form();
		Form& operator=(Form const& copy);

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(Bureaucrat& b);

		struct GradeTooHighException : public std::exception
		{
			const char * what() const throw()
			{
				return ("Form::GradeTooHighException: Grade Too High ! Value must be include between 1 & 150");
			}
		};

		struct GradeTooLowException : public std::exception
		{
			const char * what() const throw()
			{
				return ("Form::GradeTooLowException: Grade Too Low ! Value must be include between 1 & 150");
			}
		};
	
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Form& f);
