#include <iostream>
#include <cmath>
#include <iomanip>

#include "Ratio.hpp"


int main()
{
    //contructor
    Ratio r1(1,5); 
    std::cout << "constructor r1: " << r1 << std::endl;

    //default constructor
    Ratio default_r;
    std::cout << "default constructor: " << default_r << std::endl;

    //unary minus
    r1 = -r1;
    std::cout << "r1 unary minus: " << r1 << std::endl;

    //absolute
    Ratio r2(-2,-3);
    std::cout << "r2 = "<< r2 << std::endl;
    std::cout <<"abs : "<< r2.abs() << std::endl;
    Ratio r3(-1.5);
    std::cout << "r3 = "<< r3 << std::endl;
    std::cout << "r3.abs() = "<< r3.abs() << std::endl;
    
    //arithmetic operators
    //plus
    Ratio r4(1,3);
    Ratio sum = r1 + r4;
    std::cout << r1 << " + " << r4 << " = " << sum << std::endl;
    //minus
    Ratio sub = r1 - r4;
    std::cout << r1 << " - " << r4 << " = " << sub << std::endl;
    Ratio sub2 = r4 - r1;
    std::cout << r4 << " - " << r1 << " = " <<  sub2 << std::endl;

    //division
    Ratio div = r1 / r4;
    std::cout << r1 << " / " << r4 << " = " << div << std::endl;

    //multiplication
    Ratio mult = r1 * r4;
    std::cout << r1 << " * " << r4 << " = " <<  mult << std::endl;

    //comparison
    Ratio r5(1,2); 
    Ratio r6(3,4);
    std::cout << "1 = true and 0 = false" << std::endl;
    std::cout << " r5 : " << r5 << " r6 : " << r6 << std::endl;
    std::cout << "(r5 == r6) :" << (r5 == r6) << std::endl;
    std::cout << "(r5 > r6) :" << (r5 > r6) << std::endl;
    std::cout << "(r5 < r6) :" << (r5 < r6) << std::endl;
    std::cout << "(r5 >= r6) :" << (r5 >= r6) << std::endl;
    std::cout << "(r5 <= r6) :" << (r5 <= r6) << std::endl;


    //increment and decrement operators
    std::cout << "r6 : "<< r6 << std::endl;
    std::cout << "++r6 : "<< ++r6 << std::endl;   
    std::cout << "r6++ : "<< r6++ << std::endl;
    std::cout << "--r6 : "<< --r6 << std::endl;
    std::cout << "r6-- : "<< r6-- << std::endl;
    
    //assignment operators
    Ratio r7(5,2); 
    r6+=r7;
    std::cout << "+= operator :"<< r6 << std::endl;
    r6=r7;
    std::cout << "-= operator :"<< r6 << std::endl;
    r6*=r7;
    std::cout << "*= operator :"<< r6 << std::endl;
    r6/=r7;
    std::cout << "/= operator :"<< r6 << std::endl;

    //setter
    r7.set_num(7);
    std::cout <<"set numerator to 7 : " << r7 << std::endl;
    r7.get_num();
    std::cout <<"get numerator : " << r7.get_num() << std::endl;


    Ratio r8(1,2);
    //test of operations with a float
    std::cout << "r8 = " << r8 << std::endl;
    std::cout << "0.5 * r8 = " << 0.5*r8 << std::endl;
    std::cout << "r8 * 0.5 = " << r8*0.5 << std::endl;
    std::cout << "3 * r8 = " << 3*r8 << std::endl;
    std::cout << "r8 * 3 = " << r8*3 << std::endl;
    std::cout << "0 * r8 = " << 0/r8 << std::endl;
    std::cout << "r8 / 2 = "<< r8/2 << std::endl;
    std::cout << "2 / r8 = "<< 2/r8 << std::endl;
    std::cout << "r8 + 2 = "<< r8+2 << std::endl;
    std::cout << "2 + r8 = "<< 2+r8 << std::endl;
    std::cout << "r8 - 2 = "<< r8-2 << std::endl;
    std::cout << "2 - r8 = "<< 2-r8 << std::endl;

    std::cout << "r8 == 0 : "<< (r8 == 0) << std::endl;
    std::cout << "0 == r8 : "<< (0 == r8) << std::endl;
    std::cout << "r8 == 0.5 : "<< (r8 == 0.5) << std::endl;
    std::cout << "0.5 == r8 : "<< (0.5 == r8) << std::endl;
    std::cout << "r8 != 0.5 : "<< (r8 != 0.5) << std::endl;
    std::cout << "0.5 != r8 : "<< (0.5 != r8) << std::endl;
    std::cout << "r8 != 1 : "<< (r8 != 1) << std::endl;
    std::cout << "1 != r8 : "<< (1 != r8) << std::endl;
    std::cout << "r8 > 0.5 : "<< (r8 > 0.5) << std::endl;
    std::cout << "0.5 <= r8 : "<< (0.5 <= r8) << std::endl;
    std::cout << "r8 < 0.5 : "<< (r8 < 0.5) << std::endl;
    std::cout << "0.5 => r8 : "<< (0.5 >= r8) << std::endl;

    //square root of a ratio
    std::cout << "sqrt r8: " << r8.square_root() << std::endl;

    //integer part of a ratio
    std::cout << "integer part " << r8 << " : " << r8.integer_part() << std::endl;

    //power of a ratio
    std::cout << "(" << r8 << ")³ = " << power(r8,3) << std::endl;

    //approximated percentage of a ratio
    Ratio r9(10,21);
    std::cout <<" approximated percentage " << r9 << " : " << r9.convert_to_percentage() << std::endl;

    //convert ratio to float
    Ratio r10(5,14);
    std::cout <<" float of ratio " << r10 << " : " << r10.convert_ratio_to_float()<<std::endl;

    //exponential of a ratio
    std::cout <<" exponential of " << r8 <<  " = " << expo(r8) <<std::endl;

    //infinite ratio
    std::cout << "infinite : " << r10.infinit() << std::endl;

    //modulo
    Ratio r11(9,1);
    Ratio r12(4,1);
    std::cout << r11 << " % "<< r12 << " : " << r11%r12 << std::endl;

    //test for precision
    double real = 0.00000025;
    Ratio r_prec(real);
    std::cout << "0.00000025 : " << r_prec << std::endl;
    std::cout << real << " : " << std::setprecision(9) << real - (double)r_prec.convert_ratio_to_float() << std::endl;

    //trigonometry
    //cosinus
    Ratio cos_r(1,2);
    std::cout << "cos : " << cosinus_ratio(cos_r) << std::endl;

    //sinus
    Ratio sin_r(1,2);
    std::cout << "sin : " << sinus_ratio(sin_r) << std::endl;

    //tangent
    Ratio tan_r(1,2);
    std::cout << "tan : " << tan_ratio(tan_r) << std::endl;
    
    //logarithm base e
    Ratio log_r(3,2);
    std::cout <<"logarithm (e) of x(3/2): " << logarithmE(log_r) <<std::endl;

    //logarithm base 10
    Ratio log_r10(100,1);
    std::cout <<"logarithm (10) of x(100/1): " << logarithm10(log_r10) <<std::endl;

    return 0;
}