#include <iostream>
using namespace std;

struct Person
{
	int m_age;
	void get_age(Person &person)
	{
		cout << person.m_age << endl;
	}
};


int main()
{
	Person s1 = Person{ 16 };
	s1.get_age(s1);
}