#include <iostream>
#include <memory>

using namespace std;

void testTg501();
void testTg502();
void testTg503();
void testTg504();

class persong6 {
public:
	string name;

};


class fu {
public:
	string name;
	void fun() {
		cout << "fu...fun..." << endl;
	}
};

class son : public fu {
public:
	string name;
	void fun() {
		cout << "son...son..." << endl;
	}
};


class fu2 {
public:
	string name;
	int ii;
	virtual void fun() {
		cout << "fu...fun..." << endl;
	}
};

class son2 : public fu2 {
public:
	string name;
	int ii;
	void fun() {
		cout << "son...son..." << endl;
	}
};


/*
	类型转化
*/
int main() {

	//const_cast<>()，用于将const 指针类型转化普通类型。
	//testTg501();

	//static_cast<>()，用于void*及父->子的强转，该强转发生在编译期间。
	//testTg502();

	//dynamic_cast<>(),用于指针对象多态的转化，发生在运行期间。
	//testTg503();

	//reinterpret_cast<>(),用于将指针转化为指定long型作为key。
	testTg504();

	//c++11针对赋值指针为空
	fu* f = nullptr;  //和null效果一样，指针可以用nullptr。


	return 0;
}
/*
	重定义指针转化类型：将对象转化为long型，可以根据这个转化重新转回对象。
		通常用于C++对象传递给java时，java层仅保存long型数据代表这个对象。
*/
void testTg504() {
	cout << "testTg504...." << endl;
	fu* f = new fu();
	f->name = "darren";
	long fv = reinterpret_cast<long>(f);
	cout << "fv=" << fv << endl;

	fu* f2 = reinterpret_cast<fu*>(f);
	cout << "name=" << f2->name << endl;
}

/*
	动态转化特点：
		效果与静态转化一致，但仅允许多态的转化。动态转化发生在运行时。
*/
void testTg503() {
	cout << "testTg503...." << endl;

	//#### fu类型直接强转子类型，不允许会报错，因为动态转化是运行时转化。
	//fu2* f99 = new fu2();
	//f99->name = "fufufufu..";
	//son2* s99 = dynamic_cast<son2*>(f99);
	//s99->fun();


	//#### 多态，父类型转子类型。
	son2* s222 = new son2();
	s222->name = "这里实际是zi..";
	fu2* f = s222;

	son2* s = dynamic_cast<son2*>(f);
	s->fun();
	f->fun();
	cout << "name=" << s->name << endl;	//无法获取到fu状态下设置的值。

	cout << "########## test..." << endl;
}

/*
	静态转化特点：
		void*对象 --> 具体对象：只要具体对象强转指定的类型没错，那么可以正常转化。
	若类型错了，也不会报错，返回指针为野指针。

		fu*对象 --> son*对象：类似于多态的效果。
		son*对象 --> fu*对象：就是普通的多态。
*/
void testTg502() {

	//#### 可以在编译期间，还原void*对应的本来类型。
	cout << "testTg502...." << endl;
	int i = 10;
	void* v = &i;
	int* st = static_cast<int*>(v);
	cout << "st=" << *st << endl;

	cout << "test1....." << endl;

	//#### 可以将父类转化为子类，注意这里不是多态。
	fu* f = new fu();
	f->name = "fufufufu..";
	//这种转化在java运行时上是肯定报错，但由于static_cast本身是在编译时强转的，所以
	//它的做法是创建一个新对象去继承fu，并拷贝super，相当于多态。
	son* s = static_cast<son*>(f);	
	s->fun();
	f->fun();
	cout << "name=" << s->name << endl;	//若子类没有重写父类的name成员，可以正常输出fufufu。

	//#### 子类转化为父类，这种情况就是多态了。
	son* sss3 = new son();
	sss3->name = "sonsonson..";
	fu* f2 = sss3;
	son* s2 = static_cast<son*>(f2);
	s2->fun();
	f2->fun();
	cout << "name=" << s2->name << endl;

}

void testTg501() {
	cout << "testTg501...." << endl;

	const persong6* p = new persong6;
	//p->name = "darren";	//const修饰后不可修改值。

	//并不是修改p原有的属性，而是重新创建了一个指针，指向和p相同的地址。
	persong6* p2 = const_cast<persong6*>(p);
	p2->name = "darren";
	cout << "p2 name=" << p2->name << endl;
}