/*
* ̽��C++�е�ǳ�����������
* 
* Java�еĿ�����
*	1. ���ÿ������������ַ��ͬ������ָ������ݶ���һ�¡�����ֵ���������ζ�Ϊ���ÿ�����
		P p1 = new P(); P p2 = p1; // p2����Ϊ�¶��󣬵�ʵ��ָ�������p1ͬһ�����ݶ����ڴ��ַ��
*	2. ǳ������������ÿ��������ݶ����ڴ��ַҲ���µģ��������ڲ����ó�Ա���Ǻͱ������Ķ���һ�¡�
*	3. ����������ǳ�������ڲ����ó�Ա��Ӧ�����ݶ���Ҳ����new�����ġ�
* 
* C++�еĿ�����
*	1. ���ÿ�������java����һ�¡�
		P p1 = new p();  P* p2 = p1; //����ֵ��ֵ��ָ��ʱ��Ϊ���ÿ�����
*	2. ǳ������������javaһ�¡�����ֵ�����������ݶ��󣬶����߿���������
		P p1 = new P(); P p2 = p1;	//��java��ͬ��������ĸ�ֵΪǳ������
*		setP(p1);	//���������ܲ�������Ϊ������ôҲ����ǳ������
*	3. �����������javaһ�¡�
* 
* ���ڿ�������������⣬C++����Ҫ�ǳ�ע��ĵ㣺
*	����1��
*		���ڸ�ֵ�ͺ���Ϊʵ���Ĵ��ζ���ǳ���������蹹����new�˶����ڶ��ϣ�����������free�˸ö��������ڵ���
		�˴���Ϊʵ������ĺ���ʱ���ض�����ÿ������������¶��������ں����У�������������ֻ��������ͷŸö���
		��ô����������ö�Σ��ͻ������������freeͬһ�������Ա�����⡣

	�����ʽ��
		1. �����������new������ô��Ӧ���ڿ��������У�Ҳ��Ҫ��new�Ķ������Ըö�����������
		2. ����������ָ�����&����Ϊ�����ܿ����������������ĵ��á�
* 
*/

#define _CRT_SECURE_NO_WARNINGS	//���windoows����strcpy����
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
	cout << "���췽��ִ�� -- ��ǰ�����ַ��" << this << endl;
}

ObjectCp::~ObjectCp()
{
	cout << "����������ִ�� �����ַ=" << this <<  endl;
	//�����е���free��Ҫע�⿽����������Ҫ����ö���
	free(name);
}

ObjectCp::ObjectCp(const ObjectCp& cp)
{
	this->name = (char*)malloc(20);
	strcpy(this->name, name);
	cout << "����������ִ��" << endl;

}

void ObjectCp::fun1(ObjectCp objcp)
{
	cout << "ִ��fun1�� objcp�ĵ�ַ��" << &objcp << "  this�ĵ�ַΪ" << this << endl;
}

void ObjectCp::fun2()
{
	cout << "ִ��fun2...."<< endl;
}


int mainTg1(int) {
	
	//#### C++����ô��ֵ�ᱨ��������string��
	//char* aa = "qwe";

	////#### test01������main�ж�����������ڡ�
	//char name [5]  = "abcd";
	//ObjectCp obj(name);	//obj���mianִ�����ŵ���������
	//cout << "���󹹽�����" << endl;

	////#### test02:���Զ���ĸ�ֵ�����߿���������
	//char name[5] = "abcd";
	//ObjectCp obj(name);	
	////���߿�������Ĭ�Ͻ���ǳ������ʵ��obj��obj2��ַ��ͬ����ָ������ݵ�ַ��ͬ��
	//ObjectCp obj2 = obj;
	//ObjectCp obj8(name);
	//obj8 = obj;	//��ʱ������ÿ�����������������ʱ��ֵ�Ż��߹��죡


	////#### test03:���Ժ�������Ϊ����ʱ������ÿ���������
	//char name[5] = "abcd";
	//ObjectCp obj(name);	
	//ObjectCp obj2(name);
	//cout << "��ʼ���ò���Ϊ����ķ���..." << endl;
	////��������Ϊ����ʱ�����߿������������¶����˳�������ʱ���ö���ᱻ�ͷţ���������
	////��������Ĭ��Ϊǳ����������������new����������free����ô����������Ҳ����Ҫ�к͹�������ͬ��new��
	//obj.fun1(obj2);
	//cout << "����ķ���ִ�����..." << endl;

	////#### test04: ����ָ�븳ֵ�������߿����������൱�ڸ�ֵ���á�
	//char name[5] = "abcd";
	//ObjectCp obj(name);
	//ObjectCp* cp = &obj;

	return 0;
}


