//============================================================================
// Name        : overload_operator.cpp
// Author      : zhangfj
// Version     :
// Copyright   : Your copyright notice
// Description : 对加号的重载，支持负数的加法
//============================================================================

#include <iostream>

class Complex
{
public:
	int real;
	int image;

	Complex(void)
	{
		real=0;
		image=0;
		std::cout << "create complex=(" << real << "," << image << ")" << std::endl;
	}

	Complex(int i,int j)
	{
		real=i;
		image=j;
		std::cout << "create complex=(" << real << "," << image << ")" << std::endl;
	}

	~Complex()
	{
		;
	}

	void complex_show(void)
	{
		std::cout << "complex=(" << real << "," << image << ")" << std::endl;
	}
	Complex* operator + (Complex &complex1);
};

Complex* Complex::operator +(Complex &complex1)
{
	this->real+=complex1.real;
	this->image+=complex1.image;
	complex_show();
	return this;
}

int main() {
	Complex complex1(10,20);
	Complex complex2(20,10);
	Complex* p1;
	p1=complex1+complex2;
	std::cout << "new complex,real=" << (*p1).real << ",image=" << (*p1).image << std::endl;
	return 0;
}

