#include <iostream>

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom)
        : numerator{ num }, denominator{ denom }
    {
        std::cout << "Fraction constructed for " << this << '\n';
    }
    Fraction() : Fraction(1, 1) {}
    Fraction(const Fraction& fract)
        : numerator{ fract.numerator }, denominator{ fract.denominator }
    {
        std::cout << "Fraction copy constructed for " << this << '\n';
    } 
    ~Fraction() { std::cout << "Fraction destructed for " << this << '\n'; }
    void print()
    {
        std::cout << '(' << numerator << " / " << denominator << ")";
    }
};

int main()
{
    /*Создаем и инициализируем значениями числителя и знаменателя экземпляр Fraction - a*/
    Fraction a{ 2,3 };
    /*Создаем и инициализируем текущим значением экземпляра a, экземпляр Fraction - b*/
    Fraction b{ a };

    std::cout << "a = ";
    a.print();
    std::cout << "\nb = ";
    b.print();
    std::cout << '\n';

    return 0;
}