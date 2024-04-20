//那么对于之前的问题(析构函数不调用),我们就使用atexit（）函数，在程序退出的时候调用传入的函数

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
    //单例模式，就是一个类中只允许初始化一个实例，那就要禁用其他
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

//但是这个代码又面临一个问题，就是单线程