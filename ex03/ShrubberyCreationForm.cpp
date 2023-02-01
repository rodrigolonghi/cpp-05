#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm::AForm("ShrubberyCreationForm", 145, 137), target("No_name") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm::AForm("ShrubberyCreationForm", 145, 137), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
 AForm::AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), target(src.getTarget()) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
	this->setName(src.getName());
	this->setIsSigned(src.getIsSigned());
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExecute(src.getGradeToExecute());
	const_cast<std::string &>(this->target) = src.getTarget();
	return *this;
}

std::string	ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &e) const {
	if (!this->getIsSigned()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because it isn't signed yet.\n";
		throw AForm::NotSignedException();
	}
	else if (e.getGrade() > this->getGradeToExecute()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because bureaucrat doesn't have high enough grade.\n";
		throw AForm::GradeTooLowException(); 
	} else {
		std::cout << e.getName() << " executed " << this->getName() << std::endl;
		this->createFile();
	}
}

void ShrubberyCreationForm::createFile() const {
	std::ofstream	ofs((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out);
ofs << "       _-_          \n"
	<< "    /~~   ~~\\      \n"
	<< " /~~         ~~\\   \n"
	<< "{               }   \n"
	<< " \\  _-     -_  /   \n"
	<< "   ~  \\\\ //  ~    \n"
	<< "_- -   | | _- _     \n"
	<< "  _ -  | |   -_     \n"
	<< "      // \\\\;      \n\n";
}
