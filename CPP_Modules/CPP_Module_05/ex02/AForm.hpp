#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    bool _formSignature;
    const int _grade;
    const int _exeGrade;
    AForm();
  public:
    virtual ~AForm();
    AForm(const std::string name, const int grade, const int exeGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& rhs);
    std::string getName() const;
    int getGrade() const;
    int getExeGrade() const;
    bool getFormSignature() const ;
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;

  class GradeTooHighException : public std::exception
  {
    virtual const char* what() const throw() { return ("Grade too high!"); }
  };

  class GradeTooLowException : public std::exception
  {
    virtual const char* what() const throw() { return ("Grade too low!"); }
  };
   class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form not signed"; }
    };
};

std::ostream& operator <<(std::ostream& o, const AForm& form);
#endif //AFORM_HPP