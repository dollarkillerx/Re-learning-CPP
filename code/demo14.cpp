#include <iostream>
using namespace std;
class DiveExp : public exception // std::exception 所有异常的父类
{
		
};

int divide(int v1,int v2)
{
	if(v2 == 0)
	{
		throw DiveExp();
	}
	return v1 / v2;
}

int main()
{
	try
	{
		divide(1, 0);
	}
	catch (DiveExp)
	{
		cout << "dive exp" << endl;
	}
}