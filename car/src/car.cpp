//============================================================================
// Name        : car.cpp
// Author      : zhangfj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
using namespace std;

class Car
{
public:
	int wheel;
	int gas;
	std::string color;
	std::string brand;

	Car(void);
	~Car(void);
	void showcar();
	void carrun();
	void addgas(int num);
};

Car::Car(void)
{
	wheel=4;
	gas=20;
	color="yello";
	brand="lanbo";
}

Car::~Car(void)
{
	cout << "clean the car" << endl;
}

void Car::carrun()
{
	while(true)
	{
		if(gas >0)
		{
			cout << "car is run:" << gas << endl;
			gas--;
		}
		else
		{
			cout << "gas is null" << endl;
			break;
		}
		usleep(1000000);
	}

}
void Car::showcar()
{
	std::cout <<"show my car:wheel=" << wheel
			<<",color="<<color
			<<",brand="<<brand<<std::endl;
}

void Car::addgas(int num)
{
	cout << "gas before=" <<gas << endl;
	gas+=num;
	cout << "gas after=" << gas << endl;
}

int main() {
	Car mycar;
	mycar.showcar();
	mycar.carrun();
	mycar.addgas(10);
	return 0;
}
