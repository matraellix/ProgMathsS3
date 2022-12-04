#pragma once
#include <iostream>

class Ratio {

    private:

    int m_num, m_denom;


    public:

    Ratio(): m_num(0), m_denom(1){}
    Ratio(const int &num): m_num(num), m_denom(1){}
    
    Ratio(const Ratio &r): m_num(r.m_num), m_denom(r.m_denom){}
    Ratio(const int &num, const int &denom);
    
    Ratio(const double &real);

    ~Ratio(){}

    Ratio convert_float_to_ratio(const double &real, int nb_iter);

    //operators
    Ratio operator+(const Ratio &r) const;
    Ratio operator-(const Ratio &r) const;
    Ratio operator-() const;
    Ratio operator/(const Ratio &r) const;
    Ratio operator*(const Ratio &r) const;
    Ratio & operator=(const Ratio &r);
    

    Ratio abs(const Ratio &r);
    int get_num() const;
    int get_denom() const; 

    Ratio reduce_frac(const Ratio &r);
    Ratio reduce_frac(const int &num, const int &denom);

};

    std::ostream& operator<< (std::ostream& stream, const Ratio& r);