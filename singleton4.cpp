#include<iostream>
#include<mutex>
using namespace std;

class singleton{
public:
    static singleton* GetInstance(){
        if(_instance==NULL){      //RAII 类的声明周期进行资料管理  双重检测
            lock_guard<std::mutex> lock(_mutex);  //当创建的时候，多线程可能会同时访问资源，这个时候就需要加锁
            if(_instance==NULL){
                _instance=new singleton();
                atexit(Destructor);
            }
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
    static mutex _mutex;
};

int main(){
    return 0;
}

//在c++98版本，代码的语义是基于单线程的，而现在出现了多核cpu
//而在c++11会对代码进行优化，例如编译器重排，cpu重排，可能会违反顺序一致性（前面的代码会在后面的代码之前执行），目的是让代码执行的速度更快
//因此会出现几种问题，比如可见性问题执行序问题。而在c++11中提供了解决办法，同步原语（原子变量和内存栅栏）
//见singleton.cpp5