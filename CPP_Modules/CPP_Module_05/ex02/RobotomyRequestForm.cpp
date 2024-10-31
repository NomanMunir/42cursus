#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {

  AForm::execute(executor);
  std::cout << "* Makes some drilling noises *" << std::endl;
  std::srand(std::time(NULL));
  if (rand() % 2 == 0) {
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "Robotomy failed for " << _target << std::endl;
  }
}