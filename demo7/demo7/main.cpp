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

// ��ʼ����Ա����   (��̬���� ��Ҫ�������ʼ�� �������ڶ������)
int Car::m_price = 0;

int main()
{
	Car car1;
	car1.m_price += 100;
	Car::m_price += 3000;

	car1.run();
	return 0;
}