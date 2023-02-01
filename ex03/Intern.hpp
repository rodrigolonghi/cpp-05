#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		AForm	*createShrubberyCreationForm(std::string target);
		AForm	*createRobotomyRequestForm(std::string target);
		AForm	*createPresidentialPardonForm(std::string target);

	public:
		Intern();
		~Intern();
		Intern(Intern const &src);
		Intern	&operator=(Intern const &src);

		AForm	*makeForm(std::string formName, std::string formTarget);
};

#endif
