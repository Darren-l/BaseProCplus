#include <iostream>
using namespace std;

class Per {
public:
	//��������ָ���Ĺ��췽��������Ҳ����ʵ�ָ�������һ�����졣
	Per(string name);
	Per(int age);
	//~Person();

	string name;
	string getName();

	//### ��Ҫ����֧�ֶ�̬����ô����virtual��
	virtual void printf();
	//### ��javaһ����֧�ִ��麯����
	//������java��ͬ��1.�������ʵ�֡�2.��ǰ������಻����ֱ�ӳ�ʼ������
	//### C++��û��interface��ֻ�г����࣬���ȫ����������virtual���൱��interface��
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
	//### ��java��ͬ������Ӧ�ô���˽��״̬����public���������ⷽ����
	int sex;
};

void Per::printf() {
	cout << "�����Ǹ�������...." << endl;
}

Per::Per(string name) {
	cout << "�����Ǹ��๹��...." << endl;
	this->name = name;
}

Per::Per(int age) {
	this->age = age;
}

string Per::getName(){
	return name;
}

//��Ҫ�������ɸ����Ȩ�ޣ�Ĭ����private��
// �ǽ��޷����ʸ����κγ�Ա��
class Son :public Per {
public:
	//�������ָ��һ������Ĺ��������д��ʵ��ʱ��Ҫ��ʶ��
	Son(string name);
	void printf();
	void doSomething();

	string sonName;
};

void Son::doSomething() {
}
void Son::printf() {
	cout << "����������son�����...." << endl;
}

//��ʶʵ�ֵ��Ǹ�����ĸ����� :Per(name)
Son::Son(string name):Per(name) {
	cout << "���������๹��...." << endl;
	this->name = name;
}


class Father :public Per {
public:
	//�������ָ��һ������Ĺ��������д��ʵ��ʱ��Ҫ��ʶ��
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
	cout << "����������father�����...." << endl;
}

void test01T3t1();
void test01T302();
/*
	��java��ͬ��
		1. �౾��û��Ȩ�ޣ�����̳�ʱ��Ҫȷ������Ȩ�ޡ�
		2. ����ʵ�ֹ���ʱ����Ҫָ����Ӧ������ĸ����졣
		3. ����֧�ֶ�̬�ķ�����Ҫvirtual������ֱ��ȡ��ַ��ֵ���༴�ɡ�
		4. û��interface��������virtual�൱��interface��
		5. C++֧�ֶ�̳У�
*/
int mainT03() {

	//### �����븸�๹���ϵ��
	//test01T3t1();

	//### ��̬
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
	//### ������û����д���췽����
	//Per p;
	//p.name = "fu";
	//Son son;
	//son.name = "zi";
	//cout << "son �����֣�" << son.name << endl;

	//### ��������д�˹��졣
	//��java��ͬ�����߸��๹�죬�������๹�졣
	//Per p("fu...");
	Son son("zi...");
	cout << "son �����֣�" << son.name << endl;

}


