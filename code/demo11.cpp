#include <iostream>
using namespace std;

namespace cpx
{
	class Person
	{
		int m_age;
	};
}

namespace csgo
{
	class Person
	{
		int m_height;
	};
}

struct Person
{
	int m_age;
	void run()
	{
		cout << "Run" << endl;
	}
};

struct Student : Person
{
	int m_score;
	void study()
	{
		cout << "Study" << endl;
	}
};

struct Worket : Person 
{
	int m_salary;
	Worket(int salary): m_salary(salary) // 初始化列表
	{
		
	}
	void work()
	{
		cout << "Work" << endl;
	}
};

int main()
{
	Person pc;

	csgo::Person pcx;
	
	return 0;
}