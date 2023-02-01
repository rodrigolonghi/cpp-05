#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	target;
		void				createFile(void) const;

	public:
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

		std::string	getTarget() const;

		void	execute(Bureaucrat const &b) const;
};

#endif
