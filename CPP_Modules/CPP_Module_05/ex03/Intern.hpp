#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
  public:
    ~Intern();
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& rhs);
    AForm * makeForm(const std::string& formName, const std::string& formTarget);
};

#endif // INTERN_HPP