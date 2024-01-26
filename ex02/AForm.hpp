/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm
{
	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExec);
		AForm(AForm const& copy);
		virtual ~AForm();
		AForm& operator=(AForm const& copy);

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(Bureaucrat& b);
		void virtual execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			const char * what() const throw()
			{
				return ("AForm::GradeTooHighException: Grade Too High ! Value must be include between 1 & 150");
			}
		};

		class GradeTooLowException : public std::exception
		{
			const char * what() const throw()
			{
				return ("AForm::GradeTooLowException: Grade Too Low !");
			}
		};
	
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
