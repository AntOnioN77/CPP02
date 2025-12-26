#include <iostream>
#include "Fixed.hpp"
#include "limits.h"
#include <cstdio>
#include <iomanip>


//Epsilon esperado 0,00390625
//	see(...)eedddddddD --> D = 1*(1/2⁸)
//
//Maxima desviacion de conversion tolerable: abs(n_fixed.toFloat() - n_float) <= epsilon/2
//
//PAra imprimir representacion binaria std::bitset<32>

int main()
{
	std::cout << "\nValores extremos representables" << std::endl;
	Fixed max_fixed; max_fixed.setRawBits(INT_MAX);
	Fixed min_fixed; min_fixed.setRawBits(INT_MIN);
	std::cout << "max_fixed:" << max_fixed << " | min_fixed:" << min_fixed << std::endl;
	Fixed epsilon; epsilon.setRawBits(1);
	std::cout << "EPSILON esperado:0,00390625"  << "| obtenido:" << epsilon << std::endl;

	//Constructors:
	std::cout << "\nTests de constructores" << std::endl;
	Fixed constr_pred;
		std::cout << "constructor predeterminado esperado 0"  << "| obtenido:" << constr_pred << std::endl;
	Fixed constr_max(max_fixed);
		std::cout << "constructor de copia esperado:" << max_fixed  << "| obtenido:" << constr_max << std::endl;
	Fixed constr_min(min_fixed);
		std::cout << "constructor de copia min esperado:" << min_fixed  << "| obtenido:" << constr_min << std::endl;
	Fixed constr_int(42);
		std::cout << "constructor int esperado:42"  << "| obtenido:" << constr_int << std::endl;
	Fixed constr_float(1.23f);
		std::cout << "constructor float esperado:1.23"  << "| obtenido:" << constr_float << std::endl;
	Fixed constr_float_(-1.23f);
		std::cout << "constructor float esperado:-1.23"  << "| obtenido:" << constr_float_ << std::endl;
	Fixed asignation = constr_float;
		std::cout << "asignacion esperado:" << constr_float  << "| obtenido:" << asignation << std::endl;

	//Tests de funciones basicas:
	std::cout << "\nTests de funciones basicas" << std::endl;

	float float_num = 0.42;
	Fixed num(float_num);
	std::cout << "toFloat() esperado:" << float_num  << "| obtenido:" << num.toFloat() << std::endl;

	int int_num = 590;
	Fixed num2(int_num);
	std::cout << "toInt() esperado:" << int_num  << "| obtenido:" << num2.toInt() << std::endl;

	num.setRawBits(1024); //1024×(1÷2^8) = 4
	std::cout << "setRawBits(1024) esperado:4"  << "| obtenido:" << num.toInt() << std::endl;
	std::cout << "getRawBits() esperado:1024"  << "| obtenido:" << num.getRawBits() << std::endl;

	//Test de operadores aritmeticos:
	std::cout << "\nTests de operadores aritmeticos" << std::endl;

	Fixed a(42.24f);
	Fixed b(2);

	Fixed result = a + b;
	std::cout << "42.24 + 2 esperado:44.24"  << "| obtenido:" << result << std::endl;
	result = a - b;
	std::cout << "42.24 - 2 esperado:40.24"  << "| obtenido:" << result << std::endl;

	// 42.24 No tiene unas representacion exacta en float, eso introduce una desviacion
	// que * y / amplifican.
	//demostraciuon:
	std::cout << "Demostracion de desviacion en multiplicacion/division:" << std::endl;
	std::cout << "(float)42.24:" << std::setprecision(20) <<(float)42.24 << std::endl;
	result = a * b;
	std::cout << "42.24 * 2 esperado:84.48"  << "| obtenido:" << result << std::endl;

	result = a / b;
	std::cout << "42.24 / 2 esperado:21.12"  << "| obtenido:" << result << std::endl;

	//Test de operadores de comparacion:
	std::cout << "\nTests de operadores de comparacion" << std::endl;
	
	a = Fixed(1.1f);
	b = Fixed(0.9f);
	Fixed c = Fixed(1.1f);
	std::cout << "Esperado:0 (false) | Obtenido:" << (a < b) << std::endl;
	std::cout << "Esperado:0 (false) | Obtenido:" << (a <= b) << std::endl;
	std::cout << "Esperado:1 (true)  | Obtenido:" << (a > b) << std::endl;
	std::cout << "Esperado:1 (true)  | Obtenido:" << (a >= b) << std::endl;
	std::cout << "Esperado:1 (true)  | Obtenido:" << (a == c) << std::endl;
	std::cout << "Esperado:0 (false) | Obtenido:" << (a != c) << std::endl;

	//Test de operadores de incremento y decremento:
	std::cout << "\nTests de operadores de incremento y decremento" << std::endl;
	a = Fixed(0);
	std::cout << "a inicial:" << a << std::endl;
	std::cout << "++a al vuelo, esperado: 0.00390625 (epsilon)"  << "| obtenido:" << ++a << std::endl;
	std::cout << "tras ++a, esperado:0.00390625"  << "| obtenido:" << a << std::endl;
	a = Fixed(0);
	std::cout << "a seteado a 0:" << a << std::endl;
	std::cout << "a++ al vuelo, esperado: 0"  << "| obtenido:" << a++ << std::endl;
	std::cout << "tras a++, esperado:0.00390625"  << "| obtenido:" << a << std::endl;
	
	//test funciones static:
	std::cout << "\nTests de funciones static" << std::endl;
	a = Fixed(500.12f);
	b = Fixed(1256.24f);
	std::cout << "min(a,b) esperado:500.12"  << "| obtenido:" << Fixed::min(a,b) << std::endl;
	std::cout << "max(a,b) esperado:1256.24"  << "| obtenido:" << Fixed::max(a,b) << std::endl;

	//


	return 0;
}
