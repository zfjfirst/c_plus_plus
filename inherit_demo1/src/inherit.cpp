//============================================================================
// Name        : inherit.cpp
// Author      : zhangfj
// Version     :
// Copyright   : Your copyright notice
// Description : 父类构造函数携带参数，子类如何写构造函数;
//				 继承时构造函数和析构函数的执行顺序;
//============================================================================

#include <iostream>
#include <string>

class Animal
{
public:
	std::string mouth;
	std::string color;
	std::string name;

	Animal(std::string theName);
	~Animal(void);
	void eat(void);
	void sleep(void);
};

void Animal::eat(void)
{
	std::cout << "I can eat" << std::endl;
}

void Animal::sleep(void)
{
	std::cout << "I can sleep" << std::endl;
}

Animal::Animal(std::string theName)
{
	this->name=theName;
	this->color="black";
	std::cout << "construct an animal,color=" << this->color
			<<",name=" << name << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "destruct an animal,color=" << this->color << std::endl;
}


class Pig:public Animal
{
public:
	Pig(std::string theName);
	~Pig(void);
	void climb(void);
	void eat(void);
};


Pig::Pig(std::string theName):Animal(theName)
{
	this->color="white";
	this->name="zhaodd";
	std::cout << "construct a pig,color=" << this->color
			<< ",name=" << name << std::endl;
}

Pig::~Pig()
{
	std::cout << "destruct a pig,color=" << this->color << std::endl;
}
void Pig::climb()
{
	std::cout << "pig can climb tree" << std::endl;
}

void Pig::eat(void)
{
	std::cout << "pig overwrite eat" << std::endl;
}

class Bird:public Animal
{
public:
	Bird(std::string myName);
	void fly(void);
};

Bird::Bird(std::string myName):Animal(myName)
{
	;
}

void Bird::fly(void)
{
	std::cout << "bird can fly" << std::endl;
}

int main() {
	Pig pig("zhangfj");
	pig.eat();
	pig.climb();

	Bird bird("long");
	bird.eat();
	bird.fly();
	return 0;
}
