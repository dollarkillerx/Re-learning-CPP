#include <iostream>

#include "add.hpp"
using namespace std;

//template <typename  T> T add(T a ,T b)
//{
//	// �⾹Ȼ���Ա���ͨ�� ˵����cpp�Ƕ�ô�Ŀ��� �� ���Ͻ�
//	return a + b;
//}


// ģ���ʵ�� ��ò�Ҫ����
int main()
{
	//int c = add<int>(12, 8);
	int c = add(12, 8);
	cout << c << endl;
	return 0;
}