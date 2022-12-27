#include <iostream>
#include <numeric>
#include <cmath>
#include <stdexcept>
#include <cassert>
#include "Ratio.hpp"


/*******CONSTRUCTORS***********/
Ratio::Ratio(const int &num, const int &denom){ 
    //check if denom is not zero else we stop
    assert( (denom != 0) && "error: division by zero not possible");
    //gcd to reduce the ratio
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
    assert((r.get_num() != 0) && "error: division by zero not possible");
    return Ratio(r.get_denom(), r.get_num());
}

Ratio::Ratio(const double &real){
    const int nb_iter = 25;
    *this = convert_float_to_ratio(real, nb_iter);
    (*this).denom_positif();
}

const Ratio Ratio::infinit(){
    return (1,0);
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
    if (m_denom * r.m_num == 0){
        throw std::domain_error("divide by zero");
    }
    return Ratio((m_num * r.m_denom), (m_denom * r.m_num)); 
}

Ratio Ratio::operator%(const Ratio &r) const {
   return Ratio((m_num * r.m_denom) % (m_denom * r.m_num), (m_denom * r.m_denom)); 
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

bool operator==(const Ratio & r1, const Ratio &r2){
    return (r1.get_num() * r2.get_denom()) == (r2.get_num() * r1.get_denom());
}

bool operator!=(const Ratio & r1, const Ratio &r2){
    return !(r1 == r2);
}

bool operator>(const Ratio & r1, const Ratio &r2){
    return (r1.get_num() * r2.get_denom()) > (r2.get_num() * r1.get_denom());
}

bool operator<(const Ratio & r1, const Ratio &r2){
    return (r1.get_num() * r2.get_denom()) < (r2.get_num() * r1.get_denom());
}

bool operator>=(const Ratio & r1, const Ratio &r2){
    return !(r1 < r2);
}

bool operator<=(const Ratio & r1, const Ratio &r2){
    return !(r1 > r2);
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

Ratio Ratio::convert_to_percentage(){
    //num*100/denom
    //attention simplicifation non voulue on voudrait rester à du /100. Peut-etre ajouter booléen en 3e arg
    return Ratio(m_num*100/m_denom, 100);
}

int Ratio::integer_part(){
    return m_num/m_denom;
}
float Ratio::convert_ratio_to_float(){
    return static_cast<float>(m_num)/static_cast<float>(m_denom);
}


Ratio power(const Ratio &r, const int n){
    //check if n negative, if it is its out of range, can't process.
    if (n < 0) {
        throw std::out_of_range("power negative");
    }
    return (n==0) ? Ratio(1) : r * power(r, n-1);
}

double expo(const Ratio &r){
    return pow(exp(r.get_num()), (1.0/r.get_denom()));
}


