#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string	const	name;
		short				grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat(std::string name, short grade);
		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string	getName() const;
		short		getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &f);

	class GradeTooHighException : public std::exception {
		const char * what () const throw ();
	};
	class GradeTooLowException : public std::exception {
		const char * what () const throw ();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b);

#endif
