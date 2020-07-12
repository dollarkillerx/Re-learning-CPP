#include <iostream>
using namespace std;

struct Animal
{
	virtual void speack() // ע��ʹ���麯�����β�ʵ���� ��̬
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
	// �Զ��̳и��෽��
};

struct Dog : Animal
{
	void speack() // ��д���෽��  
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
	dog->run();   // ��� û��ʹ���麯�� ���� ��û��ʵ�ֶ�̬�� ����ֻ����ø���ԭ�еķ���
	dog->speack();

	Animal* cat = new Cat();
	cat->run();
	cat->speack();
	return 0;
}