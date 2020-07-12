#include <iostream>
using namespace std;

class Car
{
public:
	static int m_price;
	void run()
	{
		cout << "m price: "<< this->m_price << endl;
	}
};

// 初始化成员变量   (静态变量 需要在外面初始化 不依赖于对象存在)
int Car::m_price = 0;

int main()
{
	Car car1;
	car1.m_price += 100;
	Car::m_price += 3000;

	car1.run();
	return 0;
}