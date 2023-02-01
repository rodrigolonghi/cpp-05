#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string	target;

	public:
		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

		std::string	getTarget() const;

		void	execute(Bureaucrat const &b) const;
};

#endif
