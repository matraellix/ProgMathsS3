#include <iostream>
#include <numeric>
#include "Ratio.hpp"


/*******CONSTRUCTORS***********/
Ratio::Ratio(const int &num, const int &denom){
    if(denom == 0) throw std::string("division by zero");
    int gcd = std::gcd(num, denom);
    m_num = num/gcd;
    m_denom = denom/gcd;  
}


Ratio::Ratio(const double &real){
    const int nb_iter = 3;
    std::cout << "je passe"  << std::endl;
    convert_float_to_ratio(real, nb_iter);
}
    
//don't work
Ratio Ratio::convert_float_to_ratio(const double &real, int nb_iter){

    Ratio sum;
    if (real == 0){
        return sum;
    }
    if (nb_iter == 0){
        return sum;
    }
    if (real > 1 || real < -1){
        sum = convert_float_to_ratio(1/real, nb_iter);
        return sum;
    }
    if (real >=1 || real <= -1){
        const int q = (int)real;
        sum.m_num += q;
        sum.m_denom += 1;
        return sum + convert_float_to_ratio(real - q, nb_iter-1);
    }
    return sum;
}

/*******OPERATORS*******/
//NE MARCHE PAS A FAIRE POUR EVITER LA DUPLICATION DE CODE GCD
Ratio Ratio::reduce_frac(const Ratio &r){
    int num = 0, denom = 1;
    int gcd = std::gcd(r.m_num, r.m_denom);
    num /= gcd;
    denom /= gcd;   
    Ratio new_r(num, denom);
    return new_r;
}

Ratio Ratio::operator+(const Ratio &r) const {
    return Ratio((m_num * r.m_denom) + (m_denom * r.m_num), (m_denom * r.m_denom)); 
}

Ratio Ratio::operator-(const Ratio &r) const {
    return Ratio((m_num * r.m_denom) - (m_denom * r.m_num), (m_denom * r.m_denom)); 
}

Ratio Ratio::operator-() const {
    return Ratio(-m_num, m_denom); 
}

Ratio Ratio::operator/(const Ratio &r) const {
   return Ratio((m_num * r.m_denom), (m_denom * r.m_num)); 

}

Ratio Ratio::operator*(const Ratio &r) const {
    return Ratio((m_num * r.m_num), (m_denom * r.m_denom)); 
}

Ratio & Ratio::operator=(const Ratio &r) {
    if (&r == this) return *this;
    m_num = r.m_num;
    m_denom = r.m_denom;
    return *this;
}

Ratio Ratio::abs(const Ratio &r) {
    //a voir si on check que le num + tard
    return (r.m_num < 0 || r.m_denom < 0) ? -r : r;
}

std::ostream& operator<< (std::ostream& stream, const Ratio& r){
	stream << r.get_num() << "/" << r.get_denom();
	return stream;
}


int Ratio::get_num() const{
    return m_num;
}

int Ratio::get_denom() const{
    return m_denom;
}
