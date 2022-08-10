#include <iostream>
#include <memory>

using namespace std;

void testTg401();
void testTg402();
void testTg403();
void testTg404();

/*
	����ָ�룬���þ��ǿ���Э��ָ�����ռ���ͷš����Ƽ�ʹ�ã������ֶ��ͷűȽϱ��ա�

	����ָ��ʵ���Զ��ͷŶ���ռ��ԭ��
		��������ͳ�Ƶ�ǰ��������count��,���Ϊ0����ö�������������������count���ӳ���ֻ��3�֣�
			1. ָ�������ù����ʼ�����ڹ���������ͳ�ơ�
			2. ָ�������ÿ���������ʼ�����ڿ�������������ͳ�ơ�
			3. ָ���������������ֵ����ʱҪ��д=������������ͳ��count��

	shared����ָ��ѭ������������
		�������ж������˶Է���������ָ���Ա�����໥��ֵ���ᵼ�¼�������+1�������ڴ�й©��

	����ָ���е�����java�е�weak�����ã�ʹ���ص����£�
		1.һ����ʼ�������涼��Ҫ������ָ�����������ʹ�á�
		2. weak����ָ����Խ�����������share������ָ��ĸ�ֵ����ʱshareָ�����������+1��
		2. ʹ��unique���shared���ã�ǰ�߲�����ѭ�����������⡣
		3. ͬһ��ָ�룬����ͬʱ����������ͬ��shared_ptr����ָ�룬ÿ������ָ��ֻ�ܴ���һ����ָͨ�롣

*/

class PersonTg4 {
public:
	string name = "darren";

	PersonTg4() {
		cout << "person�Ĺ��캯��" << endl;
	}

	~PersonTg4() {
		cout << "person����������" << endl;
	}

	PersonTg4(const PersonTg4& p) {
		cout << "person�Ŀ�������" << endl;
	}
};

int mainTg5() {

	//#### ����ָ��shared_ptr��ʹ�ã���ѭ�����������⡣
	//testTg401();

	//#### ����ָ��shared_ptr�����Զ����ͷŹ���ͬʱҲ���������� -- Ĭ��ֻ��������
	//testTg402();

	//#### ����ָ��weak_ptr��C++��������
	//testTg403();

	//#### unique_ptr,�ɴ���share��������ѭ���������⡣
	//testTg404();	

	cout << "end...." << endl;
	return 0;
}

class PersonTg5 {
public:
	weak_ptr<PersonTg5> person2; 
	shared_ptr<PersonTg5> person;

	~PersonTg5() {
		cout << "Person1 ��������" << endl;
	}
};

void testTg404() {
	//Ч���ͽӿ���shareһ�¡�
	PersonTg5* p2 = new PersonTg5();
	unique_ptr<PersonTg5> uniquePtr1(p2);
}

void testTg403() {
	cout << "testTg403...." << endl;

	//����������ָ�����
	PersonTg5* p2 = new PersonTg5();
	//��ָ�����ֵ��share����ָ�룬��ʱsh2�����ü�����+1
	shared_ptr<PersonTg5> sh2(p2);
	//��������ʵ�������ԡ�
	PersonTg5* p = new PersonTg5();

	//#### ����1����sh2��ֵ��һ��shָ�룬������������+1��
	//�ڽ�sh2��ֵ��p�����е�share����ָ�룬��ʱsh2���ü��������ٴ�+1
	p->person = sh2;
	//����sh2 ��count�����2.
	cout << "sh2 count=" << sh2.use_count() << endl;

	//#### ����2������sh2��ֵ��weakָ�룬�����������+1
	p->person2 = sh2;
	cout << "p count=" << sh2.use_count() << endl;

	cout << "testTg403.... endl" << endl;
}

/*
	�Զ�����ͷŻص���������ʱ�����͸ú��������ߡ�
*/
void deletePer(PersonTg4* p) {
	cout << "deletePer...." << endl;
	delete p;
}

void testTg402() {
	cout << "testTg402.." << endl;
	//��ʼ������ָ�룬���Զ����ͷŹ���
	std::shared_ptr<PersonTg4> p7(new PersonTg4, deletePer);

	cout << "testTg402.. end..." << endl;
}


/*
	����ָ��ʵ��ԭ��
		��ջ�������Ķ�������ջ����Զ�����������������ͳ�ƶ��������������Ϊ0ʱ�����ͷš�
*/
void testTg401() {
	cout << "test01.." << endl;

	PersonTg4* p = new PersonTg4;
	PersonTg4* p2 = new PersonTg4;


	shared_ptr<PersonTg4> sharePtr1(p);
	shared_ptr<PersonTg4> sharePtr2(p2);

	//ʹ��ʱͨ��get��ȡp����ȡ����p��ʵ�ʵ�ַ�������޸ĺ�p��ֵҲ����֮�ı䡣
	cout << "sh name=" << sharePtr1.get()->name << endl;
	sharePtr1.get()->name = "darren---ttt";
	cout << "sh name=" << p->name << endl;	//��֮�ı䡣
	
	//ʵ������ָ����������Ϊ0ʱ�������ᱻ�ͷš�
	cout << "sh cout=" << sharePtr1.use_count() << endl;
	
	cout << "test01.. end" << endl;

}
