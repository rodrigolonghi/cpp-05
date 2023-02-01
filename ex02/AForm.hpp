#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const short			gradeToSign;
		const short			gradeToExecute;

	public:
		AForm();
		virtual ~AForm();
		AForm(AForm const &src);
		AForm(std::string name, short gradeToSign, short gradeToExec);
		AForm	&operator=(AForm const &src);

		std::string	getName() const;
		bool		getIsSigned() const;
		short		getGradeToSign() const;
		short		getGradeToExecute() const;

		void	setName(std::string name);
		void	setIsSigned(bool sign);
		void	setGradeToSign(short n);
		void	setGradeToExecute(short n);

		void			beSigned(Bureaucrat const &b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm const &f);

#endif
