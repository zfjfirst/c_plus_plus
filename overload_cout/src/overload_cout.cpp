//============================================================================
// Name        : rational_operator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 重载有理数的加法，能够支持连加(a+b+c+d)
//               重载<<操作符，使其能够输出有理数
//============================================================================

#include <iostream>
#include <stdio.h>

class Rational
{
public:
	int denominator;	//分母
	int numerator;	//分子

	Rational(void);			//构造函数重载
	Rational(int numerator,int denominator);
	~Rational();		//析构函数定义了，必须实现，否则编译报错
	void show_rational(void);
	Rational & operator+(Rational & addend);	//返回值是引用，相当与返回对象
	friend std::ostream & operator <<(std::ostream & os,Rational rhs);
};

Rational::Rational()
{
	this->numerator=0;
	this->denominator=0;
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

Rational & Rational::operator +(Rational & addend)
{
	int mid1=0;
	int mid2=0;

	//这个版本存在一个bug，就是a+b计算完毕后，将a的值也修改了
	mid1=numerator * addend.denominator;
	mid2=addend.numerator * denominator;
	numerator=mid1+mid2;
	denominator=addend.denominator * denominator;
	return *this;		//返回对象的引用，相当于返回对象
}

void Rational::show_rational()
{
	if((numerator % denominator) == 0)
	{
		printf("%d\n",numerator/denominator);
	}
	else
	{
		printf("%d/%d\n",numerator,denominator);
	}
}

std::ostream & operator <<(std::ostream & os,Rational rhs);
int main() {
	Rational ra1=Rational(2,4);
	Rational ra2=Rational(3,4);
	Rational ra4=Rational(3,4);
	Rational ra5=Rational(8,4);
	Rational ra3;
	ra3=ra1+ra2+ra4+ra5;
	ra3.show_rational();
	std::cout << ra5;		//重载"<<"，使其能够输出Rational对象

	return 0;
}

std::ostream & operator <<(std::ostream & os,Rational rhs)
{
	os << rhs.numerator <<"/" << rhs.denominator;
}
