//============================================================================
// Name        : optimize_opeator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 优化重载有理数加法操作符
//============================================================================

#include <iostream>
#include <stdio.h>

class Rational
{
public:
	Rational(void);
	Rational(int numerator,int denominator);
	~Rational();

	void print(void);
	Rational operator +(Rational rhs);	//rhs=rigth hand size
	Rational operator -(Rational rhs);
private:
	int numerator;
	int denominator;
};

Rational::Rational(void)
{
	numerator=0;
	denominator=0;
}

Rational::Rational(int numerator,int denominator)
{
	this->numerator=numerator;
	this->denominator=denominator;
}

Rational::~Rational()
{
	;
}

void Rational::print()
{
	if((numerator % denominator) == 0)
	{
		std::cout << (numerator/denominator) << std::endl;
	}
	else
	{
		std::cout << numerator << "/" <<denominator << std::endl;
	}
}

Rational Rational::operator +(Rational rhs)
{
	int a,b,c,d,e,f;
	a=numerator;
	b=denominator;
	c=rhs.numerator;
	d=rhs.denominator;
	e=a*d+c*b;
	f=b*d;
	return Rational(e,f);
	//可以使用最大公约数对分数进行简化
}

Rational Rational::operator -(Rational rhs)
{
	int a,b,c,d,e,f;
	c=-rhs.numerator;
	d=rhs.denominator;
	return operator +(Rational(c,d));
}

int main() {
	Rational ra1(4,10);
	Rational ra2(2,10);
	Rational ra3;
	Rational ra4;
	ra3=ra1+ra2;
	ra3.print();
	ra4=ra1-ra2;
	ra4.print();
	return 0;
}
