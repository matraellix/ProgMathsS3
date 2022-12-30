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

Ratio::Ratio(const double &real){
    const int nb_iter =9;
    *this = convert_float_to_ratio(real, nb_iter);
    (*this).denom_positive();
}

const Ratio Ratio::infinit(){
    Ratio r;
    r.m_num = 1;
    r.m_denom = 0;
    return r;
}
const Ratio Ratio::zero(){
    return Ratio(0,1);
}

/*******GETTER***********/
int Ratio::get_num() const{
    return m_num;
}

int Ratio::get_denom() const{
    return m_denom;
}

/*******SETTER***********/
int Ratio::set_num(int num){
    m_num = num;
    return m_num;
}

int Ratio::set_denom(int denom){
    assert( (denom != 0) && "error: division by zero not possible");
    m_denom = denom;
    return m_denom;
}

/*******CONVERSION***********/
Ratio convert_float_to_ratio(const double &real, int nb_iter){

    if (real == 0){
        return Ratio(0,1);
    }
    if (nb_iter == 0){
        return Ratio(0,1);
    }
    if (real > -1 && real < 1){
        return reverse(convert_float_to_ratio(1/real, nb_iter));
    }
    if (real >= 1 || real <= -1){
        const int q = static_cast<int>(real);
        return Ratio(q,1) + convert_float_to_ratio(real - q, nb_iter-1);
    }
    return Ratio(0,1);
}

float Ratio::convert_ratio_to_float(){
    return static_cast<float>(m_num)/static_cast<float>(m_denom);
}

/*******REVERSE***********/
Ratio reverse(const Ratio &r) {
    assert((r.get_num() != 0) && "error: division by zero not possible");
    return Ratio(r.get_denom(), r.get_num());
}
/*******POSITIVE DENOMINATOR***********/
void Ratio::denom_positive(){
    if(m_denom < 0){
        m_num *= -1;
        m_denom *= -1;
    }
}
/*******SIMPLIFY RATIO***********/
void Ratio::reduce_frac(){
    int gcd = std::gcd(m_num, m_denom);
    m_num /= gcd;
    m_denom /= gcd;  
    (*this).denom_positive();
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
    
    if((*this)==r){
        return Ratio(1,1);
    }else if(((*this).m_num==0) || (r.m_num==0)){
        return Ratio(0,1);
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


/*******ABSOLUTE***********/
Ratio Ratio::abs() {
    if (m_num == 0){
        return zero();
    }
    if (m_denom == 0){
        return infinit();
    }
    (*this).denom_positive();
    return (m_num < 0) ? Ratio(-m_num, m_denom) : Ratio(m_num, m_denom);
}

/*******SQUARE ROOT***********/
Ratio Ratio::square_root(){
    (*this).denom_positive();
    assert(((*this).m_num >= 0) && "sqrt impossible for negative numbers");
    Ratio new_rNum = convert_float_to_ratio(sqrt(m_num),9);
    Ratio new_rDenom = reverse(convert_float_to_ratio(sqrt(m_denom),9));
    Ratio new_r = new_rDenom*new_rNum;
    new_r.reduce_frac();
    return new_r;
}

/*******APPROXIMATED PERCENTAGE***********/
Ratio Ratio::convert_to_percentage(){
    //num*100/denom
    return Ratio(m_num*100/m_denom, 100);
}

/*******INTEGER PART***********/
int Ratio::integer_part(){
    return m_num/m_denom;
}

/*******POWER***********/
Ratio power(const Ratio &r, const int n){
    //check if n negative, if it is its out of range, can't process.
    if (n < 0) {
        throw std::out_of_range("Domain error: power negative");
    }
    return (n==0) ? Ratio(1) : r * power(r, n-1);
}

/*******EXPONENTIAL***********/
Ratio expo(const Ratio &r){
    if(r.get_num()==0){
        return Ratio(1,1);
    }
    return convert_float_to_ratio(pow(exp(r.get_num()), (1.0/r.get_denom())), 9);
}
/*******LOGARITHM BASE e **********/
Ratio logarithmE(const Ratio &r){
    if (r <= 0){
        throw std::out_of_range("Domain error: logarithm cannot be negative or equal to 0");
    }
    return convert_float_to_ratio((std::log(r.get_num()))-(std::log(r.get_denom())), 9);
}

/*******LOGARITHM BASE 10 **********/
Ratio logarithm10(const Ratio &r){
    if (r <= 0){
        throw std::out_of_range("Domain error: logarithm cannot be negative or equal to 0");
    }
    return convert_float_to_ratio((std::log10(r.get_num()))-(std::log10(r.get_denom())), 9);
}

/*******TRIGONOMETRY IN RADIANS **********/

//simple version of cosinus
Ratio cosinus_ratio(const Ratio &r){
    float num = r.get_num();
    float denom = r.get_denom();
    float arg_cos = num/denom;
    Ratio cosi = convert_float_to_ratio(std::cos(arg_cos),9);
    cosi.reduce_frac();
    return cosi;
}

//simple version of sinus
Ratio sinus_ratio(const Ratio &r){
    float num = r.get_num();
    float denom = r.get_denom();
    float arg_cos = num/denom;
    Ratio sinus = convert_float_to_ratio(std::sin(arg_cos),9);
    sinus.reduce_frac();
    return sinus;
}

Ratio tan_ratio(const Ratio &r){
    assert((r != Ratio(M_PI,2)) && "tan(pi/2) is impossible");
    return Ratio(sinus_ratio(r)/cosinus_ratio(r));
}

