#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}

	void run()
	{
		cout << "Run" << endl;
	}
};


// 自己实现一个简单的智能指针
template<typename T>
class SmartPointer
{
private:
	T* m_obj;
public:
	SmartPointer(T *obj): m_obj(obj){}
	~SmartPointer()
	{
		if (m_obj == nullptr) return;
		delete m_obj;
	}
	T *operator->() // 重载指针运算符 调用内部
	{
		return m_obj;
	}
};


void test1()
{
	//Person* p = new Person();
	//delete p;
	//

	// 智能指针P指向了堆空间Person对象
	auto_ptr<Person> p(new Person()); // CPP98
	p->run();


	SmartPointer<Person> p2(new Person());
	p2->run();
}

void test2()
{
	shared_ptr<Person> p(new Person());
	p->run();
	shared_ptr<Person> p1 = p;
	shared_ptr<Person> p2 = p1;
	shared_ptr<Person> p3 = p2;
	cout << p.use_count() << endl;
	shared_ptr<Person> p4 = p3;
	cout << p.use_count() << endl;
	shared_ptr<Person> p5 = p4;
	cout << p.use_count() << endl;


	// 这里p1~p5 都是指向 同一个 new Person地址  shared_ptr内部有一个引用计数器 当所有 引用都析构时 才会析构 Person对象
}

int main()
{
	test1();
	test2();

	
	return 0;
}