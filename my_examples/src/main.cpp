#include <iostream>
#include "Ratio.hpp"

int main()
{
    Ratio b(10,4); 
    std::cout << b << std::endl;
    b = -b;
    std::cout << b << std::endl;
    
    std::cout << b.abs(b) << std::endl;
    std::cout << b << std::endl;
    Ratio c(30,4); 
    std::cout << c << std::endl;
    
    Ratio d;
    std::cout << d << std::endl;

    Ratio sum = b + c;
    std::cout << sum << std::endl;

    Ratio sub = b - c;
    std::cout << sub << std::endl;
  
    Ratio sub2 = c - b;
    std::cout << sub2 << std::endl;

    Ratio div = b / c;
    std::cout << div << std::endl;

    Ratio mult = b * c;
    std::cout << mult << std::endl;

    Ratio e(1,2); 
    Ratio f(3,4);
    std::cout << " e : " << e << " f : " << f << std::endl;
    std::cout << (e == f) << std::endl;
    std::cout << (e > f) << std::endl;
    std::cout << (e < f) << std::endl;
    std::cout << (e >= f) << std::endl;
    std::cout << (e <= f) << std::endl;
    Ratio g(-1.5);
    std::cout << "g = "<< g << std::endl;
    std::cout << "abs(g) = "<< g.abs(g) << std::endl;
    return 0;
}
