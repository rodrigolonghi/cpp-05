#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
}

Bureaucrat::Bureaucrat(std::string name, short grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	const_cast<std::string &>(this->name) = name;
	this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	const_cast<std::string &>(this->name) = rhs.getName();
	this->grade = rhs.getGrade();
	return *this;
}

std::string	Bureaucrat::getName() const {
	return (this->name);
}

short	Bureaucrat::getGrade() const {
	return (this->grade);
}

void	Bureaucrat::incrementGrade(){
	if (this->grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;
}

void	Bureaucrat::decrementGrade(){
	if (this->grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade++;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b) {
	o << "Bureaucrat " << b.getName() << ", grade: " << b.getGrade() << std::endl;
	return o;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low exception";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high exception";
}
