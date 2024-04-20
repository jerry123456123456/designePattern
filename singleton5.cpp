#include<iostream>
#include<mutex>
#include<atomic>
using namespace std;

//load���Կ��������߳����²��������ݣ�store�޸������������߳̿ɼ�
//memory_order_acquire��memory_order_release֮�����еĴ���Ȳ��ᱻ�Ż������棬Ҳ���ᱻ�Ż�������
//
class singleton{
public:
    static singleton* GetInstance(){
        singleton *tmp=_instance.load(memory_order_relaxed);  //���_instance������ԭ�ӱ���,�ʹ���������䲻�ɲ��,load�ǿɼ�����ȡ�������ݣ���relaxedָ��ɢ�Ϳ�������Ż�
        atomic_thread_fence(memory_order_acquire);   //�ڴ�դ������˿ɼ��������ִ��������,������ʹ�ã�����ڹ��캯���ﻹʹ����ԭ�ӱ������Ϳ���ʹ��relaxed����Ϊ���������
        //�ڴ�դ����ֹ����Ĵ�����뵽ǰ��Ĵ����ǰ�棬��֤��֮ǰ�Ķ������Ժ���Ķ������ɼ�
        if(tmp==NULL){
            lock_guard<mutex> lock(_mutex);  //��ʹ��ԭ�Ӳ�����Ҳ�޷���ȫ��������������á�ԭ�Ӳ�������ȷ�����ݵ�һ���ԺͿɼ��ԣ��������ܽ���������ʴ����ľ�̬������
            tmp=_instance.load(memory_order_relaxed);
            if(tmp==NULL){
                tmp=new singleton;
            }

            atomic_thread_fence(memory_order_release);
            _instance.store(tmp,memory_order_relaxed);
            atexit(Destructor);
        }
        return tmp;
    }
private:
    static void Destructor(){
        singleton* tmp=_instance.load(memory_order_relaxed);
        if(tmp!=NULL){
            delete tmp;       
        }
    }
    singleton(){};
    ~singleton(){};
    //����ģʽ������һ������ֻ�����ʼ��һ��ʵ�����Ǿ�Ҫ��������
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
    static atomic<singleton*> _instance;
    static mutex _mutex;
};

atomic<singleton*> singleton::_instance;
mutex singleton::_mutex;

int main(){
    return 0;
}

//���������Ȼ������������Щ����