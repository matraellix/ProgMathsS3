#include <iostream>
#include "Ratio.hpp"

int main()
{
    Ratio b(10,4); 
    std::cout << b << std::endl;
    b = -b;
    std::cout << "- unaire : " << b << std::endl;
    
    std::cout <<"abs : "<< b.abs(b) << std::endl;
    std::cout << b << std::endl;
    Ratio c(30,4); 
    std::cout << c << std::endl;
    
    Ratio d;
    std::cout << d << std::endl;

    Ratio sum = b + c;
    std::cout << " sum : " << sum << std::endl;

    Ratio sub = b - c;
    std::cout << " sub : " << sub << std::endl;
  
    Ratio sub2 = c - b;
    std::cout << " sub2 : " <<  sub2 << std::endl;

    Ratio div = b / c;
    std::cout << " div : " <<  div << std::endl;

    Ratio mult = b * c;
    std::cout << " mult : " <<  mult << std::endl;

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

    // test for increment and decrement operators
    Ratio h(3,2); 
    std::cout << "h : "<< h << std::endl;
    std::cout << "++h : "<< ++h << std::endl;   
    std::cout << "h++ : "<< h++ << std::endl;
    std::cout << "--h : "<< --h << std::endl;
    std::cout << "h-- : "<< h-- << std::endl;
    
    Ratio i(5,2); 
    h+=i;
    std::cout << "+= operator :"<< h << std::endl;
    h-=i;
    std::cout << "-= operator :"<< h << std::endl;
    h*=i;
    std::cout << "*= operator :"<< h << std::endl;
    h/=i;
    std::cout << "/= operator :"<< h << std::endl;

    //test setter
    i.set_num(7);
    std::cout << i << std::endl;
    i.set_num(6);
    std::cout << i << std::endl;


    Ratio k(1,2);
    Ratio l(4,1);
    float fl = 2.5;
    std::cout << k*fl << std::endl;

    std::cout << k*l << std::endl;

    return 0;
}
