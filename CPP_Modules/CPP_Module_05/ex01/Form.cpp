#include "Form.hpp"

Form::Form(const std::string name, const int grade, const int exeGrade)
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

Form::Form(const Form& other)
: _name(other._name),
  _formSignature(other._formSignature),
  _grade(other._grade),
  _exeGrade(other._exeGrade) {}

Form& Form::operator=(const Form& rhs)
{
  _formSignature = rhs._formSignature;
  return (*this);
}

Form::~Form() {}

std::string Form::getName() const { return (_name); }

int Form::getGrade() const { return (_grade); }

int Form::getExeGrade() const { return (_exeGrade); }

bool Form::getFormSignature() const { return (_formSignature); }

void Form::beSigned(const Bureaucrat& b)
{
  if (b.getGrade() > this->_grade)
    throw GradeTooLowException();
  this->_formSignature = true;
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
  o << "Name: " << form.getName() << std::endl;
  o << "Grade: " << form.getGrade() << std::endl;
  o << "Execution Grade: " << form.getExeGrade() << std::endl;
  o << "Is Form Signed: " << form.getFormSignature();
  return (o);
}
