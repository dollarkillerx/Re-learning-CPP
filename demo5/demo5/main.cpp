#include <iostream>
using namespace std;
// ������������  ���Ƕ�������ָ��ı���������
// �ڶ����ʱ��ͱ����ʼ��  һ��ָ��ĳһ������ �Ͳ��ܸı�  "��һ����"
// �����������ó�ʼ����һ�����ã��൱��ĳ�������������
// ���õı���
	// ����ָ��  ���������������Ĺ���	
void swap(int* v1, int* v2);
void swap(int& v1, int& v2);
void test2();
int main()
{
	int age = 10;
	int c = 1;
	int* page = &age;

	*page = 20;// age = 20
	page = &c ;
	*page += 20;// c += 20

	cout << "age: " << age << endl;
	cout << "c: " << c << endl;
	cout << "page: " << page << endl;

	int pg = 20;
	int& cc = pg; // cc Ϊ pg������  (cc�൱��pg�ı���)
	cc = 19; // pg = 19   

	cout << "cc: " << cc << endl;

	int scp = 001;
	int& scp1 = scp;
	int& scp2 = scp1;
	int& scp3 = scp2; // scp3 ����ָ�� scp
	scp3 += 20;

	cout << "scp :" << scp << endl;


	int a = 12;
	int b = 33;
	swap(&a, &b);
	cout << "a : " << a << "b: " << b << endl;
	swap(a, b);// ���ô���
	cout << "a : " << a << "b: " << b << endl;

	// ����̽��
	test2();

	
	return 0;
}

void swap(int* v1, int* v2)
{
	int swap = *v1;
	*v1 = *v2;
	*v2 = swap;
}

void swap(int& v1, int& v2)
{
	int swap = v1;
	v1 = v2;
	v2 = swap;
}


struct Student
{
	int &age;
};

void test2()
{
	int age = 10;
	int* p = &age;
	int& pc = age;
	cout << sizeof(p) << endl;
	cout << sizeof(pc) << endl; // ���ǲ��� pc��ָ�� age��sizeof

	Student m1 = { age };
	cout << sizeof(m1) << endl;
}
