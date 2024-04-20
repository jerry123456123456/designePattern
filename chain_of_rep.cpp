#include <iostream>
#include <string>
using namespace std;

// ��������
class Handler {
public:
    virtual void handleRequest(const std::string request) = 0;
    virtual void setNextHandler(Handler* next) = 0;
};

// ���崦���� A
class ConcreteHandlerA : public Handler {
private:
    Handler* nextHandler;

public:
    ConcreteHandlerA() : nextHandler(nullptr) {}         //��ʼֵ�����ÿ�
    void handleRequest(const std::string request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA handles the request." << std::endl;
        } else if (nextHandler != NULL) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler available for the request." << std::endl;
        }
    }

    void setNextHandler(Handler* next) override {
        nextHandler = next;
    }
};

// ���崦���� B
class ConcreteHandlerB : public Handler {
private:
    Handler* nextHandler;

public:
    ConcreteHandlerB() : nextHandler(nullptr) {}         
    void handleRequest(const std::string request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB handles the request." << std::endl;
        } else if (nextHandler != NULL) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler available for the request." << std::endl;
        }
    }

    void setNextHandler(Handler* next) override {
        nextHandler = next;
    }
};

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;

    handlerA.setNextHandler(&handlerB);

    handlerA.handleRequest("A");
    handlerA.handleRequest("B");
    handlerA.handleRequest("C");

    return 0;
}

#if 0
������ģʽ��Chain of Responsibility Pattern����һ����Ϊ���ģʽ���������������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮���ֱ����Ϲ�ϵ����������ģʽ�У�����������һ�����������ݣ�ֱ����һ�������������Ϊֹ��ÿ�������߶��󶼰�������һ�������߶�������ã������ڴ������ϴ��ݣ�ֱ���д������ܹ����������������ﵽ����ĩ�ˡ�

������ģʽͨ���漰���½�ɫ��
1. **�������ߣ�Handler����** �����˴�������Ľӿڣ�����һ��ָ����һ�������ߵ�����.
2. **���崦���ߣ�Concrete Handler����** ʵ���˳������߽ӿڣ���������������Լ��޷����������󴫵ݸ���һ�������ߡ�
������ģʽ��Ҫ����������⣺
1. **�����������ߺͽ����ߣ�** ������ģʽͨ�����������ߺͽ����߽��ʹ�÷���������֪������Ĵ����ߣ�ֻ�轫�����͸���һ�������ߣ��ɴ����������о���˭����������
2. **��ָ̬�������ߣ�** ���Զ�̬�ı䴦�������������Ƴ������ߣ��������������̣�������Ҫ�޸Ŀͻ��˴��롣
3. **����������֪�������������̣�** ÿ��������ֻ���ע�Լ��ܷ������󣬲���Ҫ�˽������������̣���ǿ��ģ�黯�Ϳ�ά���ԡ�
�ܵ���˵��������ģʽ�ṩ��һ�ֽ��������Ŵ��������ݵĻ��ƣ�ʹ�ö�������л��ᴦ�����󣬴Ӷ�ʵ������ķ����ߺͽ�����֮��Ľ�����ϵͳ������ԺͿ���չ�ԡ�
#endif