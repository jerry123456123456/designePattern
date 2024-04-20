//����ģʽ����һ��ʵ�������ṩһ��ȫ�ַ��ʵ�
#include<iostream>
using namespace std;

class singleton{
public:
    static singleton *GetInstance(){  //�״δ���ʵ������һֱ���������������������������ͷ�
        if(_instance==NULL){
            _instance=new singleton();
        }
        return _instance;
    }
private:
    singleton(){};
    ~singleton(){};
    //����ģʽ������һ������ֻ�����ʼ��һ��ʵ�����Ǿ�Ҫ��������
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
    static singleton *_instance;    //��̬ȫ�ֱ�����������Ķ�����Թ�����������Դ
};
singleton *singleton::_instance=NULL;

#if 0
//��������ã�
Singleton* s1 = Singleton::getInstance();

    // ʹ�ÿ������캯��������ʵ��
    Singleton* s2 = new Singleton(*s1);

    // ʹ�ÿ�����ֵ�����������ʵ��
    Singleton* s3 = Singleton::getInstance();
    *s3 = *s1;

    // ʹ���ƶ����캯��������ʵ��
    Singleton* s4 = new Singleton(std::move(*s1));

    // ʹ���ƶ���ֵ�����������ʵ��
    Singleton* s5 = Singleton::getInstance();
    *s5 = std::move(*s1);
#endif

int main(){
    return 0;
}

//���⣺����м�ʲô��������,�ں���������ʱ����������������������������һЩ���ܵ��ļ�д�������������ʵ�֣����ʱ����Ҫ����ָ�룬�����singleton2.cpp