#include "AForm.hpp"

AForm::AForm() : name("AForm 00"), isSigned(false), gradeToSign(42), gradeToExecute(42) {}

AForm::AForm(AForm const &src) :
	name(src.getName()),
	isSigned(src.getIsSigned()),
	gradeToSign(src.getGradeToSign()),
	gradeToExecute(src.getGradeToExecute()) {
	*this = src;
}

AForm::AForm(std::string name, short gradeToSign, short gradeToExecute) :
	name(name),
	isSigned(false),
	gradeToSign(gradeToSign), 
	gradeToExecute(gradeToExecute) {}

AForm::~AForm() {}

AForm	&AForm::operator=(AForm const &src) {
	this->isSigned = src.getIsSigned();
	const_cast<std::string &>(this->name) = src.getName();
	const_cast<short &>(this->gradeToSign) = src.getGradeToSign();
	const_cast<short &>(this->gradeToExecute) = src.getGradeToExecute();
	return *this;
}

std::string	AForm::getName() const {
	return this->name;
}

bool	AForm::getIsSigned() const {
	return this->isSigned;
}

short	AForm::getGradeToSign() const {
	return this->gradeToSign;
}

short	AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

void	AForm::setIsSigned(bool sign) {
	this->isSigned = sign;
}

void	AForm::setName(std::string name) {
	const_cast<std::string &>(this->name) = name;
}

void	AForm::	setGradeToSign(short n) {
	const_cast<short &>(this->gradeToSign) = n;
}

void	AForm::	setGradeToExecute(short n) {
	const_cast<short &>(this->gradeToExecute) = n;
}

void	AForm::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->getGradeToSign()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because bureaucrat doesn't have high enough grade.\n";
		throw AForm::GradeTooLowException(); 
	}
	this->isSigned = true;
	std::cout << b.getName() << " signed " << this->getName() << ".\n";
}

void	AForm::execute(Bureaucrat const &e) const {
	if (!this->getIsSigned()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because it isn't signed yet.\n";
		throw AForm::NotSignedException();
	}
	else if (e.getGrade() > this->getGradeToExecute()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because bureaucrat doesn't have high enough grade.\n";
		throw AForm::GradeTooLowException(); 
	}
	else { 
		std::cout << e.getName() << " executed " << this->getName() << std::endl;
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

const char *AForm::NotSignedException::what() const throw() {
	return "AForm not signed yet";
}

std::ostream	&operator<<(std::ostream &o, AForm const &f) {
	o << "AForm name = " << f.getName() << "\nRequired Grade to Sign = " << f.getGradeToSign() <<
	"\nRequired Grade to Execute = " << f.getGradeToExecute() << "\nIs Signed = " <<
	(f.getIsSigned() ? "Signed" : "Not Signed") << std::endl;
	return o;
}
