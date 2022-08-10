#include <iostream>
#include <exception>
#include <vector>
#include <set>

using namespace std;


/*
	类对象初始化。
*/
class Per2 {
public:
	string namep2;
	Per2(string name) :namep2(name) {};
};

class Per3 {
public:
	string name;

	//#### 如果类中包含类对象成员，该成员必须要在构造时初始化。
	Per2 p2;

	//#### 初始化的方式有三种：1. 构造函数后面调用类成员的构造进行初始化。
	Per3(string name) :name(name),p2(name) {};

	//#### 2. 构造函数中，直接调用拷贝函数。
	Per3(Per2 p) :name(name), p2(p) {};

};

/*
	谓词
*/
class Obj {
public:
	//void operator()() {
	//	cout << "( )操作符重定向" << endl;
	//}

	//一元谓词
	bool operator()(int arg) {
		cout << "arg=" << arg << endl;
		return true;
	}

	//两个参数，所以是二元谓词
	void operator()(int arg, int arg2) {
		cout << "arg=" << arg << endl;
	}
};

void testTg2t01();
void testTg2t02();
void testTg2t03();

int mainTg02(){
	
	//#### 类中类成员初始化。

	//##### 运算符重定向()
	//Obj obj;
	//obj();	//调用的是重定向()中封装的方法。
	
	// #### 谓词
	//测试一元谓词，重定义()操作符，参数中传几个参数，就是几元谓词。
	testTg2t01();

	//#### 预定义函数
	testTg2t02();

	//#### 预定义函数plus的实现
	testTg2t03();

	return 0;
}

//预置函数实现。
template<typename T>
struct plus_d{
	T operator() (const T& x, const T& y) {
		return x + y;
	}
};
void testTg2t03() {
	plus_d<int> add;
	add(1, 2);
}

/*
	所谓预定义函数，就是已经封装好的一些函数。如plus，支持基础类型的相加。
*/
void testTg2t02() {
	//预置的int型加法
	plus<int> add;
	int re = add(1, 1);
	cout << re << endl;

	//预置的string型加法
	plus<string> addString;
	string re2 = addString("AAAA", "BBB");
	cout << re2 << endl;
}


//返回true表示中断回调，否则会遍历所有元素。
bool fun2(int arg2) {
	cout << "arg2=" << arg2 << endl;
	return true;
}

/*
*	谓词：所谓的谓词，就是重写类的()运算符，使用类名()方式作为函数进行传递。这种方式
*		和传普通函数的区别在于，有一层类的包装，可以定义类成员来辅助记录一些谓词函数中
*		需要记录的值。
* 
*		假设不需要在回调中记录任何事件，那么可以直接传回调。如果需要记录回调中的一些
*		状态可以使用谓词，利用类成员来记录。
* 
*		源码中大量的使用了谓词函数来代替普通函数的传递。
* 
	在kotlin的高阶函数中，通常函数参数有两种方式接受：
		1. 传lambda表达式。
		2. 定义一个函数，将函数对象传递进去。
	而在C++中，也有两种方式：
		1. 传谓词。
		2. 传普通函数。
*/
void testTg2t01() {
	vector<int> vt;
	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(5);

	//最后一个参数相当于kotlin中的高阶函数的传函数参数。
	//这里可以传一个()的操作符重定义，也可以直接传个函数。
	//vector<int>::iterator it = find_if(vt.begin(), vt.end(), fun2);	//普通函数
	vector<int>::iterator it = find_if(vt.begin(), vt.end(), Obj());	//谓词函数
	for (it = vt.begin(); it != vt.end(); it ++ ) {
		cout << "开始遍历：it=" << *it << endl;
	}

}

