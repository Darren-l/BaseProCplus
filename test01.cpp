#include <iostream>
using namespace std;

void test01t();
void test01t2();
void test01t3();
void test01t4();
void test01t5();

/*
	1. �������Ϊָ�룬��������++ --�Ĳ�����
	2. ����ָ���ָ���������������ָ���ָ������顣

*/
int mainT01() {
	
	//C++�¼ӵ�����
	//test01t();

	//C++���η�
	//test01t2();

	//C++����
	//test01t3();

	//C++�е�����&��
	test01t5();

	//��Ҫע��
	//test01t4();

	return 0;
}

int& test01t3t1(int a, int b) {
	//�������ö���������򣬲��ܳ����������������
	int add = a + b;
	//return add;

	//���ԣ���Ϊ��̬����������ȫ�ֵģ����Գ��˺���������Ҳ���ڡ�
	static int sadd = a + b;
	return sadd;
}

void test01t3t1(int& i) {
	i = 2000;
}
/*
	C++�е�����&��
		�Ѿ����ڵı�������һ�����֡�

	C++�е�&��ָ��*������
		1. �����ڿ����ã����ñ������ӵ�һ��Ϸ����ڴ档
		2. �����ʼ��ʱ��Ӧ�ø�ֵ�����Һ��ڲ�Ҫ��ָ����һ������
		3. ���õ��������޷�����������
*/
void test01t5() {
	int i = 100;
	int ii = 1000;
	int& iy = i;
	iy = ii;	//ʵ�ʸ�ֵ��ò��Ҳ���ᱨ��
	cout << "iy=" << iy << endl;

	//��������Ϊ��������,��ʱЧ����ָ��һ�¡�
	test01t3t1(iy);
	cout << "iy=" << iy << endl;

	//��������Ϊ����ֵ��
	int& iyy = test01t3t1(1, 2);
	cout << "iyy=" << iyy << endl;

	//�������õ�ַ
	int t1 = 10;
	int& tt = t1;
	//��ַһ�¡�
	cout << "t1p=" << &t1 << endl << "t2p=" << &tt << endl;
}


void test01t3() {
	//C++�У���ø���ָ�븳ֵNull,�������Ը����Ƿ�Ϊ0�жϸ�ֵ�Ƿ�Ϊ�ա�
	int* i = NULL;
	cout << "i ��ֵ�� " << i <<endl;
}


void test01t4() {

	//��Cһ����ָ�����Ϊ��������ķ�ʽ������Ҫ��ס��ָ�뱾����Զ�����Ը�ֵ��
	int  var[3] = { 10, 100, 200 };
	//var++;	//*(var++) = 300 ���ַ�ʽ�����ԡ�
	*(var + 1) = 300;	//��ȷ��ע��++��var+1����
}

/*
	unsigned �� signed ���λ������͡�

	C++ �ر�ĵط���
		1. long��short������������int����ȻҲ����ֱ�Ӻ�Cһ��дlong��
		2. unsigned int y��ʱ��int����ʡ�ԡ�

*/
void test01t2() {
	//int����ʡ�ԡ�
	unsigned x;
	unsigned int y;

	//short����
	short int i;           // �з��Ŷ�����
	short unsigned int j;  // �޷��Ŷ�����

	//��ֵ���ڼĴ����У��õ��١�
	register int  miles;

	//������ǰ�̶߳��С�
	//thread_local int x;

}

const int coni = 100;
/*
	�����C��C++������
		1. bool��true��false��ʵ�ʴ�ӡֵ��Ȼ��0��1
		2. string: �ַ������͡�
		3. const���������η���
		4. �����ʽcout+endl��
*/
void test01t() {
	//C++�����C������һ��bool���͡�
	bool b = true;
	cout << "b=" << b << endl;//ʵ�ʴ�ӡΪ0/1

	//���ַ���
	wchar_t wc = 'c';
	cout << "wc=" << wc << endl;//��ӡ����int����

	//��ͨ�ַ�
	char c = 'c';
	cout << "c=" << c << endl;

	//�¼ӵ��ַ�������,��java���ơ�
	string str = "darren\
123";
	str.append("ddddddd");
	str + "cccccc";	//����ֱ�����
	int size = str.size();
	cout << "str=" << str << "size="<< size << endl;

	//���const������
	cout << "const=" << coni << endl;

	short int s = 100;
	cout << "shot=" << s << endl;
}



