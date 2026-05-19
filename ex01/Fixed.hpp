#pragma once
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
    ~Fixed();
    int getRawBits() const;
    void setRawBits(const int raw);
    int toInt() const;
    float toFloat() const;
};

// Has to be prototyped outside of the class in order to not require the forbidden "friend" keyword
std::ostream& operator<<(std::ostream& os, Fixed const& value);