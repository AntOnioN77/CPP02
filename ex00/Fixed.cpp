#include "Fixed.hpp"

Fixed::Fixed(): rawBits=0;
Fixed::Fixed(const Fixed& src)
{
    if(this != &src)
        rawBits = src.getRawBits();

}

Fixed& Fixed::Fixed::operator=(const Fixed& src)
{
    if(this != &src)
        rawBits = src.getRawBits();
    return *this;
}

Fixed::~Fixed();

 int Fixed::getRawBits( void ) const
 {
    return rawBits;
 }

 void Fixed::setRawBits( int const raw )
 {
    rawBits = raw;
 }
 
