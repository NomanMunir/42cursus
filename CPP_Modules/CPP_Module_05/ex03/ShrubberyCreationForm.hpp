#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
public:
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  virtual ~ShrubberyCreationForm();
  AForm * clone() const;

  virtual void execute(const Bureaucrat& executor) const;

private:
  ShrubberyCreationForm();
  std::string _target;
};

#endif