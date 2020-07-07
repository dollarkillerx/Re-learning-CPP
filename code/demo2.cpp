#include <iostream>
using namespace std;
void print();
void print(int i);
void print(double i);

int main()
{
	print();
	print(12);
	print(1.1);
}

void print()
{
	cout << "Hello World" << endl;
}

void print(int i)
{
	cout << "you inp: " << i << endl;
}

void print(double i)
{
	cout << "double :" << i << endl;
}
