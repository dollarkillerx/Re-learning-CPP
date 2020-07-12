### 面向对象

#### 定义
struct class 都可以定义类 (语法糖 概念层面)
```cpp
class Person // 默认成员权限 private
{
public:
	// 成员变量
	int m_age;
	// 成员函数(function)
	void run()
	{
		cout << "Person::run()" << endl;
	}
};

struct person_struct // 默认成员权限 public
{
	int m_age; // 成员属性
	void run()
	{
		cout << "person_struct::run()" << endl;
	}
};
```

### CPP 编程规范
- 全局变量: g_
- 成员变量: m_
- 静态变量: s_
- 常量: c_
- 驼峰标识


```cpp
int main()
{
	Person man = Person{};
	man.age = 1;
	man.run();
	
	person_struct pr =  person_struct{ 1 };
	pr.run();

	person_struct* ppr = &pr;
	cout << "age: " << ppr->m_age << endl;
	
	return 0;
}

此处person 对象 和指针都是再函数的栈空间 自动分配和回收的
```

### 内存空间布局
- 每一个应用都有自己独立的内存空间 
    - 栈空间  每调用一个函数 都要分配一段连续的栈空间 用于存放临时变量  自动分配和回收  贯穿本函数的生命周期
    - 堆空间  需要手动申请和回收
    - 代码区  
    - 全局区(数据段)  一般存放全局变量   整个应用的生命周期

#### 堆空间操作
```cpp
	// 堆空间操作

	int *p = (int *)malloc(4); // 申请4个字节  返回首地址
	*p = 10;
	cout << "P: " << *p << endl;
	free(p); // 使用完毕手动回收


	// CPP 新增

	int* a = new int; // 申请一个int类型大小的堆内存
	*a = 90;
	cout << "a: " << *a << endl;
	delete a;

	char* c = new char[4]; // 申请数组  返回首地址
	delete[] c; // 回收数组


	int size = sizeof(int) * 10;
	int* pc = (int*)malloc(size);
	// memory set
	memset(pc, 1,size); // set pc 将  0~size 每一个字节都设置为1


	int* p0 = new int; // 默认不初始化
	int* p1 = new int(); // 默认初始化为0
	int* p2 = new int(5); // 初始化为指定值

	cout << *p0 << endl;
	cout << *p1 << endl;
	cout << *p2 << endl;
```

### namespace
命名空间避免重复的相同的命名冲突  和package 好像啊
```cpp
#include <iostream>
using namespace std;

class Person
{
	int m_age;
};

namespace csgo
{
	class Person
	{
		int m_height;
	};
}

int main()
{
	Person pc;

	csgo::Person pcx;
	
	return 0;
}
```
默认全局命名空间 没有名称

##### 命名空间合并
```cpp
namespace HE {
	int g_age;
}
namespace HE {
	int g_int;
}

等价于
namespace HE {
	int g_age;
	int g_int;
}
```
#### 继承
```cpp
struct Person
{
	int m_age;
	void run()
	{
		cout << "Run" << endl;
	}
};

struct Student : Person
{
	int m_score;
	void study()
	{
		cout << "Study" << endl;
	}
};

struct Worket : Person 
{
	int m_salary;
	void work()
	{
		cout << "Work" << endl;
	}
};
```

### 虚函数  (CPP 实现多态使用虚函数实现)
- 多态
	- 特性
		- 同一个操作作用域不同对象 产生不同结果
		- 再运行时 识别出真正对象类型 调用对应子类中函数
	- 要素
		- 子类重写父类的成员函数
		- 父类指针指向子类对象
		- 利用父类指针调用重写成员函数 
```cpp
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

struct Cat: Animal
{
	// 自动继承父类方法
};

struct Dog: Animal
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
	
	Animal *dog =new  Dog();
	dog->run();   // 如果 没有使用虚函数 修饰 是没有实现多态的 调用只会调用父类原有的方法
	dog->speack();

	Animal *cat =new Cat();
	cat->run();
	cat->speack();
	return 0;
}
```

### 虚表
虚函数的实现 指向的虚表  虚表中有调用函数地址的信息

举一个栗子
```cpp
struct Animal {
	int m_age;
	int m_size;
	virtual void speak() {
		"..."
	}
	virtual void run() {
		"..."
	}
}

struct Person: Animal {
	void speak() {
		"..."
	}
	void run() {
		"..."
	}
}
```
此时 Person的内存结构
	- 虚表地址 （会新增加一个虚表 地址  指向虚表 里面有person::cat person:run的函数地址）
	- m_age 地址
	- m_size 地址
```cpp
汇编代码:
Animal *cat = new Person();
cat->speak();
// 假设ebp-8为cat地址

mov eax,dword ptr [ebp-8]
mov edx,dword ptr [eax] // eax 取到前4个字节

// 取出speack 函数地址
mov eax,dword ptr[edx]
call edx
```
父类指针指向子类对象 使用到多态特性是 父类析构函数 必须申明为virtual虚函数

### 纯虚函数 就像interface  定义接口规范
```cpp
struct Animal{
	virtual void speak();
	virtual void run();
}
```

### 多继承
cpp 运行一个类 可以有多个父类 (但是不建议使用  这样会增加代码的复杂度)
```cpp
class Car: h1,h2,h3 {
	// car 继承了 h1 h2 h3
}
```

### static 静态成员
- 修饰成员变量\函数
- 存储在 (全局区 数据段)
```cpp

```