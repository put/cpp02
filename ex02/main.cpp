#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl; // Should be 0 initially
    std::cout << ++a << std::endl; // Should increase by the smallest amount possible which is 0.00390625
    std::cout << a << std::endl; // Number hasn't changed so should be 0.00390625 again
    std::cout << a++ << std::endl; // Another increase so it should be 0.0078125, but because the ++ comes after, it displays the old value of 0.00390625
    std::cout << a << std::endl; // should now output 0.0078125
    std::cout << b << std::endl; // should be 10.1016
    std::cout << Fixed::max( a, b ) << std::endl; // should also be 10.1016 because it compares to 0.0078125 and chooses the bigger number


	std::cout << "Non-subject additional tests" << std::endl;
	//Additional non-subject tests
	std::cout << a-- << std::endl; // value at this point is 0.0078125 so new value is 0.00390625 but operator comes after, so it wlil display the original value still
	std::cout << --a << std::endl; // value at this point is 0.00390625 and we decrease once again, operator coming before, so it will output 0
	a = Fixed(5.05f); // assign new value to a because it's currently 0 which isn't ideal for dividing and multiplying
	std::cout << a * 2 << std::endl; // should output 10.1016
	std::cout << a / 2 << std::endl; // should output 2.52344
	std::cout << (Fixed(3.14f) == Fixed(3.14f)) << std::endl; // compares the two Fixed values, they are exactly equal so it should output 1 (true)
	std::cout << (Fixed(3.141f) == Fixed(3.14f)) << std::endl; // compares again with a value in which the difference is smaller than 1 increment/decrement step, so should still output 1 (true)
	std::cout << (Fixed(3.145f) == Fixed(3.14f)) << std::endl; // compares once more with a difference bigger than a step, so should output 0 (false)
	std::cout << Fixed((4.55f)).toFloat() << std::endl; // testing toFloat() function, should output 4.55078
    return 0;
}