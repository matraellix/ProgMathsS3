#include <iostream>
#include <numeric>
#include <cmath>
#include "Ratio.hpp"


/*******CONSTRUCTORS***********/
Ratio::Ratio(const int &num, const int &denom){
    if(denom == 0) throw std::string("division by zero");
    int gcd = std::gcd(num, denom);
    m_num = num/gcd;
    m_denom = denom/gcd;  
}

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

Ratio inverse(const Ratio &r) {
    return Ratio(r.get_denom(), r.get_num());
}

Ratio::Ratio(const double &real){
    const int nb_iter = 3;
    *this = convert_float_to_ratio(real, nb_iter);
}
    
Ratio convert_float_to_ratio(const double &real, int nb_iter){

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
        const int q = static_cast<int>(real);
        return Ratio(q,1) + convert_float_to_ratio(real - q, nb_iter-1);
    }
    return Ratio(0,1);
}

void Ratio::denom_positif(){
    if(m_denom < 0){
        m_num *= -1;
        m_denom *= -1;
    }
}

void Ratio::reduce_frac(){
    //cas -num/-denom ou num/-denom -> (r.m_num < 0 && r.mdenom<0) || (r.m_num > 0 && r.mdenom<0) -> r.mdenom<0    
    int gcd = std::gcd(m_num, m_denom);
    m_num /= gcd;
    m_denom /= gcd;  
    (*this).denom_positif();
}

/*******OPERATORS*******/

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
    new_rf = convert_float_to_ratio(f,10);
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

Ratio Ratio::abs() {
    (*this).denom_positif();
    return (m_num < 0) ? Ratio(-m_num, m_denom) : Ratio(m_num, m_denom);
}

Ratio Ratio::squareRoot(){
    float m_numSQRT = sqrt(m_num);
    float m_denomSQRT = sqrt(m_denom);
    Ratio new_rNum;
    new_rNum = convert_float_to_ratio(m_numSQRT,10);
    Ratio new_rDenom;
    new_rDenom = convert_float_to_ratio(m_denomSQRT,10);
    new_rDenom = inverse(new_rDenom);
    Ratio new_r;
    new_r = new_rDenom*new_rNum;
    new_r.reduce_frac();
    return new_r;
}

int Ratio::integer_part(){
   return m_num/m_denom;
}

//segmentation error for n < 0;
Ratio pow(const Ratio &r, const unsigned int n){
    return (n==0) ? Ratio(1) : r * pow(r, n-1);
}

double exp(const Ratio &r){
    return 0;
}