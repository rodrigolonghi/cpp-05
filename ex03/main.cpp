#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Bureaucrat	a("Jhon", 1);
	Bureaucrat	b("Anna", 150);
	Intern		i;
	AForm		*s;
	AForm		*r;
	AForm		*p;
	AForm		*invalid;

	std::cout << "\e[0;38;5;44mIntern creating forms\n\n\e[0m";
	s = i.makeForm("shrubbery creation", "shrubbery target");
	r = i.makeForm("robotomy request", "robotomy target");
	p = i.makeForm("presidential pardon", "presidential target");
	invalid = i.makeForm("invalid form", "invalid target");

	std::cout << "\e[0;38;5;44m\n\nCheck invalid form invalid\n\n\e[0m";
	if (invalid != NULL) {
		try {
			invalid->beSigned(a);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} else {
		std::cout << "Invalid form is NULL.\n\n";
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44mAForm not signed yet error\n\n\e[0m";
	try {
		a.executeForm(*s);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nAForm can't be signed\n\n\e[0m";
	try {
		s->beSigned(b);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nSign all AForms\n\n\e[0m";
	try {
		s->beSigned(a);
		r->beSigned(a);
		p->beSigned(a);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nExecute error\n\n\e[0m";
	try {
		b.executeForm(*p);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nExecute success\n\n\e[0m";
	try {
		a.executeForm(*s);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		a.executeForm(*r);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		a.executeForm(*p);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
