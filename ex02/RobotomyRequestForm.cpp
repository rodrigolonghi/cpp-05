#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm::AForm("RobotomyRequestForm", 72, 45), target("No one") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm::AForm("RobotomyRequestForm", 72, 45), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
 AForm::AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), target(src.getTarget()) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
	this->setName(src.getName());
	this->setIsSigned(src.getIsSigned());
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExecute(src.getGradeToExecute());
	const_cast<std::string &>(this->target) = src.getTarget();
	return *this;
}

std::string	RobotomyRequestForm::getTarget() const {
	return this->target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &e) const {
	if (!this->getIsSigned()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because it isn't signed yet.\n";
		throw AForm::NotSignedException();
	} else if (e.getGrade() > this->getGradeToExecute()) {
		std::cout << e.getName() << " couldn't execute " << this->getName() << " because bureaucrat doesn't have high enough grade.\n";
		throw AForm::GradeTooLowException(); 
	} else {
		std::cout << e.getName() << " executed " << this->getName() << std::endl;
		srand (time(NULL));
		std::cout << "*Making some drilling noises*\n";
		if (rand() % 2) {
			std::cout << this->getTarget() << " has been robotomized.\n";
		} else {
			std::cout << "Robotomy failed.\n";
		}
	}
}
