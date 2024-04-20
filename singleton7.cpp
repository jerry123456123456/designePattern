#include<iostream>
using namespace std;

template<typename T>
class singleton{
public:
    static T& GetInstance(){
        static T instance;
        return instance;
    }
protected:      //Ϊ���������ܹ����õõ������еĹ���������������������protected����
    virtual ~singleton(){}
    singleton(){} 
private:
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
};

class DesignPattern:public singleton<DesignPattern>{
   friend class singleton<DesignPattern>;   //��������̳еĸ�����ʹ��ģ�幹������ʵ�������Ա����ø������ʹ������Ĺ��캯���������������������Ԫ
private:
    DesignPattern(){}
    ~DesignPattern(){}
};

int main(){
    DesignPattern& instance = DesignPattern::GetInstance();
    return 0;
}