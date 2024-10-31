#include "Bureaucrat.hpp"

int main()
{
    try
    {
      Bureaucrat a = Bureaucrat("Nauman", 150);
      Bureaucrat b = Bureaucrat("Adnan", 2);
      std::cout << b << std::endl;
      b.increment();
      std::cout << b << std::endl;
      std::cout << a << std::endl;
      a.decrement();
      std::cout << a << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "bureaucrat "<< e.what() << std::endl; 
    }
    return (0);
}
