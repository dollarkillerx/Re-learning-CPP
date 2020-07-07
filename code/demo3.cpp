// 默认参数 与 汇编底层分析
#include <iostream>
using namespace std;

int sum(int v1,int v2 = 5) // v2 default value
{
	return v1 + v2;
}

int add(int a = 16, int b = 18);

void test(int a)
{
	cout << "test(int) - " << a << endl;
}

void func(int vv1,void (*a)(int a) = test)
{
	a(vv1);
}

int main()
{
	cout << "12 + default:  " << sum(12) << endl;
	cout << "12 + 22: " << sum(12, 22) << endl;

	cout << endl;

	int(*p)(int a,int b) = add;

	cout << "a + b :" << p(12, 23) << endl;

	func(12, test);
	return 0;
}

int add(int a,int b)
{
	return a + b;
}