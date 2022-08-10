#include <iostream>
using namespace std;

/*	
* C++ 中的类与java区别。
*	1. 权限统一申明，函数中包含类名的为类的方法实现。
*	2. 析构函数。
*	3. 拷贝构造。
*	4. 静态成员及方法申明及实现。
*	5. 友元函数。
* 
* C++中，方法的申明与实现分开写。
* 
*/

class Person {
public://### 三个权限的意义和java一样。
	string name;
	string getName();


	//### 构造
	Person();
	Person(string);

	string nana;
	//通过构造直接向类成员对象赋值
	Person(string nana, string name) :name(name),nana(nana) {};

	//拷贝构造，顾名思义将p中的值，通过构造赋值给新对象。
	Person(const Person& p);

	//### 析构
	~Person();


	//### 静态
	//静态成员无法直接初始化，需要放到类外初始化。
	static int sta11;
	//申明静态的方法，实现时不用再写static
	static void testSta();

	//### 友元，可以访问类的所有成员。
	friend void friendMethod(Person p);

	//### 内联函数，与java一样，编译时代替，空间换时间。
	inline int max(int a, int b);

	//### 运算符重载,自行实现两个对象的+-*/%,|| && 等等逻辑运算符。
	Person operator+(Person p);

	void printfName(string name);

	void test(string) {
	}

protected:
	string sex;

private:
	int age = 111;	//与java不同，如果未赋值，默认值并非0；
	int getAge();
};

Person Person::operator+(Person pp) {
	Person p;
	p.age = this->age + pp.age;
	return p;
}

inline int max(int a, int b) {
	return a > b ? a : b;
}

//友元函数体内，可以访问参数p的任何成员。
void friendMethod(Person p) {
	cout << "友元函数访问。" << endl;
	cout << "访问public成员，name=" << p.name << endl;
	cout << "访问private成员，age=" << p.age << endl;
}


//构造函数,也需要先申明。
Person::Person() {
}
Person::Person(string name) {
	this->name = name;
}

//拷贝是需要自己实现的。
Person::Person(const Person &p) {
	this->name = p.name;
}

//析构函数 -- 对象释放时调用。程序退出时执行。
Person::~Person() {
	cout << "析构函数执行" << endl;
}


//初始化静态方法，可以直接放到全局中。
int Person::sta11 = 1111;

//静态方法实现时，不需在前面加static。
void Person::testSta() {
	cout << "这里是静态方法..." << endl;
}

/*
	Person::意味着这是Person的方法实现，实际上就和java写在class中一样。
	
	函数体中默认有个this代表当前函数对象对应的地址。所以使用this->可以调用当前类
	的成员,实际在类的实现方法中，调用对象成员this可以省略。

*/
void Person::printfName(string name) {
	cout << "name=" << name << endl;
	//这里不能省略this，因为方法参数名字与类的成员名重合。
	cout << "person.name=" << this->name << endl;
	//这里可以省略this。
	cout << "age=" <<getAge() << endl;
}

string Person::getName() {
	name = "darren";
	return name;
}

int Person::getAge() {
	//也可以省略this。
	return this->age;
}

void testT201();
void testT202();
void testT203();
void testT204();
void testT205();
void testT206();


/*
	测试C++中的类及对象
*/
int mainT02() {
	//对象访问成员或方法，使用.
	//testT201();
	
	//##### 访问静态成员方式。
	//testT202();

	//#### 构造和析构
	//testT203();

	//#### 友元
	//testT204();

	//#### 内联
	//testT205();

	//#### 类成员的指针。
	//testT206();

	return 0;
}

void testT206() {
	Person per("类成员指针测试...");
	Person* p;
	p = &per;
	cout << "name=" << p->name << endl;
}

void testT205() {
	cout << "a=5,b=10,max=" << max(5, 10) << endl;
}

void testT204() {
	Person p("友元函数");
	friendMethod(p);
}

void testT203() {
	Person p("nuomi");
	p.printfName("123");
}

void testT202() {
	Person p;
	//和java一样，可以用对象方式访问。
	cout << "sta11=" << p.sta11 << endl;
	p.testSta();
	//直接使用类访问，访问方式和kotlin相同。
	Person::sta11 = 123;
	int re = Person::sta11;
	cout << "re=" << re << endl;
	Person::testSta();
}

void testT201() {
	//如果是类的内部，则使用this->
	Person p;
	cout << "name=" << p.name << endl;
	cout << "name=" << p.getName() << endl;
	p.printfName("wtt...");
}


