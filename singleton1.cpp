//单例模式仅有一个实例，并提供一个全局访问点
#include<iostream>
using namespace std;

class singleton{
public:
    static singleton *GetInstance(){  //首次创建实例，会一直持续到函数结束调用析构函数释放
        if(_instance==NULL){
            _instance=new singleton();
        }
        return _instance;
    }
private:
    singleton(){};
    ~singleton(){};
    //单例模式，就是一个类中只允许初始化一个实例，那就要禁用其他
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
    static singleton *_instance;    //静态全局变量，所有类的对象可以共享访问这个资源
};
singleton *singleton::_instance=NULL;

#if 0
//如果不禁用：
Singleton* s1 = Singleton::getInstance();

    // 使用拷贝构造函数创建新实例
    Singleton* s2 = new Singleton(*s1);

    // 使用拷贝赋值运算符创建新实例
    Singleton* s3 = Singleton::getInstance();
    *s3 = *s1;

    // 使用移动构造函数创建新实例
    Singleton* s4 = new Singleton(std::move(*s1));

    // 使用移动赋值运算符创建新实例
    Singleton* s5 = Singleton::getInstance();
    *s5 = std::move(*s1);
#endif

int main(){
    return 0;
}

//问题：如果中间什么都不操作,在函数结束的时候根本不会调用析构函数，导致有一些可能的文件写入操作根本不会实现，这个时候需要智能指针，具体见singleton2.cpp