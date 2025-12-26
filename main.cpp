#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <bitset> 

static const double EPS = 0.00390625; // epsilon for Fixed (8 fractional bits)

static const std::string GREEN = "\033[32m";
static const std::string RED = "\033[31m";
static const std::string RESET = "\033[0m";
static const std::string CHECK = "\u2713"; // ✓
static const std::string CROSS = "\u2717"; // ✗

bool approxEqual(const Fixed& value, double expected, double eps = EPS)
{
    double v = value.toFloat();
    return std::fabs(v - expected) <= eps;
}

void printResult(const std::string& testName, double expected, const Fixed& obtained, double eps = EPS)
{
    bool ok = approxEqual(obtained, expected, eps);
    std::cout << std::left << std::setw(40) << testName;
    std::cout << "esperado: " << std::setw(10) << expected;
    std::cout << "obtenido: " << std::setw(12) << obtained << " ";
    if (ok)
        std::cout << GREEN << CHECK << RESET << std::endl;
    else
        std::cout << RED << CROSS << RESET << std::endl;
}

void showBoolTest(const std::string& name, bool expected, bool got)
{
    std::cout << std::left << std::setw(40) << name << "esperado: " << std::setw(6) << (expected?"true":"false")
              << "obtenido: " << std::setw(6) << (got?"true":"false") << " ";
    if (expected == got)
        std::cout << GREEN << CHECK << RESET << std::endl;
    else
        std::cout << RED << CROSS << RESET << std::endl;
}



int main() {
    std::cout << std::boolalpha;

	std::cout << "Algunas representaciones interesantes" << std::endl;
	Fixed one(1);
	std::cout << "one.getRawBits:" << std::bitset<32>(one.getRawBits()) << std::endl;
	Fixed minus_one(-1);
	std::cout << "minus_one.getRawBits:" << std::bitset<32>(minus_one.getRawBits()) << std::endl;
	
	Fixed cero(0);
	std::cout << "cero.getRawBits:" << std::bitset<32>(cero.getRawBits()) << std::endl;
	Fixed half(0.5f);
	std::cout << "half.getRawBits:" << std::bitset<32>(half.getRawBits()) << std::endl;

    // Tests visuales con checks
    printResult("Multiplicacion (5.05f * 2)", 10.1015625 /* 5.05*2 rounded to fixed */, Fixed(5.05f) * Fixed(2));

    // Para division usamos EPS = 0.00390625 como indicas
    printResult("Division (10 / 4)", 2.5, Fixed(10) / Fixed(4));

    printResult("Suma (3.25f + 2.75f)", 6.0, Fixed(3.25f) + Fixed(2.75f));
    printResult("Resta (5 - 2.5f)", 2.5, Fixed(5) - Fixed(2.5f));

    // Incrementos
    Fixed f_inc;
    printResult("Valor inicial f_inc", 0.0, f_inc);
    Fixed preInc = ++f_inc;
    printResult("Pre-increment (++f_inc)", 0.00390625, preInc);
    printResult("Valor despues de pre-increment", 0.00390625, f_inc);
    Fixed postInc = f_inc++;
    printResult("Post-increment (f_inc++) (valor devuelto)", 0.00390625, postInc);
    printResult("Valor despues de post-increment", 0.0078125, f_inc);

    // Decrementos
    Fixed f_dec(1.0f);
    printResult("Valor inicial f_dec", 1.0, f_dec);
    Fixed preDec = --f_dec;
    printResult("Pre-decrement (--f_dec)", 0.99609375, preDec);
    printResult("Valor despues de pre-decrement", 0.99609375, f_dec);
    Fixed postDec = f_dec--;
    printResult("Post-decrement (f_dec--) (valor devuelto)", 0.99609375, postDec);
    printResult("Valor despues de post-decrement", 0.9921875, f_dec);

    // Comparaciones: mostramos verdadero/falso y un check si coincide con lo esperado
    std::cout << std::endl;

    Fixed cmp1(4);
    Fixed cmp2(2);
    showBoolTest("Comparacion (4 > 2)", true, (cmp1 > cmp2));
    showBoolTest("Comparacion (2 > 4)", false, (cmp2 > cmp1));
    showBoolTest("Comparacion (2 < 4)", true, (cmp2 < cmp1));
    showBoolTest("Comparacion (4 < 2)", false, (cmp1 < cmp2));
    showBoolTest("Comparacion (4 >= 4)", true, (cmp1 >= Fixed(4)));
    showBoolTest("Comparacion (2 >= 4)", false, (cmp2 >= cmp1));
    showBoolTest("Comparacion (2 <= 4)", true, (cmp2 <= cmp1));
    showBoolTest("Comparacion (4 <= 2)", false, (cmp1 <= cmp2));

    std::cout << std::endl;
    Fixed eq1(3.5f);
    Fixed eq2(3.5f);
    Fixed eq3(3.25f);
    Fixed neq(2.5f);
    showBoolTest("Igualdad (3.5 == 3.5)", true, (eq1 == eq2));
    showBoolTest("Igualdad (3.5 == 3.25)", false, (eq1 == eq3));
    showBoolTest("Desigualdad (3.5 != 2.5)", true, (eq1 != neq));
    showBoolTest("Desigualdad (3.5 != 3.5)", false, (eq1 != eq2));

    return 0;
}