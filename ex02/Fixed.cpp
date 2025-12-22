#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int Fixed::get_point()
{
	return fixed_point;
}

Fixed::Fixed(): rawBits(0)
{
	//std::cout <<"Default constructor called" <<std::endl;
}

Fixed::Fixed(const int num)
{
	//std::cout <<"Int constructor called" <<std::endl;
	rawBits = num<<fixed_point;
}


Fixed::Fixed(const float num)
{
	//std::cout <<"Float constructor called" <<std::endl;
	rawBits = roundf(num * (1 << fixed_point));
}

Fixed& Fixed::operator=(const Fixed& src)
{
	//std::cout <<"Copy assignment operator called" <<std::endl;
	if(this != &src)
		rawBits = src.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& src)
{
	//std::cout <<"Copy constructor called" <<std::endl;
	*this = src;	//Para imprimir como en el subject, pero mas eficiente y seguro:
					//rawBits = src.rawBits;
}

Fixed::~Fixed()
{
	//std::cout <<"Destructor called" <<std::endl;
}

 int Fixed::getRawBits( void ) const
 {
	//std::cout <<"getRawBits member function called" <<std::endl;
	return rawBits;
 }

void Fixed::setRawBits( int const raw )
{
	rawBits = raw;
}

float Fixed::toFloat( void )const
{
	return (rawBits / (float)(1 << fixed_point));
}

int Fixed::toInt( void )const
{
	return (roundf(this->toFloat()));
}

std::ostream& operator<<(std::ostream& os, const Fixed& n)
{
	float convert = n.toFloat();
	os << convert;
	return os;
}

//Aritmetic Operators:
Fixed Fixed::operator+(const Fixed& b) const
{
	Fixed result;
	result.setRawBits(rawBits + b.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& b) const
{
	Fixed result;
	result.setRawBits(rawBits - b.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& b) const
{
	Fixed result;

	result.setRawBits(((long)rawBits * b.getRawBits()) >> Fixed::fixed_point);
	return result;
}

Fixed Fixed::operator/(const Fixed& b) const
{
	Fixed result;

	result.setRawBits(((long)rawBits << Fixed::fixed_point) / b.getRawBits());
	return result;
}

//Comparison operators
bool Fixed::operator<(const Fixed& b) const
{
	return rawBits < b.getRawBits();
}

bool Fixed::operator<=(const Fixed& b) const
{
	return rawBits <= b.getRawBits();
}

bool Fixed::operator>(const Fixed& b) const
{
	return rawBits > b.getRawBits();
}

bool Fixed::operator>=(const Fixed& b) const
{
	return rawBits >= b.getRawBits();
}

bool Fixed::operator==(const Fixed& b) const
{
	return (rawBits == b.getRawBits());
}

bool Fixed::operator!=(const Fixed& b) const
{
	return rawBits != b.getRawBits();
}

//increment operatotors
Fixed Fixed::operator++(int) //post-increment
{
    Fixed tmp(*this);
	rawBits++;
	return tmp;
}

Fixed& Fixed::operator++() //pre-increment
{
	rawBits++;
	return *this;
}

Fixed Fixed::operator--(int) //post-decrement
{
	Fixed tmp(*this);
	rawBits--;
	return tmp;
}

Fixed& Fixed::operator--() //pre-decrement
{
	rawBits--;
	return *this;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a.rawBits >= b.rawBits)
		return b;
	return a;
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a.rawBits >= b.rawBits)
		return b;
	return a;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a.rawBits <= b.rawBits)
		return b;
	return a;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a.rawBits <= b.rawBits)
		return b;
	return a;
}
