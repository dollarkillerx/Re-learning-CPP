// inline function
// ʹ��inline ���κ�����ʲô����ʵ�� ����ʹ������������
// ����������ʵ�ֶ����inline���η�
// �ص�
	// �������Ὣ��������ֱ��չ��Ϊ���������  (���������)
	// �������õĴ��� �Ὺ��ջ�ռ�  Ȼ�����ջ�ռ�   �������� �Ͳ�����ջ�ռ俪��
	// inlineֻ�ǽ�������� ����  ��Ҫ���������
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


	// count ���峣��
	const int agec = 10; // ����󲻿��޸�

	//const Data d = Data{ 12,12,12 };
	const Data d = { 12,12,12 };
	//d.day = 12;  const �� �����޸�
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
	// const �����ұߵ�����


	// ���
	int agex = 12;
	int height = 0;

	// const p5 ,p5�ǳ�����*p5���ǳ���
	int*  const p5 = &agex;
	*p5 = 20; // age = 12
	//p5 = &height;  ����
	*p5 = 40; // height = 40
	
	return 0;
}

inline void hello()
{
	cout << "Hello World" << endl;
}