#include <iostream>
#include <exception>
using namespace std;

void test04t1();
void test05t2();
void test05t3();
void test05t4();

/*
	1. �쳣����û��Ĭ�ϵ��쳣��
	2. new��delte�����malloc��new�����Ƿ������ڴ棬�������˶���
	3. �����ռ�������Ϊ������࣬���涼�Ǿ�̬�ķ���������Ƕ�ף��������ڲ�ͬ�ļ���
*/
int mainT04() {

	//### �쳣����
	//test04t1();

	//### ��̬�ڴ�new��delete����malloc��free��
	//test05t2();

	//### �����ռ�������Ϊ������࣬ʹ��usingָ���󣬿���ʡ�Կռ���ǰ׺��
	//test05t3();

	//### templateģ�� -- ����java�еķ��͡�
	//test05t4();

	//### ָ�볣���ͳ���ָ�롣
	//����ָ�룬�������޸�*p��ֵ��
	//int c = 10;
	//int d = 100;
	//const int* ip = &c;
	//ip = 20;	//�����������޸�
	
	//ָ�볣����������p��
	//int* const i = &c;
	//i = &d;

	return 0;
}

//### ���ģ�� --- �൱��java����ķ��͡�
//template <class T>
//class Stack {
//private:
//	vector<T> elems;     // Ԫ�� 
//
//public:
//	void push(T const&);  // ��ջ
//};

//template <class T>
//void Stack<T>::push(T const& elem)
//{
//	// ׷�Ӵ���Ԫ�صĸ���
//	elems.push_back(elem);
//}

//### ��ͨ�����Ĳ���ģ�� -- �൱��java�ķ����������͡�
template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}
void test05t4() {
	cout << "����������" << Max(5, 6)  << endl;
}

//### �����ռ��������
namespace first_sp {
	void fun() {
		cout << "first sp..." << endl;
	}
}
//### ͬһ�������ռ���Է�ɢ������ļ��ж��塣
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

//### Ƕ�ס�
namespace thir {
	namespace four {
		void fun() {
			cout << "thir->four->fun..." << endl;
		}
	}
}

//### ָ��ʹ�õ������ռ䡣
using namespace first_sp;

//### ��������ָ��ʹ�������ռ����ָ��������������������Ҫ��ǰ׺��
//using std::cout;

void test05t3() {
	//### ���ַ�ʽ�е����������о�̬�����ĵ��á�
	//first_sp::fun();
	//sec_sp::fun();

	//### �ⲿʹ��usingָ��ʹ�������ռ䡣
	//fun();

	//using std::cout;

	//### Ƕ�������ռ�ĵ��á�
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
	��malloc���ƣ�new����ֻ�ܷ���һ����λ�ġ����͡��ռ䣬����Ƕ�ά
	�����������飬����Ҫ����*N��

	ע�⣬��C++��Ҳ����ʹ��C��malloc��freeȥ��������Ŀռ���ͷŶ��󣬵�����
	�߶���Ĺ��췽�����������������Բ�Ҫ��ô�ã�����
*/
void test05t2() {
	//### ��ͨ������
	int* i = new int;
	*i = 10;
	cout << "i=" << *i << endl;
	delete i;

	//### ���飬��ά����
	//һά���飬����Ϊint[10];
	int* cc = new int[10];
	delete cc;

	//��ά���飬int[10][5]
	int** array = new int* [10];
	for (int i = 0; i < 10; i++){
		array[i] = new int[5];
	}
	//�ͷ�
	for (int i = 0; i < 10; i++){
		delete[] array[i];
	}
	delete[] array;

	//### ����
	Demo* demo = new Demo;
	demo->name = "����...";
	cout << "demo name=" << demo->name << endl;
	delete demo;

	//### �������顣
	Demo* demo2 = new Demo[5];
	delete []demo2;	//�ͷ�ʱ����Ҫָ����С��
}

void testt1(int a, int b) {
	int c = a / b;
	cout << "test1111=" << c << endl;
}

void test04t1() {

	//��javaһ�������Բ���trow���쳣��
	try {
		throw "�����׳�һ���쳣��";
	}catch(const char* msg){
		cout << "msg=" << msg << endl;
	}

	try {
		throw "�����׳��ڶ����쳣��";
	}
	catch (const char* e) {
		cout << "msg=" << e<< endl;
	}

	//�����java��ͬ���޷���������
	try {
		testt1(1,0);
	}
	catch (const char* msg) {
		cout << "msg=" << msg << endl;
	}
	catch (...) {
		cout << "�����Ƕ��׵�catch"<< endl;
	}

}
