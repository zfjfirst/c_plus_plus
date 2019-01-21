//============================================================================
// Name        : acess_friend.cpp
// Author      : zhangfj
// Version     :
// Copyright   : Your copyright notice
// Description : 使用protected保护变量，使用friend进行后门访问
//============================================================================

#include <iostream>
#include <string>

class Lovers
{
public:
	Lovers(void);
	void kiss(Lovers *lover);
protected:	//父类和子类可以访问
	int mouth;
	friend class Other;	//朋友类可以访问
};

Lovers::Lovers(void)
{
	mouth=0;
}
void Lovers::kiss(Lovers *lover)
{
	lover->mouth+=1;
	std::cout << "kissing mouth=" << lover->mouth << std::endl;
}

class Boy:public Lovers
{
public:
	Boy(void);
};

Boy::Boy()
{
	mouth=10;
}

class Girl:public Lovers
{
public:
	Girl(void);
};

Girl::Girl()
{
	mouth=20;
}

class Other
{
public:
	void gokiss(Lovers *lover);
};

void Other::gokiss(Lovers *lover)
{
	lover->mouth=100;
	std::cout << "other kiss,mouth=" << lover->mouth << std::endl;
}

int main() {
	Girl girl;
	Boy	boy;

	std::cout << "girl kiss" << std::endl;
	girl.kiss(&boy);
	std::cout << "boy kiss" << std::endl;
	boy.kiss(&girl);

	Other other;
	std::cout << "other kiss" << std::endl;
	other.gokiss(&girl);

	return 0;
}
