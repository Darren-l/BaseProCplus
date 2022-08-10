#include <iostream>
#include <pthread.h>
#include <unistd.h> 

using namespace std;

void test01();
void test02();
void test03();

/*
    在linux环境编译时，需要带上-lphread参数，否则会报错找不到函数。

    分离式线程和非分离式线程区别在于前者为异步（普通开线程），后者为同步（join）。

*/
int main(){

    //#### 测试最简单的线程开辟方式。
    // test01();

    //#### C语言thread的join函数。
    // test02();

    //#### C语言中的synchronize
    test03();

    return 0;

}


//定义互斥锁。
pthread_mutex_t mutex;

/*
    pthread_mutex可以用于实现java的synchronize，同时也能代替wait和notify。
*/
void test03(){

    cout << "test03..." << endl;
    //锁初始化
    pthread_mutex_init(&mutex, NULL);

    //加锁，这里相当于是java的synchronize。
    pthread_mutex_lock(&mutex);

    cout << "在这里的代码只允许一个线程执行..." << endl;

    //释放锁
    pthread_mutex_unlock(&mutex); 

    //销毁锁
    pthread_mutex_destroy(&mutex);

    cout << "test03 ---> end..." << endl;
}


void * thread_call_back2(void * para) { 
    //转化线程携带的参数。
    int * mpara = static_cast<int *>(para); 
    cout << "这里是异步线程:" << *mpara << endl;
    return 0;   //返回值为指针类型，如果没东西要返回也要返回0。
}

void test02(){

    cout << "test02..." << endl;
    int param = 100;
    pthread_t thread_id;

    pthread_create(&thread_id, 0, thread_call_back2, &param);

    //效果与java的join一致，当前线程会等待thread_id执行。
    pthread_join(thread_id,0);

    cout << "test02 ---> end..." << endl;
}


/*
    C中的线程启动方式类似于java回调。
*/
void * thread_call_back(void * para) { 
    //转化线程携带的参数。
    int * mpara = static_cast<int *>(para); 
    cout << "这里是异步线程:" << *mpara << endl;
    return 0;   //返回值为指针类型，如果没东西要返回也要返回0。
}

/*
    int pthread_create (pthread_t *,  //线程ID
                        const pthread_attr_t *, // 线程属性
		                void *(*)(void *), //回调函数定义
		                void *); // 回调函数传参的参数
*/
void test01(){
    cout << "test01..." << endl;
    int param = 100;
    pthread_t thread_id;

    //以这样的方式开辟线程，若开辟的栈走完了，那么线程将不会执行（与java一致）。
    pthread_create(&thread_id, 0, thread_call_back, &param);

    //这里使用sleep等待下线程的执行。
    sleep(3);
}