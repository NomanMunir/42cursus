#include "AForm.hpp"

AForm::AForm(const std::string name, const int grade, const int exeGrade)
: _name(name),
  _formSignature(false),
  _grade(grade),
  _exeGrade(exeGrade)
{
    if (grade < 1 || exeGrade < 1)
      throw GradeTooHighException();
  else if (grade > 150 || exeGrade > 150)
      throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name),
  _formSignature(other._formSignature),
  _grade(other._grade),
  _exeGrade(other._exeGrade) {}

AForm& AForm::operator=(const AForm& rhs)
{
  _formSignature = rhs._formSignature;
  return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const { return (_name); }

int AForm::getGrade() const { return (_grade); }

int AForm::getExeGrade() const { return (_exeGrade); }

bool AForm::getFormSignature() const { return (_formSignature); }

void AForm::beSigned(const Bureaucrat& b)
{
  if (b.getGrade() > this->getGrade())
    throw GradeTooLowException();
  this->_formSignature = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
  if (!this->getFormSignature())
    throw NotSignedException();
  if (executor.getGrade() > this->getExeGrade())
    throw GradeTooLowException();
  std::cout << "Form " << this->getName() << " is executed by " << executor.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
{
  o << "Name: " << form.getName() << std::endl;
  o << "Grade: " << form.getGrade() << std::endl;
  o << "Execution Grade: " << form.getExeGrade() << std::endl;
  o << "Is Form Signed: " << form.getFormSignature();
  return (o);
}
