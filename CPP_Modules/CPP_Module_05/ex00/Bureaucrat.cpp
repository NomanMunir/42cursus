#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade)
{
  if (grade < 1)
      throw GradeTooHighException();
  else if (grade > 150)
      throw  GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) { _grade = rhs._grade; return (*this); }

int Bureaucrat::getGrade() const { return (_grade); }

std::string Bureaucrat::getName() const { return (_name); }

void Bureaucrat::increment()
{
    _grade -= 1;
    if (_grade < 1)
      throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    _grade += 1;
    if (_grade > 150)
      throw  GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (o);
}