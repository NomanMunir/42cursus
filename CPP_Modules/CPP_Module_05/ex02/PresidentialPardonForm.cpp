#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->getFormSignature()) {
    std::cout << "Form is not signed, cannot be executed." << std::endl;
    return;
  }

  if (executor.getGrade() > this->getExeGrade()) {
    std::cout << "Bureaucrat has insufficient grade to execute the form." << std::endl;
    return;
  }

  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}