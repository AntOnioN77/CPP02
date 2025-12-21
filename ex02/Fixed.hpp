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

	Fixed operator*(const Fixed& b);
	Fixed operator/(const Fixed& b);

	Fixed& operator++(); //No friend, miembro, debe ser miembro? es una forma adecuada de sobrecargar el operador?
	Fixed operator++(int); //post-increment
	Fixed& operator--(); //No friend, miembro, debe ser miembro? es una forma adecuada de sobrecargar el operador?
	Fixed operator--(int); //post-decrement

		
	Fixed operator-(const Fixed& b);
	Fixed operator+(const Fixed& b);
	bool operator<(const Fixed& b); //ERROR, operadores de comparacion deberia retornar boleano o int
	bool operator<=(const Fixed& b);
	bool operator>( const Fixed& b);
	bool operator>=(const Fixed& b);
	bool operator==(const Fixed& b);
	bool operator!=(const Fixed& b);
};



std::ostream& operator<<(std::ostream& os, const Fixed& n);


#endif