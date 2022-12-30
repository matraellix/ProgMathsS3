#pragma once
#include <iostream>
#include <cassert>

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html home_image.jpg
/// \tableofcontents
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependencies
/// \li Doxygen (if you want the documentation)
/// \li Google Test (if you want the Unit Test)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html



/// \class Ratio
/// \brief class defining a rational number for algebra operations.
class Ratio {

    private:

    int m_num, m_denom; /*!< components of the rational */

    public:

    /// \brief default constructor
    Ratio(): m_num(0), m_denom(1){}

    /// \brief constructor from an integer
	/// \param m_num : the value of the integer
    Ratio(const int &num): m_num(num), m_denom(1){} 

    /// \brief constructor from a specific fraction
	/// \param m_num : the value of the numerator
	/// \param m_denom : the value of the denominator
    Ratio(const int &num, const int &denom);

    /// \brief copy-constructor
	/// \param v : the source rational to be copied
    Ratio(const Ratio &r): m_num(r.m_num), m_denom(r.m_denom){}


    /// \brief constructor from a real number
	/// \param real : the value of the real number
    Ratio(const double &real);

    /// \brief destructor
    ~Ratio() = default;

    /// \brief arithmetic operators

    /// @brief sum of two rationals
    /// @param r : ratio to add
    /// @return Ratio sum of this and r
    Ratio operator+(const Ratio &r) const;

    /// @brief substraction of two rationals
    /// @param r : ratio to substract
    /// @return Ratio sub of this and r
    Ratio operator-(const Ratio &r) const;

    /// @brief unit minus
    /// @return opposite ratio
    Ratio operator-() const;

    /// @brief division of two rationals
    /// @param r : ratio to substract
    /// @return Ratio from division of this and r
    Ratio operator/(const Ratio &r) const;

    /// @brief return the reminder of two rationals
    /// @param r : ratio to divide
    /// @return Ratio from modulo of this and r
    Ratio operator%(const Ratio &r) const;

    /// @brief multiplication of two rationals
    /// @param r : ratio to multiply
    /// @return Ratio from multiplication of this and r
    Ratio operator*(const Ratio &r) const;

    /// \brief assignment operators

    /// @brief assign a new value to a rational
    /// @param r : r is the new value to assign
    /// @return Ratio with new value
    Ratio & operator=(const Ratio &r);

    /// @brief  add a value to the current ratio and assign the new value
    /// @param r : r is the new value to add and assign
    /// @return Ratio with new value
    Ratio & operator+=(const Ratio &r);

    /// @brief substract a value to the current ratio and assign the new value
    /// @param r : r is the new value to substract and assign
    /// @return Ratio with new value
    Ratio & operator-=(const Ratio &r);

    /// @brief multiply a value to the current ratio and assign the new value
    /// @param r : r is the new value to multiply and assign
    /// @return Ratio with new value    
    Ratio & operator*=(const Ratio &r);
    
    /// @brief divide a value to the current ratio and assign the new value
    /// @param r : r is the new value to divide and assign
    /// @return Ratio with new value    
    Ratio & operator/=(const Ratio &r);

    /// \brief prefix increment and decrement operators
    /// @return Ratio with new value   
    Ratio & operator++();
    Ratio & operator--();
    /// \brief postfix increment and decrement operators
    /// @return Ratio with new value  
    /// @param int  
    Ratio operator++(int);
    Ratio operator--(int);
    
    /// \brief methods

    /// @brief get the ratio numerator
    /// @return int, numerator
    int get_num() const;

    /// @brief get the ratio denominator
    /// @return int, denominator
    int get_denom() const; 

    /// @brief set a new numerator to the ratio
    /// @param num : int, new numerator
    /// @return int, new numerator    
    int set_num(int num);

    /// @brief set a new denominator to the ratio
    /// @param denom : int, new denominator
    /// @return int, new denominator
    int set_denom(int denom);

    /// @brief return the absolute of a ratio
    /// @return Ratio in its absolute form 
    Ratio abs();

    /// @brief return the square root of a ratio
    /// @return Ratio  
    Ratio square_root();

    /// @brief convert a rational to a percentage
    /// @return Ratio 
    Ratio convert_to_percentage();

    /// @brief give the integer part of the ratio
    /// @return int 
    int integer_part();

    /// @brief convert a rational to a float
    /// @return float
    float convert_ratio_to_float();

    /// @brief return positive denominator
    void denom_positive();

    /// @brief reduce the rational with gcd 
    void reduce_frac();

    /// @brief rational form of infinit
    /// @return Ratio of infinit
    const Ratio infinit();

    /// @brief rational form of 0
    /// @return Ratio of 0
    const Ratio zero();

