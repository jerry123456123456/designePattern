#include <iostream>
#include <string>
using namespace std;

// 抽象处理者
class Handler {
public:
    virtual void handleRequest(const std::string request) = 0;
    virtual void setNextHandler(Handler* next) = 0;
};

// 具体处理者 A
class ConcreteHandlerA : public Handler {
private:
    Handler* nextHandler;

public:
    ConcreteHandlerA() : nextHandler(nullptr) {}         //初始值必须置空
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

// 具体处理者 B
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
责任链模式（Chain of Responsibility Pattern）是一种行为设计模式，它允许多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的直接耦合关系。在责任链模式中，将请求沿着一个处理链传递，直到有一个对象处理该请求为止。每个处理者对象都包含对下一个处理者对象的引用，请求在处理链上传递，直到有处理者能够处理请求或者请求达到链的末端。

责任链模式通常涉及以下角色：
1. **抽象处理者（Handler）：** 定义了处理请求的接口，包含一个指向下一个处理者的引用.
2. **具体处理者（Concrete Handler）：** 实现了抽象处理者接口，负责处理请求，如果自己无法处理，则将请求传递给下一个处理者。
责任链模式主要解决以下问题：
1. **解耦请求发送者和接收者：** 责任链模式通过将请求发送者和接收者解耦，使得发送者无需知道具体的处理者，只需将请求发送给第一个处理者，由处理者链自行决定谁来处理请求。
2. **动态指定处理者：** 可以动态改变处理链，新增或移除处理者，灵活调整处理流程，而不需要修改客户端代码。
3. **处理者无需知道整个处理流程：** 每个处理者只需关注自己能否处理请求，不需要了解整个处理流程，增强了模块化和可维护性。
总的来说，责任链模式提供了一种将请求沿着处理链传递的机制，使得多个对象都有机会处理请求，从而实现请求的发送者和接收者之间的解耦，提高系统的灵活性和可扩展性。
#endif