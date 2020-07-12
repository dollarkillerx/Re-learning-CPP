#include <iostream>
using namespace std;

struct Animal
{
	virtual void speack() // 注意使用虚函数修饰才实现了 多态
	{
		cout << "Animal::speak" << endl;
	}
	virtual void run()
	{
		cout << "Animal::run()" << endl;
	}
};

struct Cat : Animal
{
	// 自动继承父类方法
};

struct Dog : Animal
{
	void speack() // 重写父类方法  
	{
		cout << "Dog::speak" << endl;
	}
	void run()
	{
		cout << "Dog::run()" << endl;
	}
};

int main()
{
	Dog* dog1 = new Dog();
	dog1->run();
	dog1->speack();

	Animal* dog = new  Dog();
	dog->run();   // 如果 没有使用虚函数 修饰 是没有实现多态的 调用只会调用父类原有的方法
	dog->speack();

	Animal* cat = new Cat();
	cat->run();
	cat->speack();
	return 0;
}