#include <iostream>
using namespace std;
// ������������  ���Ƕ�������ָ��ı���������
// �ڶ����ʱ��ͱ����ʼ��  һ��ָ��ĳһ������ �Ͳ��ܸı�  "��һ����"

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

	
	return 0;
}