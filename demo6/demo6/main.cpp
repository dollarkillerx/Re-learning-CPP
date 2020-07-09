#include <iostream>
using namespace std;

void test1();

int main()
{
	int a = 10;
	__asm { // vs2019 x64  cpp不支持 __asm
		mov eax,a
		add eax,10
		mov a,eax

		mov ax,10  // 赋值AX
		mov eax,11223344H // eax 包含 AX  此时会影响 AX  = 3344
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