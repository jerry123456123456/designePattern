#include <iostream>
#include <vector>

// �۲����� Observer
class Observer {
public:
    virtual void update() = 0;
};
/////////////////////////////////////////////////////////////
// ������ Subject
class Subject {
public:
    // ��ӹ۲���
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    // �Ƴ��۲���
    void detach(Observer* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    // ֪ͨ�۲���
    void notify() {
        for (Observer* observer : observers) {  //observers�������ÿһ��Ԫ�ظ�ֵ��observer��������update()  
            observer->update();
        }
    }
    // ����״̬
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
// ����۲����� ConcreteObserver
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(Subject* subject) : subject(subject) {   
        //����ĳ�Ա��ʼ���б�ȼ��ڣ�
        //this->subject=subject;
        subject->attach(this);    //�����this�ǵ�ǰ����observer1����observer2��Ҳ����˵Subject�ഴ����subject�����е�observers����β����Ԫ��
    }

    ~ConcreteObserver() {
        subject->detach(this);
    }

    void update() override {
        //���Ĵ����߼��ǣ�������������setState������ʱ�򣬽�subject���е�state��ֵ����֪ͨ�۲���
        //��֪ͨ�󣬵���������룬��ӡstate��ֵ
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
�۲���ģʽ��һ����Ϊ���ģʽ����������һ��һ�Զ��������ϵ���ö���۲��߶���ͬʱ�������յ�Ŀ�����״̬�ı仯��������ģʽ�У���Ŀ������״̬�����仯ʱ�������������Ĺ۲��߶��󶼻�õ�֪ͨ���Զ����¡�

�۲���ģʽ������������⣺

1. **����۲��ߺ�Ŀ��**���۲���ģʽʹ��Ŀ�����͹۲��߶���֮�����϶Ƚ��ͣ�Ŀ���������֪���۲��ߵľ���ʵ�֣�ֻ��Ҫά��һ���۲����б����״̬֪ͨ���ɡ�

2. **֧�ֹ㲥֪ͨ**��Ŀ�����״̬�ı仯����ͬʱ֪ͨ����۲��߶���ʹ��ϵͳ�еĲ�ͬ�����ܹ���ʱ��Ӧ�仯��

3. **ʵ�ֿ���ԭ��**��ͨ���۲���ģʽ�������ڲ��޸�Ŀ�����͹۲��߶��������£���̬������µĹ۲��߻�ɾ�����еĹ۲��ߣ����Ͽ���ԭ��

4. **����ϵͳ�ĸ�����**���۲���ģʽ��Ŀ�����͹۲��߶�����룬ʹ��ϵͳ�и�������֮��Ľ�����ü򵥣������ϵͳ�Ŀ�ά���Ժ���չ�ԡ�

�ܵ���˵,�۲���ģʽ�����ڵ�һ�������״̬�����仯��Ҫ֪ͨ��������,������Щ������Ҫ����״̬�ı仯������Ӧ�Ĵ���ʱ������ģʽ��ʵ���¼�����GUI��������Ϣ֪ͨ�ȳ����б��㷺Ӧ�á�
#endif