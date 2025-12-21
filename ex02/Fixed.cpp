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
Fixed Fixed::operator+(const Fixed& b)
{
	Fixed sum;
	sum.setRawBits(rawBits + b.getRawBits());
	return sum;
}

Fixed Fixed::operator-(const Fixed& b)
{
	Fixed mult;
	mult.setRawBits(rawBits - b.getRawBits());
	return mult;
}

Fixed Fixed::operator*(const Fixed& b)
{
	Fixed mult;

	mult.setRawBits(((long)rawBits * b.getRawBits()) >> Fixed::fixed_point);
	return mult;
}

Fixed Fixed::operator/(const Fixed& b)
{
	Fixed div;

	div.setRawBits(((long)rawBits << Fixed::fixed_point) / b.getRawBits());
	return div;
}

//Comparison operators
bool Fixed::operator<(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() < b.getRawBits();
}

bool Fixed::operator<=(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() <= b.getRawBits();
}

bool Fixed::operator>(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() > b.getRawBits();
}

bool Fixed::operator>=(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() >= b.getRawBits();
}

bool Fixed::operator==(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() == b.getRawBits());
}

bool Fixed::operator!=(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() != b.getRawBits();
}

//increment operatotors
Fixed Fixed::operator++(Fixed& fixed, int) //post-increment
{
    Fixed tmp(fixed);
	fixed.rawBits++;
	return tmp;
}

Fixed& Fixed::operator++(Fixed& fixed) //pre-increment
{
	fixed.rawBits++;
	return fixed;
}

Fixed Fixed::operator--(Fixed& fixed, int) //post-decrement
{
	Fixed tmp(fixed);
	fixed.rawBits--;
	return tmp;
}

Fixed& Fixed::operator--(Fixed& fixed) //pre-decrement
{
	fixed.rawBits--;
	return fixed;
}




