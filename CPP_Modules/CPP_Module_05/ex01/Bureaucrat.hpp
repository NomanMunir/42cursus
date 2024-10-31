#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
        Bureaucrat();
    public:
        ~Bureaucrat();
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        int getGrade() const;
        std::string getName() const;
        void increment();
        void decrement();
        void signForm(Form& form);

    class GradeTooHighException : public std::exception
    {
        virtual const char* what() const throw() { return ("Grade too high!"); }
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char* what() const throw() { return ("Grade too low!"); }
    };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat &b);

# endif //BUREAUCRAT_HPP