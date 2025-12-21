#include "Fixed.hpp"
#include <ostream>
#include <iostream>

Fixed::Fixed(): rawBits(0)
{
	std::cout <<"Default constructor called" <<std::endl;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout <<"Copy assignment operator called" <<std::endl;
	if(this != &src)
		rawBits = src.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout <<"Copy constructor called" <<std::endl;
	if(this != &src)
		*this = src;

}

Fixed::~Fixed()
{
	std::cout <<"Destructor called" <<std::endl;
}

 int Fixed::getRawBits( void ) const
 {
	std::cout <<"getRawBits member function called" <<std::endl;
	return rawBits;
 }

void Fixed::setRawBits( int const raw )
{
	rawBits = raw;
}
