#include <iostream>
using namespace std;

void test1();
int test2();

int main()
{
	test1();
	int c = test2();
	cout << "c test2: " << c << endl;

	int a = 18;
	int b = 32;

	if (a == b)
	{
		printf("a = b");
	}else
	{
		printf("a != b");
	}
	
	return 0;
}

void test1()
{
	int a = 1;
	int b = 2;
	int c = a + b;
}

int test2()
{
	int a = 1;
	int b = 2;
	int c = a + b;
	return c;
}
