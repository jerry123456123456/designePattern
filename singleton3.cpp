//��ô����֮ǰ������(��������������),���Ǿ�ʹ��atexit�����������ڳ����˳���ʱ����ô���ĺ���

#include<iostream>
#include<cstdlib>
using namespace std;

class singleton{
public:
    static singleton* GetInstance(){
        if(_instance==NULL){
            _instance=new singleton();
            atexit(Destructor);
        }
        return _instance;
    }

private:
    static void Destructor(){
        if(_instance!=NULL){
            delete _instance;
            _instance=NULL;
        }
    }

    singleton(){};
    ~singleton(){};
    //����ģʽ������һ������ֻ�����ʼ��һ��ʵ�����Ǿ�Ҫ��������
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
    static singleton *_instance;
};

singleton *singleton::_instance=NULL;

int main(){
    return 0;
}

//�����������������һ�����⣬���ǵ��߳