    /// @brief display the rational
    /// @param stream 
    /// @param r Ratio to display
    /// @return display the rational
    friend std::ostream &operator<< (std::ostream& stream, const Ratio& r);

};
    /// @brief reverse a rational
    /// @param r ratio to reverse
    /// @return reversed ratio
    Ratio reverse(const Ratio &r);

    /// @brief return the power of a rational
    /// @param r : ratio to calculate the power
    /// @return Ratio, value of the power
    Ratio power(const Ratio &r, const int n);

    /// @brief return the exponential value of a rational
    /// @param r : ratio to calculate exponential
    /// @return double, value of exponential
    Ratio expo(const Ratio &r);

    /// @brief return the logarithm Ratio value (base e)
    /// @param r : ratio to calculate log
    /// @return Ratio, value of log
    Ratio logarithmE(const Ratio &r);

    /// @brief return the logarithm Ratio value (base 10)
    /// @param r : ratio to calculate log
    /// @return Ratio, value of log
    Ratio logarithm10(const Ratio &r);

    /// @brief return the cosinus of a rational
    /// @param r : ratio to calculate cos
    /// @return ratio, value of cosinus
    Ratio cosinus_ratio(const Ratio &r);

    /// @brief return the sinus of a rational
    /// @param r : ratio to calculate sin
    /// @return ratio, value of sinus
    Ratio sinus_ratio(const Ratio &r);

    /// @brief return the tan of a rational
    /// @param r : ratio to calculate tan
    /// @return ratio, value of tan
    Ratio tan_ratio(const Ratio &r);

    /// @brief convert real to rational
    /// @param real: double to convert
    /// @param nb_iter : int, nb of times we call the function
    /// @return Rational form of real
    Ratio convert_float_to_ratio(const double &real, int nb_iter);

    /// \brief comparison operators

    /// @brief equal comparison between two rationals
    /// @param r1 : ratio to compare
    /// @param r2 : ratio to compare
    /// @return  bool from comparison
    bool operator==(const Ratio &r1, const Ratio &r2);

    /// @brief not_equal comparison between two rationals
    /// @param r1 : ratio to compare
    /// @param r2 : ratio to compare
    /// @return  bool from comparison
    bool operator!=(const Ratio &r1, const Ratio &r2);

    /// @brief greater or equal than comparison between two rationals
    /// @param r1 : ratio to compare
    /// @param r2 : ratio to compare
    /// @return  bool from r1 greater or equal than r2
    bool operator>=(const Ratio &r1, const Ratio &r2);


    /// @brief less or equal than comparison between two rationals
    /// @param r1 : ratio to compare
    /// @param r2 : ratio to compare
    /// @return  bool from r1 less or equal than r2
    bool operator<=(const Ratio &r1, const Ratio &r2);

    /// @brief greater than comparison between two rationals
    /// @param r1 : ratio to compare
    /// @param r2 : ratio to compare
    /// @return  bool from r1 greater than r2
    bool operator>(const Ratio &r1, const Ratio &r2);

    /// @brief less than comparison between two rationals
    /// @param r1 : ratio to compare
    /// @param r2 : ratio to compare
    /// @return  bool from r1 less than r2
    bool operator<(const Ratio &r1, const Ratio &r2);



/// \brief comparison template operators

/// @brief template multiplication
/// @tparam T : int or float/double
/// @param nb : real to multiply 
/// @param r : ratio to multiply
/// @return Ratio from the multiplication
template<typename T> 
Ratio operator*(const T &nb, const Ratio &r) {
    //check if nb is an integer or a float else we stop
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator*(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");
    return r*nb;
}

/// @brief template division
/// @tparam T : int or float/double
/// @param nb : real to divide
/// @param r : ratio to divide
/// @return Ratio from division
template<typename T> 
Ratio operator/(const T &nb, const Ratio &r){
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator/(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");
    return reverse(r)*nb;
}

/// @brief template sum
/// @tparam T : int or float/double
/// @param nb : real to add
/// @param r : ratio to add
/// @return Ratio from sum
template<typename T> 
Ratio operator+(const T &nb, const Ratio &r) {
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator+(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");
    return r+nb;
}

/// @brief template substraction
/// @tparam T : int or float/double
/// @param nb : real to sub
/// @param r : ratio to sub
/// @return  Ratio from substraction
template<typename T> 
Ratio operator-(const T &nb, const Ratio &r) {
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator-(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");
    return r-nb;
}

/// @brief template equal comparison
/// @tparam T : int or float/double
/// @param nb : real to compare
/// @param r : ratio to compare
/// @return  bool from comparison
template<typename T> 
bool operator==(const T &nb, const Ratio &r){
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator==(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");
    return r == nb;
}

/// @brief template not_equal comparison
/// @tparam T : int or float/double
/// @param nb : real to compare
/// @param r : ratio to compare
/// @return  bool from comparison
template<typename T> 
bool operator!=(const T &nb, const Ratio &r){
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator!=(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");
    return !(nb == r);
}

/// @brief template greater than comparison between a real and rational
/// @tparam T : int or float/double
/// @param nb : real to compare
/// @param r : ratio to compare
/// @return  bool from comparison nb greater than r
template<typename T> 
bool operator>(const T &nb, const Ratio &r){
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator>(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");
    return r < nb;
}

/// @brief template less than comparison between a real and rational
/// @tparam T : int or float/double
/// @param nb : real to compare
/// @param r : ratio to compare
/// @return  bool from comparison nb less than r
template<typename T> 
bool operator<(const T &nb, const Ratio &r){
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator<(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");  
    return r > nb;
}

/// @brief template greater than or equal comparison between a real and rational
/// @tparam T : int or float/double
/// @param nb : real to compare
/// @param r : ratio to compare
/// @return  bool from comparison nb greather or equal than r
template<typename T> 
bool operator>=(const T &nb, const Ratio &r){
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator>=(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");    
    return !(nb < r);
}

/// @brief template less or equal than comparison between a real and rational
/// @tparam T : int or float/double
/// @param nb : real to compare
/// @param r : ratio to compare
/// @return  bool from comparison nb less or equal than r
template<typename T> 
bool operator<=(const T &nb, const Ratio &r){
    static_assert( (std::is_arithmetic_v<T>), "Ratio::operator<=(const T &nb, const Ratio &r): invalid type of nb, should be int or float/double");  
    return !(nb > r);
}
