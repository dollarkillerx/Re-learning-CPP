#include <iostream>

#include "add.hpp"
using namespace std;

//template <typename  T> T add(T a ,T b)
//{
//	// 这竟然可以编译通过 说明了cpp是多么的开放 和 不严谨
//	return a + b;
//}


// 模板和实现 最好不要分离
int main()
{
	//int c = add<int>(12, 8);
	int c = add(12, 8);
	cout << c << endl;
	return 0;
}