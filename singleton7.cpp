#include<iostream>
using namespace std;

template<typename T>
class singleton{
public:
    static T& GetInstance(){
        static T instance;
        return instance;
    }
protected:      //为了让子类能够调用得到父类中的构造和析构函数，必须放在protected里面
    virtual ~singleton(){}
    singleton(){} 
private:
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
};

class DesignPattern:public singleton<DesignPattern>{
   friend class singleton<DesignPattern>;   //由于子类继承的父类中使用模板构建子类实例，所以必须让父类可以使用子类的构造函数，所以这里必须声明友元
private:
    DesignPattern(){}
    ~DesignPattern(){}
};

int main(){
    DesignPattern& instance = DesignPattern::GetInstance();
    return 0;
}