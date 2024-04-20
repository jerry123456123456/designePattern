//��һ���汾�Ĵ���̫���ˣ��������Ĵ���ֱ��ʹ�þ�̬ȫ�ֱ���
//���������Ҫ������c++11��magic static���ԣ�����������ڳ�ʼ����ʱ�򣬲���ͬʱ����������䣬�����߳̽��������ȴ���ʼ������
//C++11������Magic Statics���ԣ��������ں����ڲ��ľ�̬������һ�α�ʹ��ʱ���г�ʼ�����������ڳ�������ʱ���������Եĺô��ǿ����ӳپ�̬�����ĳ�ʼ����ֱ�����Ǳ���ҪΪֹ���Ӷ���߳�������ܺ�Ч�ʡ�
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
    //����ģʽ������һ������ֻ�����ʼ��һ��ʵ�����Ǿ�Ҫ��������
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
};

int main(){
    return 0;
}

//��һ���汾ʹ����ģ�壬��ߴ���ĸ�����