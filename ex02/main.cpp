#include <iostream>
#include "Fixed.hpp"
#include "limits.h"
#include <bitset> 

/* int main( void ) {
Fixed		a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, (const Fixed&)b ) << std::endl;

return 0;
}

 */


/* 

void fixed_int_test(Fixed& result, int expected)
{
	if(result.toInt() == expected)
		std::cout << "Esperado:" << expected << "Obtenido:" << result << std::endl;
	else
		std::cout << "\033[31m" <<  "Esperado:" << expected << "Obtenido:" << result << std::endl;
}

void fixed_float_test(Fixed& result, float expected)
{
	if(result.toInt() == expected)
		std::cout << "Esperado:" << expected << "Obtenido:" << result << std::endl;
	else
		std::cout << "\033[31m" <<  "Esperado:" << expected << "Obtenido:" << result << std::endl;
}
 */
/*
	Epsilon esperado 0,00390625
see(...)eedddddddD --> D = 1*(1/2⁸)

	Error maximo tolerable: abs(n_fixed.toFloat() - n_float) <= epsilon/2
*/
int main()
{
	std::cout << "Algunas representaciones interesantes" << std::endl;
	Fixed one(1);
	std::cout << "one.getRawBits:" << std::bitset<32>(one.getRawBits()) << std::endl;
	Fixed minus_one(-1);
	std::cout << "minus_one.getRawBits:" << std::bitset<32>(minus_one.getRawBits()) << std::endl;
	
	Fixed cero(0);
	std::cout << "cero.getRawBits:" << std::bitset<32>(cero.getRawBits()) << std::endl;
	Fixed half(0.5f);
	std::cout << "half.getRawBits:" << std::bitset<32>(half.getRawBits()) << std::endl;

	std::cout << "\nValores extremos representables" << std::endl;
	Fixed max_fixed; max_fixed.setRawBits(INT_MAX);
	std::cout << "max_fixed.getRawBits:" << std::bitset<32>(max_fixed.getRawBits()) << std::endl;
	Fixed min_fixed; min_fixed.setRawBits(INT_MIN);
	std::cout << "min_fixed.getRawBits:" << std::bitset<32>(min_fixed.getRawBits()) << std::endl;
	std::cout << "max_fixed:" << max_fixed << " | min_fixed:" << min_fixed << std::endl;
	Fixed epsilon; epsilon.setRawBits(1);
	std::cout << ((epsilon.toFloat() == 0.00390625f)?"\033[32m":"\033[31m")
			<< "EPSILON esperado:0,00390625"  << "| obtenido:" << epsilon << std::endl;

	//Constructors:
	std::cout << "\nTests de constructores" << std::endl;
	Fixed constr_pred;
		std::cout << ((constr_pred.toFloat() == 0.0F)?"\033[32m":"\033[31m")
			<< "constructor predeterminado esperado 0"  << "| obtenido:" << constr_pred << std::endl;
	Fixed constr_max(max_fixed);
		std::cout << ((constr_max.toFloat() == 8388608.0F)?"\033[32m":"\033[31m")
			<< "constructor int max esperado 8388608"  << "| obtenido:" << constr_max << std::endl;
	Fixed constr_min(min_fixed);
		std::cout << ((constr_min.toFloat() == -8388608.0F)?"\033[32m":"\033[31m")
			<< "constructor int min esperado -8388608"  << "| obtenido:" << constr_min << std::endl;
	
	
/* 	Fixed constr_float_()
	Fixed constr_float_()
	Fixed constr_float_()
	Fixed constr_float_() */


}