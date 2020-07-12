# 高级语法

### 类型转换
- c语言风格
    - `(type) expression`  `(int) age`
    - `type (experssion)`  `int (age)`
- CPP 风格
    - `static_cast`
    - `dynamic_cast`
    - `reinterpert_cast`
    - `const_cast`
    - 使用格式: `xxx_cast<type> (expression)`
##### `const_cast` const => 非const  去除Const 属性
```cpp
const Person *p1 = new Person();
Person *p2 = const_cast<Person *>(p1);

mov eax,dword ptr [p1]
mov dword ptr[p2],eax
// or c风格
Person *p3 = (Person *)p1   // 他们汇编是一样的  没有区别

mov eax,dword ptr [p1]
mov dword ptr[p3],eax
```
##### `dynamic_cast` 用于多态类型转换 (有运行时检测)
```cpp
Person *p1 = new Person();
Person *p2 = new Student();

Student *stu1 = dynamic_cast<Student *>(p1); // 不安全的  会返回NULL
Student *stu2 = dynamic_cast<Student *>(p2); // 安全
```
##### `static_cast`
    - 对比`dynamic_cast` 缺乏运行时安全检测
    - 不能交叉转换 (不是同一继承体系的 无法转换)
    - 常用于基本数据类型转换 非const 转换为const

#### `reinterpret_cast` 属于比较底层的转换 没有任何检测  就是二进制的转换
```cpp
int a = 10;     // 0A 00 00 00  
double b = a;   // 00 00 00 00 00 00 00 24 40  浮点型内存中数据存储和int存储不一样 

double d = reinterpret_cast<double&>(a); // // 0A 00 00 00 CC CC CC CC
cout << sizeof(int) << endl; // 4
cout << sizeof(double) << endl; // 8
```

## CPP 11
- `auto`
    - 可以从表达式中推导出变量类型
    - 编译器时执行 不影响最终机器码
- `decltype`
    - 获取变量类型
- `nullptr`
    - 解决NULL二义性
- 快速遍历
```cpp
// auto
auto a = 10;

// decltype
int a = 10;
decltype(a) b = 20; // int

// nullptr
func(0);
func(NULL);
func(nullptr);
NULL == nullptr  // true


// 快速遍历
int array[] = {11,22,33,44};
for (item : array) {
    cout << item << endl;
}
```
#### Lambda 表达式
```cpp
int exec(int v1,int v2,int (*func)(int,int)) {
    return func(v1,v2);
}
``` 

### CPP14，CPP17

### 异常
```cpp

try {
    throw "抛出异常";
    int *p = new int[99999];
}catch(...) {
    cout << "异常 申请内存不够" << endl;
    break;
}

// 自定义异常  demo14.cpp
class NewExcp: public Exception { // Exception 所有异常的基类

}
```

### 智能指针(现代CPP) code: demo9
- 传统指针
    - 容易发生内存泄漏
    - 需要手动管理内存（忘记释放，出现异常等）
    - 释放后产生野指针
- 智能指针
    - `auto_ptr` 属于C++98标准 C++11中不推荐使用 有局限性 不能管理数组
    - `shared_ptr` 属于C++11
    - `unique_ptr` 属于C++11
手写一个智能指针
```cpp
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
```
shared_ptr 
```cpp
void test2()
{
	shared_ptr<Person> p(new Person());
	p->run();
	shared_ptr<Person> p1 = p;
	shared_ptr<Person> p2 = p1;
	shared_ptr<Person> p3 = p2;
	cout << p.use_count() << endl; // use count 强引用数量
	shared_ptr<Person> p4 = p3;
	cout << p.use_count() << endl;
	shared_ptr<Person> p5 = p4;
	cout << p.use_count() << endl;

	// 这里p1~p5 都是指向 同一个 new Person地址  shared_ptr内部有一个引用计数器 当所有 引用都析构时 才会析构 Person对象
}
```
unique_ptr 所有指针 当前同时仅有一个指针指向 (适合多线程)
```cpp
unique_ptr<Person> p1(new Person());
po = std::move(p1); // p1释放占用 
``` 