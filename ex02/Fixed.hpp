#include <ostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
	int rawBits;
	static const int fixed_point = 8;

	public:
	Fixed();
	Fixed(const int raw);
	Fixed(const float  num);
	Fixed(const Fixed& src);
	~Fixed();
	Fixed& operator=(const Fixed& src);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int get_point();

	friend Fixed operator*(const Fixed& a, const Fixed& b);
	friend Fixed operator/(const Fixed& a, const Fixed& b);

	friend Fixed& operator++(Fixed& fixed); //No friend, miembro, debe ser miembro? es una forma adecuada de sobrecargar el operador?
	friend Fixed operator++(Fixed& fixed, int); //post-increment
	friend Fixed& operator--(Fixed& fixed); //No friend, miembro, debe ser miembro? es una forma adecuada de sobrecargar el operador?
	friend Fixed operator--(Fixed& fixed, int); //post-decrement
};

	
	Fixed operator-(const Fixed& a, const Fixed& b);
	Fixed operator+(const Fixed& a, const Fixed& b);
	bool operator<(const Fixed& a, const Fixed& b); //ERROR, operadores de comparacion deberia retornar boleano o int
	bool operator<=(const Fixed& a, const Fixed& b);
	bool operator>(const Fixed& a, const Fixed& b);
	bool operator>=(const Fixed& a, const Fixed& b);
	bool operator==(const Fixed& a, const Fixed& b);
	bool operator!=(const Fixed& a, const Fixed& b);

std::ostream& operator<<(std::ostream& os, const Fixed& n);


#endif