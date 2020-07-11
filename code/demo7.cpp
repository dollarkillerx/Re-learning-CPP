#include <iostream>
using namespace std;

class Person // 默认成员 private
{
public:
	// 成员变量
	int age;
	// 成员函数(function)
	void run()
	{
		cout << "Person::run()" << endl;
	}
};

struct person_struct // 默认成员 public
{
	int m_age; // 成员属性
	void run()
	{
		cout << "person_struct::run()" << endl;
	}
};


struct Car
{
	int m_price;
};

int main()
{
	Person man = Person{};
	man.age = 1;
	man.run();
	
	person_struct pr =  person_struct{ 1 };
	pr.run();

	person_struct* ppr = &pr;
	cout << "age: " << ppr->m_age << endl;
	
	return 0;
}