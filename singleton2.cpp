#include <memory>
#include <iostream>
using namespace std;

class Singleton {
public:
    static shared_ptr<Singleton> GetInstance() {
        if (!_instance) {
            _instance = shared_ptr<Singleton>(new Singleton());
        }
        return _instance;
    }

    // ������������Ϊ����
    ~Singleton() {};

private:
    Singleton() {};

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    // ���� shared_ptr Ϊ��Ԫ,��������ָ����ܹ��������е�˽�г�Ա
    friend shared_ptr<Singleton>;

    static shared_ptr<Singleton> _instance;
};

shared_ptr<Singleton> Singleton::_instance = NULL;

int main() {
    shared_ptr<Singleton> instance = Singleton::GetInstance();

    // �ڳ������ʱ���Զ��������������ͷ���Դ
    return 0;
}

//������ָ���������ȷ��singleton���ʵ���ڲ���Ҫ��ʱ���ܹ���ȷ�ͷ��ڴ棬�����ڴ�й©��
//ͬʱ��share_ptr����ָ�뻹���Է���Ĺ�������������ڣ���Ϊ������ָ���ʵ��������ָ�붼�����������ʱ��ʵ���ᱻ�Զ�����
//���ֻ��һ������ָ��������ʵ�����Ǿ���unique_ptr

//������û��ʹ�� `std::make_shared`������ֱ��ʹ�� `new` �ؼ��������� `Singleton` ���󲢽����װ�� `std::shared_ptr` �С���Ȼ `std::make_shared` �ںܶ���������Ƽ��ķ�ʽ����ֱ��ʹ�� `new` Ҳ����Ч�ġ���ĳЩ����£�ֱ��ʹ�� `new` ���ܸ��ʺϣ�������Ҫ���ݶ���Ĳ��������캯��ʱ��

//����Ĵ����У�`Singleton::GetInstance()` �������𷵻� `Singleton` ���ʵ����������Ҫʱ������ʵ������ `main()` �����У����ȡ�� `Singleton` ��ʵ�����洢�� `shared_ptr` �У����������ʱ��`shared_ptr` ����������������ͷ���Դ��
//�ܵ���˵������û��ʹ�� `std::make_shared`����Ĵ�����Ȼ����Ч�Ĳ���ʵ���˵���ģʽ��ʹ�� `std::make_shared` ��Ҫ��Ϊ�˱���ֱ��ʹ�� `new` �� `delete`���Ӷ���ߴ���İ�ȫ�ԺͿɶ��ԡ�

//�����ʹ������ָ�룬��singleton3.cpp