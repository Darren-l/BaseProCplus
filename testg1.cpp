/*
* 探究C++中的浅拷贝与深拷贝。
* 
* Java中的拷贝：
*	1. 引用拷贝：对象本身地址不同，但所指向的数据对象一致。对象赋值及方法传参都为引用拷贝。
		P p1 = new P(); P p2 = p1; // p2对象为新对象，但实际指向的是与p1同一个数据对象内存地址。
*	2. 浅拷贝：相比引用拷贝，数据对象内存地址也是新的，但对象内部引用成员还是和被拷贝的对象一致。
*	3. 深拷贝：相对于浅拷贝，内部引用成员对应的数据对象也是新new出来的。
* 
* C++中的拷贝：
*	1. 引用拷贝：与java概念一致。
		P p1 = new p();  P* p2 = p1; //对象值赋值给指针时，为引用拷贝。
*	2. 浅拷贝：概念与java一致。对象赋值，及方法传递对象，都会走拷贝函数。
		P p1 = new P(); P p2 = p1;	//与java不同，对象本身的赋值为浅拷贝。
*		setP(p1);	//若函数接受参数类型为对象，那么也会走浅拷贝。
*	3. 深拷贝：概念与java一致。
* 
* 关于拷贝会引起的问题，C++中需要非常注意的点：
*	问题1：
*		由于赋值和函数为实例的传参都是浅拷贝，假设构造中new了对象在堆上，并在析构中free了该对象。若存在调用
		了传参为实例对象的函数时，必定会调用拷贝函数创建新对象并作用在函数中，当函数走完后又会走析构释放该对象。
		那么如果方法调用多次，就会引起析构多次free同一个对象成员的问题。

	解决方式：
		1. 如果构造中有new对象，那么对应在在拷贝函数中，也需要有new的动作，对该对象进行深拷贝。
		2. 函数参数以指针或者&引用为主，避开拷贝函数及析构的调用。
* 
*/

#define _CRT_SECURE_NO_WARNINGS	//规避windoows调用strcpy报错。
#include <iostream>
#include <exception>

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class ObjectCp {
public:
	char* name;

	ObjectCp(char* name);
	~ObjectCp();
	ObjectCp(const ObjectCp& cp);

	void fun1(ObjectCp objcp);
	void fun2();

};
ObjectCp::ObjectCp(char* name)
{
	this->name = (char*) malloc(20);
	strcpy(this->name,name);
	cout << "构造方法执行 -- 当前对象地址：" << this << endl;
}

ObjectCp::~ObjectCp()
{
	cout << "析构函数的执行 对象地址=" << this <<  endl;
	//析构中调用free需要注意拷贝函数中需要深拷贝该对象。
	free(name);
}

ObjectCp::ObjectCp(const ObjectCp& cp)
{
	this->name = (char*)malloc(20);
	strcpy(this->name, name);
	cout << "拷贝函数的执行" << endl;

}

void ObjectCp::fun1(ObjectCp objcp)
{
	cout << "执行fun1， objcp的地址：" << &objcp << "  this的地址为" << this << endl;
}

void ObjectCp::fun2()
{
	cout << "执行fun2...."<< endl;
}


int mainTg1(int) {
	
	//#### C++中这么赋值会报错，可以用string。
	//char* aa = "qwe";

	////#### test01：测试main中对象的生命周期。
	//char name [5]  = "abcd";
	//ObjectCp obj(name);	//obj会等mian执行完后才调用析构。
	//cout << "对象构建结束" << endl;

	////#### test02:测试对象的赋值，会走拷贝函数。
	//char name[5] = "abcd";
	//ObjectCp obj(name);	
	////会走拷贝函数默认进行浅拷贝，实际obj与obj2地址不同，但指向的数据地址相同。
	//ObjectCp obj2 = obj;
	//ObjectCp obj8(name);
	//obj8 = obj;	//此时不会调用拷贝函数，仅仅声明时赋值才会走构造！


	////#### test03:测试函数参数为对象时，会调用拷贝函数。
	//char name[5] = "abcd";
	//ObjectCp obj(name);	
	//ObjectCp obj2(name);
	//cout << "开始调用参数为对象的方法..." << endl;
	////函数参数为对象时，会走拷贝函数创建新对象，退出函数体时，该对象会被释放，走析构。
	////拷贝函数默认为浅拷贝，若构造中有new，析构中有free，那么拷贝函数中也必须要有和构造中相同的new。
	//obj.fun1(obj2);
	//cout << "对象的方法执行完毕..." << endl;

	////#### test04: 测试指针赋值，不会走拷贝函数，相当于赋值引用。
	//char name[5] = "abcd";
	//ObjectCp obj(name);
	//ObjectCp* cp = &obj;

	return 0;
}


