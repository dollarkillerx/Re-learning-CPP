#include <iostream>
using namespace std;

void test1();
int test2();
void testmc();
void testPort();
void test3();
void testref();
void testlist();
void const_ref();
int sum(const int& a, const int& b);

int main()
{
	testmc();
	testPort();
	test3();
	testref();
	testlist();

	const_ref();
	return 0;
}

void testPort()
{
	int age = 3;
	int* p = &age;
	*p = 6;
}


void testmc()
{
	test1();
	int c = test2();
	cout << "c test2: " << c << endl;

	int a = 18;
	int b = 32;

	if (a == b)
	{
		printf("a = b");
	}
	else
	{
		printf("a != b");
	}

}

void test3()
{
	int a = 10;
	int* p = &a;
	*p += 20;
}


void testref()
{
	int a = 10;
	int& b = a;
	b += 20;

	/*00B35E72 C7 45 F4 0A 00 00 00 mov         dword ptr[ebp - 0Ch], 0Ah
		00B35E79 8D 45 F4             lea         eax, [ebp - 0Ch]
		00B35E7C 89 45 E8             mov         dword ptr[ebp - 18h], eax
		00B35E7F 8B 45 E8             mov         eax, dword ptr[ebp - 18h]
		00B35E82 8B 08                mov         ecx, dword ptr[eax]
		00B35E84 83 C1 14             add         ecx, 14h
		00B35E87 8B 55 E8             mov         edx, dword ptr[ebp - 18h]
		00B35E8A 89 0A                mov         dword ptr[edx], ecx*/
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

void testlist()
{
	int array[] = { 1,2,3,4,5,6 };
	int(*array_prot1)[6] = &array; // array_prot1 为 array[]数组的指针

	int c = 12;
	int* p = &c;
	int* array_prot2[3] = {p,p,p};  //  array_port2 为指针数组

	int(&ref)[6] = array; // 为引用数组 
}

void const_ref()
{
	int age = 10;
	const int& ref = age;
	// 常引用 不会修改指向，也不可以修改所指向的变量
	cout << "ref: " << ref << endl;

	int a = 121;
	int b = 12;

	cout << "a + b :" << sum(a, b) << endl;
	// 常引用可以指向临时数据
	const int& ac = 1212;


	int agec = 10;
	const long& rg = agec;
	age = 30;
}

// const & 作为参数 可以接受const 和 非const的实参数
// 可以和非const参数构成重载
int sum(const int& a,const int& b)
{
	return a + b;
}
