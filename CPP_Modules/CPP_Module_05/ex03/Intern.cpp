#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { (void)other; return (*this); }

AForm * Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
  AForm *forms[3] = {new ShrubberyCreationForm(formTarget), new RobotomyRequestForm(formTarget), new PresidentialPardonForm(formTarget)};
  std::string names[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
  for (int i = 0; i < 3; i++)
  {
    if (formName == names[i] && forms[i])
    {
      std::cout << "Intern creates " << names[i] << std::endl;
      AForm *tmp = forms[i]->clone();
      for (size_t j = 0; j < 3; j++)
        if (forms[j]) delete forms[j];
      return (tmp);
    }
  }
  for (size_t j = 0; j < 3; j++)
    if (forms[j]) delete forms[j];
  return (NULL);
}
