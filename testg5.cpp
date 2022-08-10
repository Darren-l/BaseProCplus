#include <iostream>
#include <memory>

using namespace std;

void testTg401();
void testTg402();
void testTg403();
void testTg404();

/*
	智能指针，作用就是可以协助指针对象空间的释放。不推荐使用，还是手动释放比较保险。

	智能指针实现自动释放对象空间的原理：
		在析构中统计当前对象引用count数,如果为0则调用对象析构。而对象引用count增加场景只有3种：
			1. 指针对象调用构造初始化，在构造中增加统计。
			2. 指针对象调用拷贝函数初始化，在拷贝函数中增加统计。
			3. 指针对象先声明，后赋值，此时要重写=操作符，增加统计count。

	shared智能指针循环依赖场景：
		两个类中都定义了对方的类智能指针成员，并相互赋值，会导致计数器多+1而引起内存泄漏。

	智能指针有点像是java中的weak弱引用，使用特点如下：
		1.一旦初始化，后面都需要用智能指针来代替对象使用。
		2. weak智能指针可以接受其他（如share）智能指针的赋值，此时share指针计数器不会+1。
		2. 使用unique会比shared更好，前者不会有循环依赖的问题。
		3. 同一个指针，不能同时关联两个不同的shared_ptr智能指针，每个智能指针只能代理一个普通指针。

*/

class PersonTg4 {
public:
	string name = "darren";

	PersonTg4() {
		cout << "person的构造函数" << endl;
	}

	~PersonTg4() {
		cout << "person的析构函数" << endl;
	}

	PersonTg4(const PersonTg4& p) {
		cout << "person的拷贝函数" << endl;
	}
};

int mainTg5() {

	//#### 智能指针shared_ptr的使用，有循环依赖的问题。
	//testTg401();

	//#### 智能指针shared_ptr允许自定义释放规则（同时也会走析构） -- 默认只走析构。
	//testTg402();

	//#### 智能指针weak_ptr，C++的弱引用
	//testTg403();

	//#### unique_ptr,可代替share，不会有循环依赖问题。
	//testTg404();	

	cout << "end...." << endl;
	return 0;
}

class PersonTg5 {
public:
	weak_ptr<PersonTg5> person2; 
	shared_ptr<PersonTg5> person;

	~PersonTg5() {
		cout << "Person1 析构函数" << endl;
	}
};

void testTg404() {
	//效果和接口与share一致。
	PersonTg5* p2 = new PersonTg5();
	unique_ptr<PersonTg5> uniquePtr1(p2);
}

void testTg403() {
	cout << "testTg403...." << endl;

	//首先声明个指针对象。
	PersonTg5* p2 = new PersonTg5();
	//将指针对象赋值给share智能指针，此时sh2的引用计数会+1
	shared_ptr<PersonTg5> sh2(p2);
	//再声明个实例来测试。
	PersonTg5* p = new PersonTg5();

	//#### 测试1，将sh2赋值给一个sh指针，计数器会正常+1。
	//在将sh2赋值给p对象中的share智能指针，此时sh2引用计数器会再次+1
	p->person = sh2;
	//所以sh2 的count输出是2.
	cout << "sh2 count=" << sh2.use_count() << endl;

	//#### 测试2，若将sh2赋值给weak指针，则计数器不会+1
	p->person2 = sh2;
	cout << "p count=" << sh2.use_count() << endl;

	cout << "testTg403.... endl" << endl;
}

/*
	自定义的释放回调函数，此时析构和该函数都会走。
*/
void deletePer(PersonTg4* p) {
	cout << "deletePer...." << endl;
	delete p;
}

void testTg402() {
	cout << "testTg402.." << endl;
	//初始化智能指针，并自定义释放规则
	std::shared_ptr<PersonTg4> p7(new PersonTg4, deletePer);

	cout << "testTg402.. end..." << endl;
}


/*
	智能指针实现原理：
		在栈中声明的对象，走完栈后会自动走析构。在析构中统计对象的声明次数，为0时进行释放。
*/
void testTg401() {
	cout << "test01.." << endl;

	PersonTg4* p = new PersonTg4;
	PersonTg4* p2 = new PersonTg4;


	shared_ptr<PersonTg4> sharePtr1(p);
	shared_ptr<PersonTg4> sharePtr2(p2);

	//使用时通过get获取p，获取的是p的实际地址，所以修改后，p的值也会随之改变。
	cout << "sh name=" << sharePtr1.get()->name << endl;
	sharePtr1.get()->name = "darren---ttt";
	cout << "sh name=" << p->name << endl;	//随之改变。
	
	//实处智能指针引用数，为0时走析构会被释放。
	cout << "sh cout=" << sharePtr1.use_count() << endl;
	
	cout << "test01.. end" << endl;

}
