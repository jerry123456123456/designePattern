#include<iostream>
#include<mutex>
using namespace std;

class singleton{
public:
    static singleton* GetInstance(){
        if(_instance==NULL){      //RAII ����������ڽ������Ϲ���  ˫�ؼ��
            lock_guard<std::mutex> lock(_mutex);  //��������ʱ�򣬶��߳̿��ܻ�ͬʱ������Դ�����ʱ�����Ҫ����
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
    //����ģʽ������һ������ֻ�����ʼ��һ��ʵ�����Ǿ�Ҫ��������
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

//��c++98�汾������������ǻ��ڵ��̵߳ģ������ڳ����˶��cpu
//����c++11��Դ�������Ż���������������ţ�cpu���ţ����ܻ�Υ��˳��һ���ԣ�ǰ��Ĵ�����ں���Ĵ���֮ǰִ�У���Ŀ�����ô���ִ�е��ٶȸ���
//��˻���ּ������⣬����ɼ�������ִ�������⡣����c++11���ṩ�˽���취��ͬ��ԭ�ԭ�ӱ������ڴ�դ����
//��singleton.cpp5