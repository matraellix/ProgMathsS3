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

Ratio Ratio::inverse(const Ratio &r) {
    return Ratio(r.m_denom, r.m_num);
}

Ratio::Ratio(const double &real){
    const int nb_iter = 3;
    *this = convert_float_to_ratio(real, nb_iter);
}
    
Ratio Ratio::convert_float_to_ratio(const double &real, int nb_iter){

    if (real == 0){
        return Ratio(0,1);
    }
    if (nb_iter == 0){
        return Ratio(0,1);
    }
    if (real > -1 && real < 1){
        return inverse(convert_float_to_ratio(1/real, nb_iter));
    }
    if (real >= 1 || real <= -1){
        const int q = (int)real;
        return Ratio(q,1) + convert_float_to_ratio(real - q, nb_iter-1);
    }
}

/*******OPERATORS*******/
//NE MARCHE PAS A FAIRE POUR EVITER LA DUPLICATION DE CODE GCD
void Ratio::reduce_frac(){
    //cas -num/-denom ou num/-denom -> (r.m_num < 0 && r.mdenom<0) || (r.m_num > 0 && r.mdenom<0) -> r.mdenom<0    
    int gcd = std::gcd(m_num, m_denom);
    m_num /= gcd;
    m_denom /= gcd;  
    if(m_denom < 0){
        m_num *= -1;
        m_denom *= -1;
    } 
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


Ratio Ratio::operator*(const float &f) const {
    Ratio new_rf;
    new_rf = new_rf.convert_float_to_ratio(f,10);
    new_rf.m_num *= m_num ;
    new_rf.m_denom *= m_denom ;
    new_rf.reduce_frac();
    return new_rf; 
}


Ratio Ratio::operator*(const int &i) const {
    Ratio new_r ((m_num * i), (m_denom));
    new_r.reduce_frac();
    return new_r; 
}

Ratio & Ratio::operator=(const Ratio &r) {
    if (&r == this) return *this;
    m_num = r.m_num;
    m_denom = r.m_denom;
    return *this;
}

bool Ratio::operator==(const Ratio &r){
    return (m_num * r.m_denom) == (r.m_num * m_denom);
}

bool Ratio::operator!=(const Ratio &r){
    return !((m_num * r.m_denom) == (r.m_num * m_denom));
}

bool Ratio::operator>(const Ratio &r){
    return (m_num * r.m_denom) > (r.m_num * m_denom);
}

bool Ratio::operator<(const Ratio &r){
    return (m_num * r.m_denom) < (r.m_num * m_denom);
}

bool Ratio::operator>=(const Ratio &r){
    return !(*this < r);
}

bool Ratio::operator<=(const Ratio &r){
    return !(*this > r);
}

Ratio & Ratio::operator++(){
    m_num += m_denom;
    return *this;
}

Ratio & Ratio::operator--(){
    m_num -= m_denom;
    return *this;
}

Ratio Ratio::operator++(int){ 

    return ++*this;
}

Ratio Ratio::operator--(int){
    return --*this;
}

Ratio & Ratio::operator+=(const Ratio &r) {
    *this = *this + r;
    return *this;
}

Ratio & Ratio::operator-=(const Ratio &r) {
    *this = *this - r;
    return *this;
}
Ratio & Ratio::operator*=(const Ratio &r) {
    *this = *this * r;
    return *this;
}

Ratio & Ratio::operator/=(const Ratio &r) {
    *this = *this / r;
    return *this;
}


std::ostream& operator<< (std::ostream& stream, const Ratio& r){
	stream << r.get_num() << "/" << r.get_denom();
	return stream;
}


Ratio Ratio::abs(const Ratio &r) {
    //a voir si on check que le num + tard
    return (r.m_num < 0 || r.m_denom < 0) ? -r : r;
}

/*
Ratio Ratio::squareRoot(const Ratio &r){
    m_num = sqrt(r.m_num);
}*/

int Ratio::get_num() const{
    return m_num;
}

int Ratio::get_denom() const{
    return m_denom;
}

int Ratio::set_num(int num){
    m_num = num;
    return m_num;
}

int Ratio::set_denom(int denom){
    m_denom = denom;
    return m_denom;
}