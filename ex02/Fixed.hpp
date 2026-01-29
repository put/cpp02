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
    bool operator>=(const Fixed& orig) const;
    bool operator==(const Fixed& orig) const;
    bool operator!=(const Fixed& orig) const;
    Fixed operator+(const Fixed& orig);
    Fixed operator-(const Fixed& orig);
    Fixed operator*(const Fixed& orig);
    Fixed operator/(const Fixed& orig);
    Fixed& operator++();
    Fixed& operator--();
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int raw);
    int toInt() const;
    float toFloat() const;
    friend std::ostream& operator<<(std::ostream& os, Fixed const& value);
};
#endif