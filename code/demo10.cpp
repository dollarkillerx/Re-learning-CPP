#include <iostream>
using namespace std;

struct Person
{
	int m_age;
	int m_money;

	Person()
	{
		this->m_money = 12;
		this->m_age = 33;
	}
	
	Person(int age,int money)
	{
		this->m_age = age;
		this->m_money = money;
	}
};

int main()
{
	Person hello = Person(1, 2);
	Person *phello =new  Person(1,2);
	Person pc(1, 3);

	Person* px = new Person{};
	cout << px->m_money << endl;
	cout << px->m_age << endl;
	return 0;
}