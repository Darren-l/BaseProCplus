#include <iostream>
using namespace std;

/*	
* C++ �е�����java����
*	1. Ȩ��ͳһ�����������а���������Ϊ��ķ���ʵ�֡�
*	2. ����������
*	3. �������졣
*	4. ��̬��Ա������������ʵ�֡�
*	5. ��Ԫ������
* 
* C++�У�������������ʵ�ַֿ�д��
* 
*/

class Person {
public://### ����Ȩ�޵������javaһ����
	string name;
	string getName();


	//### ����
	Person();
	Person(string);

	string nana;
	//ͨ������ֱ�������Ա����ֵ
	Person(string nana, string name) :name(name),nana(nana) {};

	//�������죬����˼�彫p�е�ֵ��ͨ�����츳ֵ���¶���
	Person(const Person& p);

	//### ����
	~Person();


	//### ��̬
	//��̬��Ա�޷�ֱ�ӳ�ʼ������Ҫ�ŵ������ʼ����
	static int sta11;
	//������̬�ķ�����ʵ��ʱ������дstatic
	static void testSta();

	//### ��Ԫ�����Է���������г�Ա��
	friend void friendMethod(Person p);

	//### ������������javaһ��������ʱ���棬�ռ任ʱ�䡣
	inline int max(int a, int b);

	//### ���������,����ʵ�����������+-*/%,|| && �ȵ��߼��������
	Person operator+(Person p);

	void printfName(string name);

	void test(string) {
	}

protected:
	string sex;

private:
	int age = 111;	//��java��ͬ�����δ��ֵ��Ĭ��ֵ����0��
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

//��Ԫ�������ڣ����Է��ʲ���p���κγ�Ա��
void friendMethod(Person p) {
	cout << "��Ԫ�������ʡ�" << endl;
	cout << "����public��Ա��name=" << p.name << endl;
	cout << "����private��Ա��age=" << p.age << endl;
}


//���캯��,Ҳ��Ҫ��������
Person::Person() {
}
Person::Person(string name) {
	this->name = name;
}

//��������Ҫ�Լ�ʵ�ֵġ�
Person::Person(const Person &p) {
	this->name = p.name;
}

//�������� -- �����ͷ�ʱ���á������˳�ʱִ�С�
Person::~Person() {
	cout << "��������ִ��" << endl;
}


//��ʼ����̬����������ֱ�ӷŵ�ȫ���С�
int Person::sta11 = 1111;

//��̬����ʵ��ʱ��������ǰ���static��
void Person::testSta() {
	cout << "�����Ǿ�̬����..." << endl;
}

/*
	Person::��ζ������Person�ķ���ʵ�֣�ʵ���Ͼͺ�javaд��class��һ����
	
	��������Ĭ���и�this����ǰ���������Ӧ�ĵ�ַ������ʹ��this->���Ե��õ�ǰ��
	�ĳ�Ա,ʵ�������ʵ�ַ����У����ö����Աthis����ʡ�ԡ�

*/
void Person::printfName(string name) {
	cout << "name=" << name << endl;
	//���ﲻ��ʡ��this����Ϊ����������������ĳ�Ա���غϡ�
	cout << "person.name=" << this->name << endl;
	//�������ʡ��this��
	cout << "age=" <<getAge() << endl;
}

string Person::getName() {
	name = "darren";
	return name;
}

int Person::getAge() {
	//Ҳ����ʡ��this��
	return this->age;
}

void testT201();
void testT202();
void testT203();
void testT204();
void testT205();
void testT206();


/*
	����C++�е��༰����
*/
int mainT02() {
	//������ʳ�Ա�򷽷���ʹ��.
	//testT201();
	
	//##### ���ʾ�̬��Ա��ʽ��
	//testT202();

	//#### ���������
	//testT203();

	//#### ��Ԫ
	//testT204();

	//#### ����
	//testT205();

	//#### ���Ա��ָ�롣
	//testT206();

	return 0;
}

void testT206() {
	Person per("���Աָ�����...");
	Person* p;
	p = &per;
	cout << "name=" << p->name << endl;
}

void testT205() {
	cout << "a=5,b=10,max=" << max(5, 10) << endl;
}

void testT204() {
	Person p("��Ԫ����");
	friendMethod(p);
}

void testT203() {
	Person p("nuomi");
	p.printfName("123");
}

void testT202() {
	Person p;
	//��javaһ���������ö���ʽ���ʡ�
	cout << "sta11=" << p.sta11 << endl;
	p.testSta();
	//ֱ��ʹ������ʣ����ʷ�ʽ��kotlin��ͬ��
	Person::sta11 = 123;
	int re = Person::sta11;
	cout << "re=" << re << endl;
	Person::testSta();
}

void testT201() {
	//���������ڲ�����ʹ��this->
	Person p;
	cout << "name=" << p.name << endl;
	cout << "name=" << p.getName() << endl;
	p.printfName("wtt...");
}


