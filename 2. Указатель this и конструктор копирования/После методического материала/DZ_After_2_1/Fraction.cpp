#include <iostream>
#include <numeric>

#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
	: m_numerator{ numerator }, m_denominator{ denominator }
{
	if (m_denominator == 0)
	{
		throw std::invalid_argument("Denominator cannot be zero.");
	}

	Reduce();
}

Fraction::Fraction() : Fraction(0, 1)
{
}

void Fraction::Print() const
{
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}

Fraction& Fraction::Add(const Fraction& other)
{
	m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
	m_denominator *= other.m_denominator;

	Reduce();

	return *this;
}

Fraction& Fraction::Add(int value)
{
	return (*this).Add(Fraction(value, 1));
}

Fraction& Fraction::Substract(const Fraction& other)
{
	m_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
	m_denominator *= other.m_denominator;

	Reduce();

	return *this;
}

Fraction& Fraction::Substract(int value)
{
	return (*this).Substract(Fraction(value, 1));
}

Fraction& Fraction::Multiply(const Fraction& other)
{
	m_numerator *= other.m_numerator;
	m_denominator *= other.m_denominator;

	Reduce();

	return *this;
}

Fraction& Fraction::Multiply(int value)
{
	return (*this).Multiply(Fraction(value, 1));
}

void Fraction::Reduce()
{
	int gcd = std::gcd(m_numerator, m_denominator);

	m_numerator /= gcd;
	m_denominator /= gcd;

	if (m_denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
}
