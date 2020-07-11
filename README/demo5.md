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
