#include <iostream>
using namespace std;

void test1();

int main()
{
	int a = 10;
	__asm { // vs2019 x64  cpp²»Ö§³Ö __asm
		mov eax,a
		add eax,10
		mov a,eax

		mov ax,10
		mov eax,11223344H
	}

	cout << "A :" << a << endl;
	
	test1();
	return 0;
}

void test1()
{
	int b = 10;
	b += 10;
}