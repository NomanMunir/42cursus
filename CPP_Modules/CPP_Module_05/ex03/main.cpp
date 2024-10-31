#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
   try {
        Intern * intern = new Intern();
        AForm * form = intern->makeForm("Shrubbery Creation", "Shrubbery");
        Bureaucrat b("Noman", 149);
        b.signForm(*form);
        b.executeForm(*form);
        delete(form);
        if (intern) delete(intern);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
