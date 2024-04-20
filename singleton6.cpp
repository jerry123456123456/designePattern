//上一个版本的代码太长了，接下来的代码直接使用静态全局变量
//这个代码主要利用了c++11的magic static特性：如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初始化结束
//C++11引入了Magic Statics特性，它允许在函数内部的静态变量第一次被使用时进行初始化，而不是在程序启动时。这种特性的好处是可以延迟静态变量的初始化，直到它们被需要为止，从而提高程序的性能和效率。
#include<iostream>
using namespace std;

class singleton{
public:
    static singleton& GetInstance(){
        static singleton instance;
        return instance;
    }
private:
    singleton(){};
    ~singleton(){};
    //单例模式，就是一个类中只允许初始化一个实例，那就要禁用其他
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
};

int main(){
    return 0;
}

//下一个版本使用类模板，提高代码的复用性