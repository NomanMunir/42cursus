#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();
  AForm * clone() const;

  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

  void execute(const Bureaucrat& executor) const;

private:
  PresidentialPardonForm();
  std::string _target;
};

#endif // PRESIDENTIALPARDONFORM_HPP