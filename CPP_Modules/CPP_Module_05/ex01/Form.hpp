#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
    const std::string _name;
    bool _formSignature;
    const int _grade;
    const int _exeGrade;
    Form();
  public:
    ~Form();
    Form(const std::string name, const int grade, const int exeGrade);
    Form(const Form& other);
    Form& operator=(const Form& rhs);
    std::string getName() const;
    int getGrade() const;
    int getExeGrade() const;
    bool getFormSignature() const ;
    void beSigned(const Bureaucrat& b);
  
  class GradeTooHighException : public std::exception
  {
    virtual const char* what() const throw() { return ("Grade too high!"); }
  };

  class GradeTooLowException : public std::exception
  {
    virtual const char* what() const throw() { return ("Grade too low!"); }
  };
};

std::ostream& operator <<(std::ostream& o, const Form& form);
#endif //FORM_HPP