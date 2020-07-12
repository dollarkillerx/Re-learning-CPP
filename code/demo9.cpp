#include <iostream>
using namespace std;


struct Person
{
	int id;
};

int main()
{
	// 堆空间操作

	int *p = (int *)malloc(4); // 申请4个字节  返回首地址
	*p = 10;
	cout << "P: " << *p << endl;
	free(p); // 使用完毕手动回收


	int* a = new int; // 申请一个int类型大小的堆内存
	*a = 90;
	cout << "a: " << *a << endl;
	delete a;

	char* c = new char[4]; // 申请数组  返回首地址
	delete[] c; // 回收数组


	int size = sizeof(int) * 10;
	int* pc = (int*)malloc(size);
	// memory set
	memset(pc, 1,size); // set pc 将  0~size 都设置为1

	int* p0 = new int; // 默认不初始化
	int* p1 = new int(); // 默认初始化为0
	int* p2 = new int(5); // 初始化为指定值

	cout << *p0 << endl;
	cout << *p1 << endl;
	cout << *p2 << endl;


	Person ac = Person{ 1 };
	memset(&ac, 0, sizeof(Person));
	return 0;
}