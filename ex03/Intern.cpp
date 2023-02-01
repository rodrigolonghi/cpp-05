#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern	&Intern::operator=(Intern const &src) {
	(void)src;
	return *this;
}

AForm	*Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string cmd[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm *(Intern::*func[3])(std::string target) = {&Intern::createShrubberyCreationForm,
	&Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	
	for (int i = 0; i < 3; i++) {
		if (name == cmd[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*func[i])(target);
		}
	}
	std::cout << name << " is not a valid form.\n";
	return (NULL);
}