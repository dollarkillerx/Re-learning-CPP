#include <iostream>
using namespace std;


struct Person
{
	int id;
};

int main()
{
	// �ѿռ����

	int *p = (int *)malloc(4); // ����4���ֽ�  �����׵�ַ
	*p = 10;
	cout << "P: " << *p << endl;
	free(p); // ʹ������ֶ�����


	int* a = new int; // ����һ��int���ʹ�С�Ķ��ڴ�
	*a = 90;
	cout << "a: " << *a << endl;
	delete a;

	char* c = new char[4]; // ��������  �����׵�ַ
	delete[] c; // ��������


	int size = sizeof(int) * 10;
	int* pc = (int*)malloc(size);
	// memory set
	memset(pc, 1,size); // set pc ��  0~size ������Ϊ1

	int* p0 = new int; // Ĭ�ϲ���ʼ��
	int* p1 = new int(); // Ĭ�ϳ�ʼ��Ϊ0
	int* p2 = new int(5); // ��ʼ��Ϊָ��ֵ

	cout << *p0 << endl;
	cout << *p1 << endl;
	cout << *p2 << endl;


	Person ac = Person{ 1 };
	memset(&ac, 0, sizeof(Person));
	return 0;
}