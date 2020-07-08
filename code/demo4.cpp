// extern C (修饰的代码会按照C语言方式进行编译)
#include <iostream>
using namespace std;

// 示例1： 

//// C语言是不支持函数重载的
//extern "C" void hello()
//{
//	
//}
//
//// 此处无法完成编译
//extern "C" void hello(int i )
//{
//	
//}

// 示例2:
extern "C" {
	// 如果函数同时有申明和实现， 要让函数声明被 extern “C” 修饰 ， 函数实现可以不修饰
	void hello();
	//void hello(int i )
	//{
	//	
	//}
	void pcl()
	{
		
	}
}

void pcl(int a) // name mangling
{
	
}


int main()
{
	hello();
	return 0;
}

void hello()
{
	
}