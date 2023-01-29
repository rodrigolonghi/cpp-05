#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	a("Jhon", 75);
	Bureaucrat	b("Will", 1);
	Bureaucrat	c("Anna", 150);

	//Should not throw error
	//increment grade
	std::cout << a;
	try {
		a.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	//decrement grade
	std::cout << a;
	try {
		a.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what();
	}
	std::cout << a << std::endl;

	//Should throw error
	//increment grade
	std::cout << b;
	try {
		b.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	//decrement grade
	std::cout << c;
	try {
		c.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << c;
	return (0);
}
