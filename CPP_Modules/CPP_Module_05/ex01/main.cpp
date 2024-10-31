#include "Bureaucrat.hpp"

int main()
{
    try
    {
      Bureaucrat a = Bureaucrat("Nauman", 11);
      Form b = Form("school form", 2, 4);
      std::cout << a << std::endl;
      std::cout << b << std::endl;
      a.signForm(b);
      a.signForm(b);
      std::cout << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
    return (0);
}
