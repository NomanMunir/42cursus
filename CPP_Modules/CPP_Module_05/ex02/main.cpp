#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
   try {
        Bureaucrat b("Noman", 1);
        ShrubberyCreationForm Sform("Shrubbery");
        RobotomyRequestForm Rform("Robotomy");
        PresidentialPardonForm Pform("President");

        std::cout << "\n--------------- ( Shrubbery Form) ---------------" << std::endl;
        b.signForm(Sform);
        b.executeForm(Sform);
        std::cout << "\n--------------- ( Robotomy Form) ---------------" << std::endl;
        b.signForm(Rform);
        b.executeForm(Rform);
        b.executeForm(Rform);
        b.executeForm(Rform);
        b.executeForm(Rform);
        std::cout << "\n--------------- ( President Form) ---------------" << std::endl;
        b.signForm(Pform);
        b.executeForm(Pform);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
