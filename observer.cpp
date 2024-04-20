#include <iostream>
#include <vector>

// 观察者类 Observer
class Observer {
public:
    virtual void update() = 0;
};
/////////////////////////////////////////////////////////////
// 主题类 Subject
class Subject {
public:
    // 添加观察者
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    // 移除观察者
    void detach(Observer* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    // 通知观察者
    void notify() {
        for (Observer* observer : observers) {  //observers容器里的每一个元素赋值给observer，并调用update()  
            observer->update();
        }
    }
    // 设置状态
    void setState(int state) {
        this->state = state;
        notify();
    }
    int getState() {
        return state;
    }
private:
    std::vector<Observer*> observers;
    int state;
};
///////////////////////////////////////////////////////////////
// 具体观察者类 ConcreteObserver
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(Subject* subject) : subject(subject) {   
        //上面的成员初始化列表等价于：
        //this->subject=subject;
        subject->attach(this);    //这里的this是当前对象，observer1或者observer2，也就是说Subject类创建的subject对象中的observers容器尾插新元素
    }

    ~ConcreteObserver() {
        subject->detach(this);
    }

    void update() override {
        //这块的代码逻辑是：当主函数调用setState函数的时候，将subject类中的state赋值，并通知观察者
        //被通知后，调用这个代码，打印state的值
        std::cout << "Observer received update. New state: " << subject->getState() << std::endl;   
    }

private:
    Subject* subject;
};

int main() {
    Subject subject;
    ConcreteObserver observer1(&subject);
    ConcreteObserver observer2(&subject);

    subject.setState(1);

    return 0;
}

#if 0
观察者模式是一种行为设计模式，它定义了一种一对多的依赖关系，让多个观察者对象同时监听并收到目标对象状态的变化。在这种模式中，当目标对象的状态发生变化时，所有依赖它的观察者对象都会得到通知并自动更新。

观察者模式解决了以下问题：

1. **解耦观察者和目标**：观察者模式使得目标对象和观察者对象之间的耦合度降低，目标对象无需知道观察者的具体实现，只需要维护一个观察者列表进行状态通知即可。

2. **支持广播通知**：目标对象状态的变化可以同时通知多个观察者对象，使得系统中的不同部分能够及时响应变化。

3. **实现开闭原则**：通过观察者模式，可以在不修改目标对象和观察者对象的情况下，动态地添加新的观察者或删除现有的观察者，符合开闭原则。

4. **降低系统的复杂性**：观察者模式将目标对象和观察者对象分离，使得系统中各个部分之间的交互变得简单，提高了系统的可维护性和扩展性。

总的来说,观察者模式适用于当一个对象的状态发生变化需要通知其他对象,并且这些对象需要根据状态的变化做出相应的处理时。这种模式在实现事件处理、GUI开发、消息通知等场景中被广泛应用。
#endif