#pragma once
class Fraction
{
public:
	Fraction(int numerator, int denominator);

	Fraction();

	void Print() const;

	Fraction& Add(const Fraction& other);

	Fraction& Add(int value);

	Fraction& Substract(const Fraction& other);

	Fraction& Substract(int value);

	Fraction& Multiply(const Fraction& other);

	Fraction& Multiply(int value);

private:
	int m_numerator;
	int m_denominator;

	void Reduce();
};

