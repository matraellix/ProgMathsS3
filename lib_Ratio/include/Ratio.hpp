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
    Ratio operator+(const Ratio &r) const;
    Ratio operator-(const Ratio &r) const;
    Ratio operator-() const;
    Ratio operator/(const Ratio &r) const;
    Ratio operator*(const Ratio &r) const;
    //Ratio operator*(const float &f) const;
    //Ratio operator*(const int &i) const;
    /// \brief assignment operators
    Ratio & operator=(const Ratio &r);
    Ratio & operator+=(const Ratio &r);
    Ratio & operator-=(const Ratio &r);
    Ratio & operator*=(const Ratio &r);
    Ratio & operator/=(const Ratio &r);
    /// \brief prefix increment and decrement operators
    Ratio & operator++();
    Ratio & operator--();
    /// \brief postfix increment and decrement operators
    Ratio operator++(int);
    Ratio operator--(int);

    /// \brief comparison operators
    bool operator==(const Ratio &r);
    bool operator!=(const Ratio &r);
    bool operator>=(const Ratio &r);
    bool operator<=(const Ratio &r);
    bool operator>(const Ratio &r);
    bool operator<(const Ratio &r);
    
    /// \brief methods
    int get_num() const;
    int get_denom() const; 
    int set_num(int num);
    int set_denom(int denom);

    Ratio abs();
    Ratio squareRoot();
    Ratio convert_to_percentage();
    int integer_part();
    float convert_ratio_to_float();

    void denom_positif();
    void reduce_frac();

};
    Ratio inverse(const Ratio &r);
    Ratio power(const Ratio &r, const int n);
    double expo(const Ratio &r);
    /// \brief return the rational number from a real
    Ratio convert_float_to_ratio(const double &real, int nb_iter);
    std::ostream& operator<< (std::ostream& stream, const Ratio& r);


    template<typename T> 
    Ratio from_int_or_float(const T &nb);
    template<typename T> 
    Ratio operator*(const T &nb, const Ratio &r);
    template<typename T> 
    Ratio operator/(const T &nb, const Ratio &r);
    template<typename T> 
    Ratio from_int_or_float(const T &nb);


template<typename T> 
Ratio from_int_or_float(const T &nb){
    Ratio r;
    if(std::is_integral<T>::value){
        r = nb;
    } else {
        r = convert_float_to_ratio(nb,10);
    }
    return r;
}

template<typename T> 
Ratio operator*(const T &nb, const Ratio &r) {
    Ratio new_r = from_int_or_float(nb);
    new_r *= r;
    new_r.reduce_frac();
    return new_r; 
}


template<typename T> 
Ratio operator/(const T &nb, const Ratio &r){
    if (nb == 0) return 0;
    Ratio new_r = from_int_or_float(nb);
    new_r /= r;
    new_r.reduce_frac();
    return new_r;  
}

template<typename T> 
Ratio operator+(const T &nb, const Ratio &r) {
    Ratio new_r = from_int_or_float(nb);
    new_r += r;
    new_r.reduce_frac();
    return new_r; 
}

template<typename T> 
Ratio operator-(const T &nb, const Ratio &r) {
    Ratio new_r = from_int_or_float(nb);
    new_r -= r;
    new_r.reduce_frac();
    return new_r; ; 
}

template<typename T> 
bool operator==(const T &nb, const Ratio &r){
    Ratio new_r = from_int_or_float(nb);
    return new_r == r;
}

template<typename T> 
bool operator!=(const T &nb, const Ratio &r){
    Ratio new_r = from_int_or_float(nb);
    return !(new_r == r);
}

template<typename T> 
bool operator>(const T &nb, const Ratio &r){
    Ratio new_r = from_int_or_float(nb);
    return (new_r > r);
}

template<typename T> 
bool operator<(const T &nb, const Ratio &r){
    Ratio new_r = from_int_or_float(nb);
    return (new_r < r);
}

template<typename T> 
bool operator>=(const T &nb, const Ratio &r){
    Ratio new_r = from_int_or_float(nb);
    return !(new_r < r);
}

template<typename T> 
bool operator<=(const T &nb, const Ratio &r){
    Ratio new_r = from_int_or_float(nb);
    return !(new_r > r);
}
