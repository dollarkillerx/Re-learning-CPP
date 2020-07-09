#include <iostream>
using namespace std;
// 引用用作计算  就是对引用所指向的变量做计算
// 在定义的时候就必须初始化  一旦指向某一个变量 就不能改变  "从一而终"
// 可以利用引用初始化另一个引用，相当于某个变量多个别名
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
	int& cc = pg; // cc 为 pg的引用  (cc相当于pg的别名)
	cc = 19; // pg = 19   

	cout << "cc: " << cc << endl;

	int scp = 001;
	int& scp1 = scp;
	int& scp2 = scp1;
	int& scp3 = scp2; // scp3 依旧指向 scp
	scp3 += 20;

	cout << "scp :" << scp << endl;
	return 0;
}