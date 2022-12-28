#include <iostream>
#include "Ratio.hpp"

int main()
{
    Ratio b(0,5); 
    std::cout << b << std::endl;
    b = -b;
    std::cout << "- unaire : " << b << std::endl;
    Ratio z(-2,-3);
    std::cout <<"abs : "<< z.abs() << std::endl;
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
    std::cout << "g.abs() = "<< g.abs() << std::endl;

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
    //float fl = 2.5;
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


    std::cout << k*l << std::endl;

    Ratio j(3,4);
    Ratio m(1,2);
    std::cout << "sqrt j: " << j.square_root() << std::endl;
    std::cout << "sqrt m: " << m.square_root() << std::endl;

    Ratio n(-7,2);
    std::cout << "integer part n " << n << " : " << n.integer_part() << std::endl;
    Ratio o(-3,2);
    std::cout << "(" << o << ")Â³ = " << power(o,2) << std::endl;

    Ratio p(10,21);
    std::cout <<" percentage approximé m: " << p.convert_to_percentage()<<std::endl;

    Ratio q(5,14);
    std::cout <<" float d'un ratio m: " << q.convert_ratio_to_float()<<std::endl;

    Ratio r(1,2);
    std::cout <<" exponentielle de r(1,2): " << expo(r) <<std::endl;

    std::cout << "infini : " << r.infinit() << std::endl;

    Ratio s(9,1);
    Ratio t(4,1);
    std::cout << "1/2 % 5/7 : " << s%t << std::endl;

    Ratio wow(0.00025);
    std::cout << "0.00025 : " << wow << std::endl;

    Ratio u(1,2);
    std::cout << "cos : " << cosinus_ratio(u) << std::endl;

    Ratio v(1,2);
    std::cout << "sin : " << sinus_ratio(v) << std::endl;

    Ratio w(1,2);
    std::cout << "tan : " << tan_ratio(w) << std::endl;
    
    Ratio x(100,1);
    std::cout <<" logarithm of x(1/2): " << logarithm(x) <<std::endl;

    return 0;
}