// inline function
// 使用inline 修饰函数的什么或者实现 可以使其变成内联函数
// 建议声明和实现都添加inline修饰符
// 特点
	// 编译器会将函数调用直接展开为函数体代码  (代码会膨胀)
	// 函数调用的代价 会开辟栈空间  然后回收栈空间   内联函数 就不存在栈空间开辟
	// inline只是建议编译器 内联  还要看具体情况
inline void hello();

#include <iostream>
using namespace std;

struct Data
{
	int year;
	int month;
	int day;
};

int main()
{
	hello();
	hello();

	int a = 1;
	int b = 2;
	(a =  b) = 88;
	cout << "a : " << a << " b: " << b << endl;

	(a < b ? a : b) = 88;
	cout << "a : " << a << " b: " << b << endl;


	// count 定义常量
	const int agec = 10; // 定义后不可修改

	//const Data d = Data{ 12,12,12 };
	const Data d = { 12,12,12 };
	//d.day = 12;  const 后 不可修改
	//d.month = 1;
	//d.year = 12;


	
	Data cpx = { 1,2,4 };
	Data* pa = &cpx;
	pa->month = 12;
	(*pa).day = 33;
	cout << "a month: " << pa->month << " year: " << pa->year << endl;


	// what ???
	int age = 10;
	const int* p0 = &age;
	int const* p1 = &age;
	int* const p2 = &age;
	const int* const p3 = &age;
	int const* const p4 = &age;
	// const 修饰右边的内容


	// 解惑
	int agex = 12;
	int height = 0;

	// const p5 ,p5是常量，*p5不是常量
	int*  const p5 = &agex;
	*p5 = 20; // age = 12
	//p5 = &height;  报错
	*p5 = 40; // height = 40
	
	return 0;
}

inline void hello()
{
	cout << "Hello World" << endl;
}