#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	a("Jhon", 75);
	Bureaucrat	b("Will", 1);
	Bureaucrat	c("Anna", 150);
	Form		d("Form1", 42, 42);

	//Bureaucrat tests
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
	std::cout << c << std::endl;

	//Form tests
	//Should not throw error
	try {
		b.signForm(d);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	//Should throw error
	try {
		a.signForm(d);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
