#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const short			gradeToSign;
		const short			gradeToExecute;

	public:
		Form();
		~Form();
		Form(Form const &src);
		Form(std::string name, short gradeToSign, short gradeToExecute);
		Form &operator=(Form const &rhs);

		std::string	getName() const;
		bool		getIsSigned() const;
		short		getGradeToSign() const;
		short		getGradeToExecute() const;

		void	beSigned(Bureaucrat const &b);

	class GradeTooHighException : public std::exception {
		const char * what () const throw ();
	};
	class GradeTooLowException : public std::exception {
		const char * what () const throw ();
	};
};

std::ostream	&operator<<(std::ostream &o, Form const &b);

#endif
