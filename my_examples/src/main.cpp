#include <iostream>
#include <cmath>
#include <iomanip>

#include "Ratio.hpp"


int main()
{
    //contructor
    Ratio b(1,5); 
    Ratio c(1,3);
    std::cout << b << std::endl;

    //default constructor
    Ratio d;
    std::cout << d << std::endl;

    //unary minus
    b = -b;
    std::cout << "- unaire : " << b << std::endl;

    //absolute
    Ratio z(-2,-3);
    std::cout <<"abs : "<< z.abs() << std::endl;
    Ratio g(-1.5);
    std::cout << "g = "<< g << std::endl;
    std::cout << "g.abs() = "<< g.abs() << std::endl;
    
    //arithmetic operators
    //plus
    Ratio sum = b + c;
    std::cout << " sum : " << sum << std::endl;
    //minus
    Ratio sub = b - c;
    std::cout << " sub : " << sub << std::endl;
    Ratio sub2 = c - b;
    std::cout << " sub2 : " <<  sub2 << std::endl;

    //division
    Ratio div = b / c;
    std::cout << " div : " <<  div << std::endl;

    //multiplication
    Ratio mult = b * c;
    std::cout << " mult : " <<  mult << std::endl;

    //comparison
    Ratio e(1,2); 
    Ratio f(3,4);
    std::cout << "1 = true and 0 = false" << std::endl;
    std::cout << " e : " << e << " f : " << f << std::endl;
    std::cout << "(e == f) :" << (e == f) << std::endl;
    std::cout << "(e > f) :" << (e > f) << std::endl;
    std::cout << "(e < f) :" << (e < f) << std::endl;
    std::cout << "(e >= f) :" << (e >= f) << std::endl;
    std::cout << "(e <= f) :" << (e <= f) << std::endl;


    //increment and decrement operators
    Ratio h(3,2); 
    std::cout << "h : "<< h << std::endl;
    std::cout << "++h : "<< ++h << std::endl;   
    std::cout << "h++ : "<< h++ << std::endl;
    std::cout << "--h : "<< --h << std::endl;
    std::cout << "h-- : "<< h-- << std::endl;
    
    //assignment operators
    Ratio i(5,2); 
    h+=i;
    std::cout << "+= operator :"<< h << std::endl;
    h-=i;
    std::cout << "-= operator :"<< h << std::endl;
    h*=i;
    std::cout << "*= operator :"<< h << std::endl;
    h/=i;
    std::cout << "/= operator :"<< h << std::endl;

    //setter
    i.set_num(7);
    std::cout <<"set numerator to 7 : " << i << std::endl;
    i.set_num(6);
    std::cout <<"set numerator to 6 : " << i << std::endl;
    //getter
    i.get_num();
    std::cout <<"get numerator : " << i << std::endl;


    Ratio k(1,2);
    //test of operations with a float
    std::string aie = "aie";
    std::cout << "test multi 0.5*k : "<< 0.5*k << std::endl;
    std::cout << "test multi k*0.5 : "<< k*0.5 << std::endl;
    std::cout << "test multi 3*k : "<< 3*k << std::endl;
    std::cout << "test multi k*3 : "<< k*3 << std::endl;
    std::cout << "test div 0/k : "<< 0/k << std::endl;
    std::cout << "test div k/2 : "<< k/2 << std::endl;
    std::cout << "test div k/2.5 : "<< k/2.5 << std::endl;
    std::cout << "test div 2/K : "<< 2/k << std::endl;

    std::cout << "test addition k+2 : "<< k+2 << std::endl;
    std::cout << "test addition 2+k : "<< 2+k << std::endl;
    std::cout << "test soustraction k-2: "<< k-2 << std::endl;
    std::cout << "test soustraction 2-k: "<< 2-k << std::endl;

    std::cout << "test k == 0 : "<< (k == 0) << std::endl;
    std::cout << "test 0 == k : "<< (0 == k) << std::endl;
    std::cout << "test k == 0.5 : "<< (k == 0.5) << std::endl;
    std::cout << "test 0.5 == k : "<< (0.5 == k) << std::endl;
    std::cout << "test k != 0.5 : "<< (k != 0.5) << std::endl;
    std::cout << "test 0.5 != k : "<< (0.5 != k) << std::endl;
    std::cout << "test k != 1 : "<< (k != 1) << std::endl;
    std::cout << "test 1 != k : "<< (1 != k) << std::endl;
    std::cout << "test k > 0.5 : "<< (k > 0.5) << std::endl;
    std::cout << "test 0.5 <= k : "<< (0.5 <= k) << std::endl;
    std::cout << "test k < 0.5 : "<< (k < 0.5) << std::endl;
    std::cout << "test 0.5 => k : "<< (0.5 >= k) << std::endl;

    //square root of a ratio
    Ratio j(3,4);
    std::cout << "sqrt j: " << j.square_root() << std::endl;
    Ratio m(1,2);
    std::cout << "sqrt m: " << m.square_root() << std::endl;

    //integer part of a ratio
    Ratio n(-7,2);
    std::cout << "integer part n " << n << " : " << n.integer_part() << std::endl;

    //power of a ratio
    Ratio o(-3,2);
    std::cout << "(" << o << ")³ = " << power(o,3) << std::endl;

    //approximated percentage of a ratio
    Ratio p(10,21);
    std::cout <<" approximated percentage : " << p.convert_to_percentage()<<std::endl;

    //convert ratio to float
    Ratio q(5,14);
    std::cout <<" float of a ratio : " << q.convert_ratio_to_float()<<std::endl;

    //exponential of a ratio
    Ratio r(1,2);
    std::cout <<" exponential r(1,2): " << expo(r) <<std::endl;

    //infinite ratio
    std::cout << "infinite : " << r.infinit() << std::endl;

    //modulo
    Ratio s(9,1);
    Ratio t(4,1);
    std::cout << "1/2 % 5/7 : " << s%t << std::endl;

    //test for precision
    Ratio wow(0.00000025);
    std::cout << "0.00025 : " << wow << std::endl;
    double ca = 101.52;
    Ratio wow1(c);
    std::cout << ca << " : " << wow1 << std::endl;
    std::cout << ca << " : " << std::setprecision(9) << ca - (double)wow1.convert_ratio_to_float() << std::endl;

    //trigonometry
    //cosinus
    Ratio u(1,2);
    std::cout << "cos : " << cosinus_ratio(u) << std::endl;

    //sinus
    Ratio v(1,2);
    std::cout << "sin : " << sinus_ratio(v) << std::endl;

    //tangent
    Ratio w(1,2);
    std::cout << "tan : " << tan_ratio(w) << std::endl;
    
    //logarithm base e
    Ratio x(3,2);
    std::cout <<"logarithm (e) of x(3/2): " << logarithmE(x) <<std::endl;

    //logarithm base 10
    Ratio y(100,1);
    std::cout <<"logarithm (10) of x(100/1): " << logarithm10(y) <<std::endl;

    return 0;
}