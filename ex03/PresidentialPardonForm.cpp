#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm::AForm("PresidentialPardonForm", 25, 5), target("No one") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm::AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
 AForm::AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), target(src.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
	this->setName(src.getName());
	this->setIsSigned(src.getIsSigned());
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExecute(src.getGradeToExecute());
	const_cast<std::string &>(this->target) = src.getTarget();
	return *this;
}

std::string	PresidentialPardonForm::getTarget() const {
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &e) const {
	if (!this->getIsSigned()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because it isn't signed yet.\n";
		throw AForm::NotSignedException();
	} else if (e.getGrade() > this->getGradeToExecute()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because bureaucrat doesn't have high enough grade.\n";
		throw AForm::GradeTooLowException(); 
	} else { 
		std::cout << e.getName() << " executed " << this->getName() << std::endl;
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
	}
}
