#include <iostream>
using namespace std;

void test01t();
void test01t2();
void test01t3();
void test01t4();
void test01t5();

/*
	1. 如果对象为指针，不可以自++ --的操作。
	2. 数组指针和指针数组区别：数组的指针和指针的数组。

*/
int mainT01() {
	
	//C++新加的类型
	//test01t();

	//C++修饰符
	//test01t2();

	//C++独有
	//test01t3();

	//C++中的引用&。
	test01t5();

	//需要注意
	//test01t4();

	return 0;
}

int& test01t3t1(int a, int b) {
	//错误，引用对象的作用域，不能超出它本身的作用域。
	int add = a + b;
	//return add;

	//可以，因为静态的作用域是全局的，所以出了函数，对象也存在。
	static int sadd = a + b;
	return sadd;
}

void test01t3t1(int& i) {
	i = 2000;
}
/*
	C++中的引用&：
		已经存在的变量的另一个名字。

	C++中的&与指针*的区别：
		1. 不存在空引用，引用必须连接到一块合法的内存。
		2. 必须初始化时就应该赋值对象，且后期不要再指向另一个对象。
		3. 引用的作用域无法超出它本身。
*/
void test01t5() {
	int i = 100;
	int ii = 1000;
	int& iy = i;
	iy = ii;	//实际赋值，貌似也不会报错。
	cout << "iy=" << iy << endl;

	//把引用作为函数参数,此时效果与指针一致。
	test01t3t1(iy);
	cout << "iy=" << iy << endl;

	//把引用作为返回值。
	int& iyy = test01t3t1(1, 2);
	cout << "iyy=" << iyy << endl;

	//测试引用地址
	int t1 = 10;
	int& tt = t1;
	//地址一致。
	cout << "t1p=" << &t1 << endl << "t2p=" << &tt << endl;
}


void test01t3() {
	//C++中，最好给空指针赋值Null,这样可以根据是否为0判断该值是否为空。
	int* i = NULL;
	cout << "i 的值是 " << i <<endl;
}


void test01t4() {

	//与C一样，指针可作为访问数组的方式，但需要记住，指针本身永远不可以赋值。
	int  var[3] = { 10, 100, 200 };
	//var++;	//*(var++) = 300 这种方式不可以。
	*(var + 1) = 300;	//正确，注意++和var+1区别。
}

/*
	unsigned 和 signed 修饰基础类型。

	C++ 特别的地方：
		1. long和short可以用于修饰int，当然也可以直接和C一样写long。
		2. unsigned int y，时，int可以省略。

*/
void test01t2() {
	//int可以省略。
	unsigned x;
	unsigned int y;

	//short可以
	short int i;           // 有符号短整数
	short unsigned int j;  // 无符号短整数

	//将值存在寄存器中，用的少。
	register int  miles;

	//声明当前线程独有。
	//thread_local int x;

}

const int coni = 100;
/*
	相对于C，C++新增：
		1. bool：true、false。实际打印值仍然是0、1
		2. string: 字符串类型。
		3. const：常量修饰符。
		4. 输出方式cout+endl。
*/
void test01t() {
	//C++相对于C，多了一个bool类型。
	bool b = true;
	cout << "b=" << b << endl;//实际打印为0/1

	//宽字符型
	wchar_t wc = 'c';
	cout << "wc=" << wc << endl;//打印的是int型数

	//普通字符
	char c = 'c';
	cout << "c=" << c << endl;

	//新加的字符串类型,和java类似。
	string str = "darren\
123";
	str.append("ddddddd");
	str + "cccccc";	//允许直接相加
	int size = str.size();
	cout << "str=" << str << "size="<< size << endl;

	//输出const常量。
	cout << "const=" << coni << endl;

	short int s = 100;
	cout << "shot=" << s << endl;
}



