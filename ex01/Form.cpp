#include "Form.hpp"

Form::Form() : name("Jhonson"), isSigned(false), gradeToSign(42), gradeToExecute(42) {}

Form::Form(Form const &src) :
	name(src.getName()),
	isSigned(src.getIsSigned()),
	gradeToSign(src.getGradeToSign()),
	gradeToExecute(src.getGradeToExecute()) {
	*this = src;
}

Form::Form(std::string name, short gradeToSign, short gradeToExecute) :
	name(name),
	isSigned(false),
	gradeToSign(gradeToSign), 
	gradeToExecute(gradeToExecute) {}

Form::~Form() {}

Form	&Form::operator=(Form const &rhs) {
	this->isSigned = rhs.getIsSigned();
	const_cast<std::string &>(this->name) = rhs.getName();
	const_cast<short &>(this->gradeToSign) = rhs.getGradeToSign();
	const_cast<short &>(this->gradeToExecute) = rhs.getGradeToExecute();
	return *this;
}

std::string	Form::getName() const {
	return this->name;
}

bool	Form::getIsSigned() const {
	return this->isSigned;
}

short	Form::getGradeToSign() const {
	return this->gradeToSign;
}

short	Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void	Form::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->getGradeToSign()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because bureaucrat doesn't have high enough grade.\n";
		throw Form::GradeTooLowException(); 
	}
	this->isSigned = true;
	std::cout << b.getName() << " signed " << this->getName() << ".\n";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

std::ostream	&operator<<(std::ostream &o, Form const &f) {
	o << "Form name = " << f.getName() << "\nRequired Grade to Sign = " << f.getGradeToSign() <<
	"\nRequired Grade to Execute = " << f.getGradeToExecute() << "\nIs Signed = " <<
	(f.getIsSigned() ? "Signed" : "Not Signed") << std::endl;
	return o;
}
