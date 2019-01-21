//============================================================================
// Name        : static_attibute.cpp
// Author      : zhangfj
// Version     :
// Copyright   : Your copyright notice
// Description : 静态属性和形态方法存储在静态区，类似于全局变量
//   			 类定义后就可以调用。程序中的{}覆盖的区域，类似于函数的区域
//============================================================================

#include <iostream>

class Pet
{
public:
	static void getCount();
	Pet(void);
	~Pet(void);
private:
	static int count; //remember to init
};

int Pet::count=0; //1）分配静态内存；2）初始化

Pet::Pet()
{
	std::cout << "创造了一个宠物" << std::endl;
	count++;
}

Pet::~Pet()
{
	std::cout << "毁灭了一个宠物" << std::endl;
	count--;
}

void Pet::getCount()
{
	std::cout << "宠物的个数是" << count << std::endl;
}

class Dog:Pet
{
	;
};

int main() {
	Dog dog;
	Pet::getCount(); //call static methord,not "dog.getCount()"
	{
		Dog dog1;
		Dog dog2;
		Pet::getCount();
	}
	Pet::getCount();
	return 0;
}
