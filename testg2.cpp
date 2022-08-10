#include <iostream>
#include <exception>
#include <vector>
#include <set>

using namespace std;


/*
	������ʼ����
*/
class Per2 {
public:
	string namep2;
	Per2(string name) :namep2(name) {};
};

class Per3 {
public:
	string name;

	//#### ������а���������Ա���ó�Ա����Ҫ�ڹ���ʱ��ʼ����
	Per2 p2;

	//#### ��ʼ���ķ�ʽ�����֣�1. ���캯������������Ա�Ĺ�����г�ʼ����
	Per3(string name) :name(name),p2(name) {};

	//#### 2. ���캯���У�ֱ�ӵ��ÿ���������
	Per3(Per2 p) :name(name), p2(p) {};

};

/*
	ν��
*/
class Obj {
public:
	//void operator()() {
	//	cout << "( )�������ض���" << endl;
	//}

	//һԪν��
	bool operator()(int arg) {
		cout << "arg=" << arg << endl;
		return true;
	}

	//���������������Ƕ�Ԫν��
	void operator()(int arg, int arg2) {
		cout << "arg=" << arg << endl;
	}
};

void testTg2t01();
void testTg2t02();
void testTg2t03();

int mainTg02(){
	
	//#### �������Ա��ʼ����

	//##### ������ض���()
	//Obj obj;
	//obj();	//���õ����ض���()�з�װ�ķ�����
	
	// #### ν��
	//����һԪν�ʣ��ض���()�������������д��������������Ǽ�Ԫν�ʡ�
	testTg2t01();

	//#### Ԥ���庯��
	testTg2t02();

	//#### Ԥ���庯��plus��ʵ��
	testTg2t03();

	return 0;
}

//Ԥ�ú���ʵ�֡�
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
	��νԤ���庯���������Ѿ���װ�õ�һЩ��������plus��֧�ֻ������͵���ӡ�
*/
void testTg2t02() {
	//Ԥ�õ�int�ͼӷ�
	plus<int> add;
	int re = add(1, 1);
	cout << re << endl;

	//Ԥ�õ�string�ͼӷ�
	plus<string> addString;
	string re2 = addString("AAAA", "BBB");
	cout << re2 << endl;
}


//����true��ʾ�жϻص���������������Ԫ�ء�
bool fun2(int arg2) {
	cout << "arg2=" << arg2 << endl;
	return true;
}

/*
*	ν�ʣ���ν��ν�ʣ�������д���()�������ʹ������()��ʽ��Ϊ�������д��ݡ����ַ�ʽ
*		�ʹ���ͨ�������������ڣ���һ����İ�װ�����Զ������Ա��������¼һЩν�ʺ�����
*		��Ҫ��¼��ֵ��
* 
*		���費��Ҫ�ڻص��м�¼�κ��¼�����ô����ֱ�Ӵ��ص��������Ҫ��¼�ص��е�һЩ
*		״̬����ʹ��ν�ʣ��������Ա����¼��
* 
*		Դ���д�����ʹ����ν�ʺ�����������ͨ�����Ĵ��ݡ�
* 
	��kotlin�ĸ߽׺����У�ͨ���������������ַ�ʽ���ܣ�
		1. ��lambda���ʽ��
		2. ����һ�����������������󴫵ݽ�ȥ��
	����C++�У�Ҳ�����ַ�ʽ��
		1. ��ν�ʡ�
		2. ����ͨ������
*/
void testTg2t01() {
	vector<int> vt;
	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(5);

	//���һ�������൱��kotlin�еĸ߽׺����Ĵ�����������
	//������Դ�һ��()�Ĳ������ض��壬Ҳ����ֱ�Ӵ���������
	//vector<int>::iterator it = find_if(vt.begin(), vt.end(), fun2);	//��ͨ����
	vector<int>::iterator it = find_if(vt.begin(), vt.end(), Obj());	//ν�ʺ���
	for (it = vt.begin(); it != vt.end(); it ++ ) {
		cout << "��ʼ������it=" << *it << endl;
	}

}

