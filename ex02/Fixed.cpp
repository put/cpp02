    #include "Fixed.hpp"
    #include <iostream>
    #include <ostream>
    
    Fixed::Fixed()
    {
        _value = 0;
        std::cout << "Default ctor called" << std::endl;
    }

    Fixed::Fixed(const Fixed& orig)
    {
        _value = orig._value;
        std::cout << "Copy ctor called" << std::endl;
    }

    Fixed::Fixed(const int num)
    {
        _value = num << FRAC_BIT_COUNT;
        std::cout << "Int ctor called" << std::endl;
    }

    Fixed::Fixed(const float num)
    {
        _value = roundf(num * (1 << FRAC_BIT_COUNT));
        std::cout << "Float ctor called" << std::endl;
    }

    Fixed& Fixed::operator=(const Fixed& orig)
    {
        if (this != &orig)
            _value = orig._value;
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    bool Fixed::operator>(const Fixed &orig) const
    {
        return _value > orig.getRawBits();
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
    }

    Fixed Fixed::operator-(const Fixed &orig)
    {
        Fixed res;
        res._value = _value - orig._value;
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
        _value += 1;
        return *this;
    }

    Fixed& Fixed::operator--()
    {
        _value -= 1;
        return *this;
    }

    Fixed::~Fixed()
    {
        std::cout << "Destructor called" << std::endl;
    }

    int Fixed::getRawBits() const
    {
        std::cout << "Getter called" << std::endl;
        return _value;
    }

    void Fixed::setRawBits(const int raw)
    {
        std::cout << "Setter called" << std::endl;
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

    std::ostream& operator<<(std::ostream& os, Fixed const& value)
    {
        os << value.toFloat();
        return os;
    }