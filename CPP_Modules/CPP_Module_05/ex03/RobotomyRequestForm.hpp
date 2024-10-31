#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();
  AForm * clone() const;
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

  virtual void execute(const Bureaucrat& executor) const;

private:
  RobotomyRequestForm();
  std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP