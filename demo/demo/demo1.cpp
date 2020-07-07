#include <iostream>
using namespace std; // 引入命名空间

void test1();
void test2();
int add(int a, int b);
double add(double a, double b);

int main()
{
	test1();
	test2();
	return 0;
}

void test2()
{
	cout << "1 + 1 = " << add(1, 1) << endl;
	cout << "1 + 2.6 = "<< add(1.0,2.6) << endl;
	// 函数重载使用 name margling 技术  编译时需要函数重载的函数名称会发生改变
	// 举一个栗子 (不同的编译器生成规则不一样)
	// add(int a ,int b) => add_int(int a,int b) 
	// add(double a,double b) => add_double(double a,double b)
}

int add (int a,int b)
{
	return a + b;
}
double add (double a,double b)
{
	return a + b;
}

void test1()
{
	cout << "Hello World" << endl << "Fuck you" << endl; // 好像管道

	int age;
	cin >> age;
	if (age == 0)
	{
		cout << "you not in number" << endl;
	}
	else
	{
		cout << "you in: " << age << endl;
	}

	// cout, console out
	// cin, console in
	// << 左移运算符
}

