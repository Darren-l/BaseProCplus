#include <iostream>
#include <exception>
using namespace std;

void test04t1();
void test05t2();
void test05t3();
void test05t4();

/*
	1. 异常捕获，没有默认的异常。
	2. new和delte，相比malloc，new不仅是分配了内存，还创建了对象。
	3. 命名空间可以理解为特殊的类，里面都是静态的方法，允许嵌套，允许定义在不同文件。
*/
int mainT04() {

	//### 异常捕获。
	//test04t1();

	//### 动态内存new和delete代替malloc和free。
	//test05t2();

	//### 命名空间可以理解为特殊的类，使用using指定后，可以省略空间名前缀。
	//test05t3();

	//### template模板 -- 类似java中的泛型。
	//test05t4();

	//### 指针常量和常量指针。
	//常量指针，不允许修改*p的值。
	//int c = 10;
	//int d = 100;
	//const int* ip = &c;
	//ip = 20;	//报错，不允许修改
	
	//指针常量，不允许p。
	//int* const i = &c;
	//i = &d;

	return 0;
}

//### 类的模板 --- 相当于java的类的泛型。
//template <class T>
//class Stack {
//private:
//	vector<T> elems;     // 元素 
//
//public:
//	void push(T const&);  // 入栈
//};

//template <class T>
//void Stack<T>::push(T const& elem)
//{
//	// 追加传入元素的副本
//	elems.push_back(elem);
//}

//### 普通函数的参数模板 -- 相当于java的方法参数泛型。
template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}
void test05t4() {
	cout << "输出最大数：" << Max(5, 6)  << endl;
}

//### 命名空间的申明。
namespace first_sp {
	void fun() {
		cout << "first sp..." << endl;
	}
}
//### 同一的命名空间可以分散到多个文件中定义。
namespace sec_sp {
	void fun() {
		cout << "serc sp..." << endl;
	}
}

namespace sec_sp {
	void fun2() {
		cout << "serc sp2222..." << endl;
	}
}

//### 嵌套。
namespace thir {
	namespace four {
		void fun() {
			cout << "thir->four->fun..." << endl;
		}
	}
}

//### 指定使用的命名空间。
using namespace first_sp;

//### 甚至可以指定使用命名空间里的指定方法，其他方法则需要加前缀。
//using std::cout;

void test05t3() {
	//### 这种方式有点类似于类中静态方法的调用。
	//first_sp::fun();
	//sec_sp::fun();

	//### 外部使用using指定使用命名空间。
	//fun();

	//using std::cout;

	//### 嵌套命名空间的调用。
	thir::four::fun();
}

class Demo {
public:
	string name;
	int getAge() {
		return age;
	}
	

private:
	int age;
};

/*
	和malloc类似，new本身只能分配一个单位的“类型”空间，如果是多维
	数组或对象数组，则需要自行*N。

	注意，在C++中也可以使用C的malloc和free去申明对象的空间和释放对象，但不会
	走对象的构造方法和析构方法，所以不要这么用！！！
*/
void test05t2() {
	//### 普通变量。
	int* i = new int;
	*i = 10;
	cout << "i=" << *i << endl;
	delete i;

	//### 数组，多维数组
	//一维数组，长度为int[10];
	int* cc = new int[10];
	delete cc;

	//二维数组，int[10][5]
	int** array = new int* [10];
	for (int i = 0; i < 10; i++){
		array[i] = new int[5];
	}
	//释放
	for (int i = 0; i < 10; i++){
		delete[] array[i];
	}
	delete[] array;

	//### 对象。
	Demo* demo = new Demo;
	demo->name = "对象...";
	cout << "demo name=" << demo->name << endl;
	delete demo;

	//### 对象数组。
	Demo* demo2 = new Demo[5];
	delete []demo2;	//释放时不需要指定大小。
}

void testt1(int a, int b) {
	int c = a / b;
	cout << "test1111=" << c << endl;
}

void test04t1() {

	//和java一样，可以捕获trow的异常。
	try {
		throw "故意抛出一个异常。";
	}catch(const char* msg){
		cout << "msg=" << msg << endl;
	}

	try {
		throw "故意抛出第二个异常。";
	}
	catch (const char* e) {
		cout << "msg=" << e<< endl;
	}

	//这里和java不同，无法正常捕获
	try {
		testt1(1,0);
	}
	catch (const char* msg) {
		cout << "msg=" << msg << endl;
	}
	catch (...) {
		cout << "这里是兜底的catch"<< endl;
	}

}
