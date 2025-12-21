#include <iostream>
#include "Fixed.hpp"

int main( void ) {
Fixed		a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

/* 
int main() {
    std::cout << std::boolalpha;

    // Multiplicación
    Fixed b = Fixed(5.05f) * Fixed(2);
    std::cout << "Multiplicacion (5.05f * 2): esperado: 10.1016 ; obtenido: " << b << std::endl;

    // División
    Fixed c = Fixed(10) / Fixed(4);
    std::cout << "Division (10 / 4): esperado: 2.5 ; obtenido: " << c << std::endl;

    // Suma
    Fixed d = Fixed(3.25f) + Fixed(2.75f);
    std::cout << "Suma (3.25f + 2.75f): esperado: 6 ; obtenido: " << d << std::endl;

    // Resta
    Fixed e = Fixed(5) - Fixed(2.5f);
    std::cout << "Resta (5 - 2.5f): esperado: 2.5 ; obtenido: " << e << std::endl;

    // Incrementos (pre y post)
    Fixed f_inc;
    std::cout << "Valor inicial f_inc: esperado: 0 ; obtenido: " << f_inc << std::endl;
    Fixed preInc = ++f_inc;
    std::cout << "Pre-increment (++f_inc): esperado: 0.00390625 ; obtenido: " << preInc << std::endl;
    std::cout << "Valor despues de pre-increment: esperado: 0.00390625 ; obtenido: " << f_inc << std::endl;
    Fixed postInc = f_inc++;
    std::cout << "Post-increment (f_inc++): esperado: 0.00390625 ; obtenido: " << postInc << std::endl;
    std::cout << "Valor despues de post-increment: esperado: 0.0078125 ; obtenido: " << f_inc << std::endl;

    // Decrementos (pre y post)
    Fixed f_dec(1.0f);
    std::cout << "Valor inicial f_dec: esperado: 1 ; obtenido: " << f_dec << std::endl;
    Fixed preDec = --f_dec;
    std::cout << "Pre-decrement (--f_dec): esperado: 0.99609375 ; obtenido: " << preDec << std::endl;
    std::cout << "Valor despues de pre-decrement: esperado: 0.99609375 ; obtenido: " << f_dec << std::endl;
    Fixed postDec = f_dec--;
    std::cout << "Post-decrement (f_dec--): esperado: 0.99609375 ; obtenido: " << postDec << std::endl;
    std::cout << "Valor despues de post-decrement: esperado: 0.9921875 ; obtenido: " << f_dec << std::endl;

    // Comparaciones
    Fixed cmp1(4);
    Fixed cmp2(2);
    // '>' operator: true and false cases
    std::cout << "Comparacion (4 > 2): esperado: true ; obtenido: " << (cmp1 > cmp2) << std::endl;
    std::cout << "Comparacion (2 > 4): esperado: false ; obtenido: " << (cmp2 > cmp1) << std::endl;
    // '<' operator: true and false cases
    std::cout << "Comparacion (2 < 4): esperado: true ; obtenido: " << (cmp2 < cmp1) << std::endl;
    std::cout << "Comparacion (4 < 2): esperado: false ; obtenido: " << (cmp1 < cmp2) << std::endl;
    // '>=' operator: true and false cases
    std::cout << "Comparacion (4 >= 4): esperado: true ; obtenido: " << (cmp1 >= Fixed(4)) << std::endl;
    std::cout << "Comparacion (2 >= 4): esperado: false ; obtenido: " << (cmp2 >= cmp1) << std::endl;
    // '<=' operator: true and false cases
    std::cout << "Comparacion (2 <= 4): esperado: true ; obtenido: " << (cmp2 <= cmp1) << std::endl;
    std::cout << "Comparacion (4 <= 2): esperado: false ; obtenido: " << (cmp1 <= cmp2) << std::endl;

    // Igualdad / Diferencia
    Fixed eq1(3.5f);
    Fixed eq2(3.5f);
    Fixed eq3(3.25f);
    Fixed neq(2.5f);
    // '==' operator: true and false cases
    std::cout << "Igualdad (3.5 == 3.5): esperado: true ; obtenido: " << (eq1 == eq2) << std::endl;
    std::cout << "Igualdad (3.5 == 3.25): esperado: false ; obtenido: " << (eq1 == eq3) << std::endl;
    // '!=' operator: true and false cases
    std::cout << "Desigualdad (3.5 != 2.5): esperado: true ; obtenido: " << (eq1 != neq) << std::endl;
    std::cout << "Desigualdad (3.5 != 3.5): esperado: false ; obtenido: " << (eq1 != eq2) << std::endl;

    return 0;
} */