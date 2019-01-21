//============================================================================
// Name        : destruct.cpp
// Author      : zhangfj
// Version     :
// Copyright   : Your copyright notice
// Description : 演示父类的析构函数应该声明为虚函数
//============================================================================

#include <iostream>

class Animal
{
public:
	std::string name;
	Animal(std::string theName);
	virtual ~Animal();  //使用多态，析构函数必须声明为虚函数
};

Animal::Animal(std::string theName)
{
	name=theName;
	std::cout << name << "的爸爸出生了" << std::endl;
}

Animal::~Animal()
{
	std::cout << name << "的爸爸死亡了" << std::endl;
}

class Cat : public Animal
{
public:
	Cat(std::string theName);
	~Cat();
};

Cat::Cat(std::string theName) : Animal(theName)
{
	std::cout << name << "自己出生了" << std::endl;
}

Cat::~Cat()
{
	std::cout << name << "自己死亡了" << std::endl;
}

int main() {
	Animal *pet;
	pet=new Cat("加菲");
	delete pet;
	return 0;
}
