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
	����ת��
*/
int main() {

	//const_cast<>()�����ڽ�const ָ������ת����ͨ���͡�
	//testTg501();

	//static_cast<>()������void*����->�ӵ�ǿת����ǿת�����ڱ����ڼ䡣
	//testTg502();

	//dynamic_cast<>(),����ָ������̬��ת���������������ڼ䡣
	//testTg503();

	//reinterpret_cast<>(),���ڽ�ָ��ת��Ϊָ��long����Ϊkey��
	testTg504();

	//c++11��Ը�ֵָ��Ϊ��
	fu* f = nullptr;  //��nullЧ��һ����ָ�������nullptr��


	return 0;
}
/*
	�ض���ָ��ת�����ͣ�������ת��Ϊlong�ͣ����Ը������ת������ת�ض���
		ͨ������C++���󴫵ݸ�javaʱ��java�������long�����ݴ����������
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
	��̬ת���ص㣺
		Ч���뾲̬ת��һ�£����������̬��ת������̬ת������������ʱ��
*/
void testTg503() {
	cout << "testTg503...." << endl;

	//#### fu����ֱ��ǿת�����ͣ�������ᱨ����Ϊ��̬ת��������ʱת����
	//fu2* f99 = new fu2();
	//f99->name = "fufufufu..";
	//son2* s99 = dynamic_cast<son2*>(f99);
	//s99->fun();


	//#### ��̬��������ת�����͡�
	son2* s222 = new son2();
	s222->name = "����ʵ����zi..";
	fu2* f = s222;

	son2* s = dynamic_cast<son2*>(f);
	s->fun();
	f->fun();
	cout << "name=" << s->name << endl;	//�޷���ȡ��fu״̬�����õ�ֵ��

	cout << "########## test..." << endl;
}

/*
	��̬ת���ص㣺
		void*���� --> �������ֻҪ�������ǿתָ��������û����ô��������ת����
	�����ʹ��ˣ�Ҳ���ᱨ������ָ��ΪҰָ�롣

		fu*���� --> son*���������ڶ�̬��Ч����
		son*���� --> fu*���󣺾�����ͨ�Ķ�̬��
*/
void testTg502() {

	//#### �����ڱ����ڼ䣬��ԭvoid*��Ӧ�ı������͡�
	cout << "testTg502...." << endl;
	int i = 10;
	void* v = &i;
	int* st = static_cast<int*>(v);
	cout << "st=" << *st << endl;

	cout << "test1....." << endl;

	//#### ���Խ�����ת��Ϊ���࣬ע�����ﲻ�Ƕ�̬��
	fu* f = new fu();
	f->name = "fufufufu..";
	//����ת����java����ʱ���ǿ϶�����������static_cast�������ڱ���ʱǿת�ģ�����
	//���������Ǵ���һ���¶���ȥ�̳�fu��������super���൱�ڶ�̬��
	son* s = static_cast<son*>(f);	
	s->fun();
	f->fun();
	cout << "name=" << s->name << endl;	//������û����д�����name��Ա�������������fufufu��

	//#### ����ת��Ϊ���࣬����������Ƕ�̬�ˡ�
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
	//p->name = "darren";	//const���κ󲻿��޸�ֵ��

	//�������޸�pԭ�е����ԣ��������´�����һ��ָ�룬ָ���p��ͬ�ĵ�ַ��
	persong6* p2 = const_cast<persong6*>(p);
	p2->name = "darren";
	cout << "p2 name=" << p2->name << endl;
}