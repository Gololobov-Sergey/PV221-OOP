#pragma once

class Fraction
{

	int numerator;
	int denominator;

	void nod()
	{

	}

public:
	Fraction() : Fraction(0)	{ }

	explicit Fraction(int numerator) : Fraction(numerator, 1) {}

	Fraction(int numerator, int denominator)
	{
		this->nod();
		this->numerator = numerator;
		this->denominator = denominator;
	}

	Fraction sum(Fraction f)
	{
		Fraction res;
		res.numerator = this->numerator * f.denominator + this->denominator * f.numerator;
		res.denominator = this->denominator * f.denominator;
		res.nod();
		return res;
	}


	Fraction normal()
	{
		///
		return *this;
	}

	void print()
	{
		cout << numerator << "/" << denominator << endl;
	}
};
