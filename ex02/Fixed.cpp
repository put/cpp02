    #include "Fixed.hpp"
    #include <cmath>
    #include <ostream>
    
    Fixed::Fixed()
    {
        _value = 0;
    }

    Fixed::Fixed(const Fixed& orig)
    {
        _value = orig._value;
    }

    Fixed::Fixed(const int num)
    {
        _value = num << FRAC_BIT_COUNT;
    }

    Fixed::Fixed(const float num)
    {
        _value = roundf(num * (1 << FRAC_BIT_COUNT));
    }

    Fixed& Fixed::operator=(const Fixed& orig)
    {
        if (this != &orig)
            _value = orig._value;
        return *this;
    }

    bool Fixed::operator>(const Fixed &orig) const
    {
        return _value > orig.getRawBits();
    }

	bool Fixed::operator<=(const Fixed& orig) const
	{
		return _value >= orig.getRawBits();
	}

    bool Fixed::operator>=(const Fixed &orig) const
    {
        return _value >= orig.getRawBits();
    }

    bool Fixed::operator<(const Fixed &orig) const
    {
        return _value < orig._value;
    }

    bool Fixed::operator==(const Fixed &orig) const
    {
        return _value == orig._value;
    }

    bool Fixed::operator!=(const Fixed &orig) const
    {
        return _value != orig._value;
    }

    Fixed Fixed::operator+(const Fixed &orig)
    {
        Fixed res;
        res._value = _value + orig._value;
        return res;
    }

    Fixed Fixed::operator-(const Fixed &orig)
    {
        Fixed res;
        res._value = _value - orig._value;
        return res;
    }

    Fixed Fixed::operator*(const Fixed &orig)
    {
        Fixed res;
        long temp;
        temp = _value * orig._value;
        res._value = temp >> FRAC_BIT_COUNT;
        return res;
    }

    Fixed Fixed::operator/(const Fixed &orig)
    {
        Fixed res;
        long temp = ((long)_value << FRAC_BIT_COUNT) / orig._value;
        res._value = temp;
        return res;
    }

    Fixed& Fixed::operator++()
    {
        _value++;
        return *this;
    }

    Fixed& Fixed::operator--()
    {
        _value--;
        return *this;
    }

    Fixed Fixed::operator++(int)
    {
        Fixed temp(*this);
        _value++;
        return temp;
    }

    Fixed Fixed::operator--(int)
    {
        Fixed temp(*this);
        _value--;
        return temp;
    }

    std::ostream& operator<<(std::ostream& os, Fixed const& value)
    {
        os << value.toFloat();
        return os;
    }

    Fixed::~Fixed() = default;

    int Fixed::getRawBits() const
    {
        return _value;
    }

    void Fixed::setRawBits(const int raw)
    {
        _value = raw;
    }

    int Fixed::toInt() const
    {
        return _value >> 8;
    }

    float Fixed::toFloat() const
    {
        return (float)_value / (1 << FRAC_BIT_COUNT);
    }

    Fixed& Fixed::min(Fixed& a, Fixed& b)
    {
        return (a < b ? a : b);
    }

    Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
    {
        return (a < b ? a : b);
    }

    Fixed& Fixed::max(Fixed& a, Fixed& b)
    {
        return (a > b ? a : b);
    }

    Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
    {
        return (a > b ? a : b);
    }