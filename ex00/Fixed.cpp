    #include "Fixed.hpp"
    #include <iostream>
    
    Fixed::Fixed()
    {
        _value = 0;
        std::cout << "Default ctor called" << std::endl;
    }

    Fixed::Fixed(const Fixed& orig)
    {
        _value = orig.getRawBits();
        std::cout << "Copy ctor called" << std::endl;
    }
    Fixed& Fixed::operator=(const Fixed& orig)
    {
        if (this != &orig)
            _value = orig.getRawBits();
        std::cout << "Assignment operator called" << std::endl;
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