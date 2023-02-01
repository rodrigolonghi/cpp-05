#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <time.h>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	target;

	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

		std::string	getTarget() const;

		void	execute(Bureaucrat const &b) const;
};

#endif
