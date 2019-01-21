//============================================================================
// Name        : polymorphism_01.cpp
// Author      : zhangfj
// Version     :
// Copyright   : Your copyright notice
// Description : 演示多态产生的需求原因，以及简单的多态
//============================================================================

#include <iostream>

class Pet
{
public:
	std::string name;
	Pet(std::string theName);
	virtual ~Pet();		//使用多态，析构函数必须声明为虚函数
	virtual void eat(void);
};

Pet::Pet(std::string theName)
{
	name=theName;
	std::cout << name << "出生了" << std::endl;
}
Pet::~Pet()
{
	std::cout << name << "死了" << std::endl;
}
void Pet::eat()
{
	std::cout << name << "会吃东西" << std::endl;
}

class Bird : public Pet
{
public:
	Bird(std::string theName);
	~Bird();
	 void eat(void);
};

Bird::Bird(std::string theName):Pet(theName)
{
	;
}

Bird::~Bird()
{
	;
}

void Bird::eat(void)
{
	std::cout << name << "喜欢吃虫子" << std::endl;
}

class Dog : public Pet
{
public:
	Dog(std::string theName);
	~Dog();
	void eat(void);
};

Dog::Dog(std::string theName) : Pet(theName)
{
	;
}

Dog::~Dog()
{
	;
}

void Dog::eat()
{
	std::cout << name << "喜欢吃屎" << std::endl;
}


int main() {

	Pet pig("猪");
	pig.eat();

	Pet *bird1;
	bird1=new Pet("鸟");
	bird1->eat();
	delete bird1;

	Bird *bird;
	bird=new Bird("大鹅");
	bird->eat();
	delete bird;

	Pet *pet;
	pet=new Bird("唐老鸭");  //父类指针指向了子类，则只能获取父类的属性方法，除非父类使用了虚函数,使用多态
	pet->eat();
	delete pet;

	pet=new Dog("阿狗");
	pet->eat();
	delete pet;

	return 0;
}
