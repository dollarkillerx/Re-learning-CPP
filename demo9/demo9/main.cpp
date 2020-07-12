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


// �Լ�ʵ��һ���򵥵�����ָ��
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
	T *operator->() // ����ָ������� �����ڲ�
	{
		return m_obj;
	}
};


void test1()
{
	//Person* p = new Person();
	//delete p;
	//

	// ����ָ��Pָ���˶ѿռ�Person����
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


	// ����p1~p5 ����ָ�� ͬһ�� new Person��ַ  shared_ptr�ڲ���һ�����ü����� ������ ���ö�����ʱ �Ż����� Person����
}

int main()
{
	test1();
	test2();

	
	return 0;
}