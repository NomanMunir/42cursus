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

void Bureaucrat::signForm(AForm& form)
{
  try
  {
    if (form.getFormSignature())
    {
      std::cout << "Form already signed." << std::endl;
      return ;
    }
    form.beSigned(*this);
    if (form.getFormSignature())
      std::cout << _name << " signed " << form.getName() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const & form)
{
  try
  {
    form.execute(*this);
  }
  catch (std::exception& e)
  {
    std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
  }

}


std::ostream& operator<<(std::ostream& o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (o);
}