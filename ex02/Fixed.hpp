#ifndef FIXED_HPP
#define FIXED_HPP
#include <ostream>

class Fixed {
    private:
    static const int FRAC_BIT_COUNT = 8;
    int _value;
    public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed& orig);
    Fixed& operator=(const Fixed& orig);
    bool operator>(const Fixed& orig) const;
    bool operator>=(const Fixed& orig) const;
    bool operator<(const Fixed& orig) const;
    bool operator<=(const Fixed& orig) const;
    bool operator==(const Fixed& orig) const;
    bool operator!=(const Fixed& orig) const;
    Fixed operator+(const Fixed& orig);
    Fixed operator-(const Fixed& orig);
    Fixed operator*(const Fixed& orig);
    Fixed operator/(const Fixed& orig);
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int raw);
    int toInt() const;
    float toFloat() const;
    static Fixed const& max(Fixed const& a, Fixed const& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static Fixed const& min(Fixed const& a, Fixed const& b);
    static Fixed& min(Fixed& a, Fixed& b);
    friend std::ostream& operator<<(std::ostream& os, Fixed const& value);
};
#endif