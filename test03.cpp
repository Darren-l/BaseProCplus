#include <iostream>
using namespace std;

class Per {
public:
	//若父类有指定的构造方法，子类也必须实现父类至少一个构造。
	Per(string name);
	Per(int age);
	//~Person();

	string name;
	string getName();

	//### 若要方法支持多态，那么必须virtual。
	virtual void printf();
	//### 与java一样，支持纯虚函数。
	//特征与java相同：1.子类必须实现。2.当前类变虚类不可以直接初始化对象。
	//### C++中没有interface，只有抽象类，类的全部方法都是virtual就相当于interface。
	virtual void doSomething() = 0;
	void setSex(int sex) {
		this->sex = sex;
	}

	int getSex() {
		return sex;
	}

protected:
	int age;

private:
	//### 与java相同，变量应该处于私有状态，在public中申明对外方法。
	int sex;
};

void Per::printf() {
	cout << "这里是父类的输出...." << endl;
}

Per::Per(string name) {
	cout << "这里是父类构造...." << endl;
	this->name = name;
}

Per::Per(int age) {
	this->age = age;
}

string Per::getName(){
	return name;
}

//需要申明集成父类的权限，默认是private，
// 那将无法访问父类任何成员。
class Son :public Per {
public:
	//子类必须指定一个父类的构造进行重写，实现时需要标识。
	Son(string name);
	void printf();
	void doSomething();

	string sonName;
};

void Son::doSomething() {
}
void Son::printf() {
	cout << "这里是子类son的输出...." << endl;
}

//标识实现的是父类的哪个构造 :Per(name)
Son::Son(string name):Per(name) {
	cout << "这里是子类构造...." << endl;
	this->name = name;
}


class Father :public Per {
public:
	//子类必须指定一个父类的构造进行重写，实现时需要标识。
	Father(string name);
	void printf();
	void doSomething();
};

Father::Father(string name) :Per(name) {
	this->name = name;
}

void Father::doSomething() {
}

void Father::printf() {
	cout << "这里是子类father的输出...." << endl;
}

void test01T3t1();
void test01T302();
/*
	与java不同：
		1. 类本身没有权限，子类继承时需要确定父类权限。
		2. 子类实现构造时，需要指定对应父类的哪个构造。
		3. 父类支持多态的方法需要virtual申明，直接取地址赋值父类即可。
		4. 没有interface，抽象类virtual相当于interface。
		5. C++支持多继承！
*/
int mainT03() {

	//### 子类与父类构造关系。
	//test01T3t1();

	//### 多态
	test01T302();

	return 0;
}


void test01T302() {
	Per* per;
	Son son("son");
	Father father("father");
	per = &son;
	per->printf();
	per = &father;
	per->printf();
}

void test01T3t1() {
	//### 若父类没有重写构造方法。
	//Per p;
	//p.name = "fu";
	//Son son;
	//son.name = "zi";
	//cout << "son 的名字：" << son.name << endl;

	//### 若父类重写了构造。
	//与java相同，先走父类构造，再走子类构造。
	//Per p("fu...");
	Son son("zi...");
	cout << "son 的名字：" << son.name << endl;

}


