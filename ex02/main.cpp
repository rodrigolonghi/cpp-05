#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat				a("Jhon", 1);
	Bureaucrat				b("Will", 40);
	Bureaucrat				c("Anna", 130);
	ShrubberyCreationForm	s("Shrubbery");
	RobotomyRequestForm		r("Robotomy");
	PresidentialPardonForm	p("Presidential");

	std::cout << "\e[0;38;5;44mAForm not signed yet error\n\n\e[0m";
	try {
		a.executeForm(s);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nAForm can't be signed\n\n\e[0m";
	try {
		s.beSigned(c);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nSign all AForms\n\n\e[0m";
	try {
		s.beSigned(a);
		r.beSigned(a);
		p.beSigned(a);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nExecute error\n\n\e[0m";
	try {
		c.executeForm(p);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\e[0;38;5;44m\nExecute success\n\n\e[0m";
	try {
		c.executeForm(s);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		b.executeForm(r);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		a.executeForm(p);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
