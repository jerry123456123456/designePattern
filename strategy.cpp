#include <iostream>

// ���Խӿ�
class Strategy {
public:
    virtual void execute() = 0;
};

// ���������A
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy A" << std::endl;
    }
};

// ���������B
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy B" << std::endl;
    }
};

// ��������
class Context {
private:
    Strategy* strategy;
    Strategy* originalStrategy;

public:
    Context(Strategy* strategy) : strategy(strategy), originalStrategy(strategy) {}

    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy() {
        strategy->execute();
    }

    void restoreOriginalStrategy() {
        strategy = originalStrategy;
    }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);
    context.executeStrategy();

    context.setStrategy(&strategyB);
    context.executeStrategy();

    // ����ʹ��ԭ���Ĳ���
    context.restoreOriginalStrategy();
    context.executeStrategy();

    return 0;
}

#if 0
����ģʽ��һ����Ϊ���ģʽ����������һϵ���㷨������ÿ���㷨��װ�ɵ����Ĳ����࣬ʹ����Щ�㷨�����໥�滻�����ҿͻ��˴��벻��Ӱ�졣�ڲ���ģʽ�У��㷨��ѡ�����������ʱ��̬�ı䣬�Ӷ�ʵ���㷨������ԺͿ���չ�ԡ�

����ģʽ��Ŀ���ǽ��㷨�Ķ��塢ʹ�ú͹�����룬�Ա��ܹ������ر�����л���ͬ���㷨���ԣ�������Ҫ�޸Ŀͻ��˴��롣ͨ������ģʽ�����ǿ��Խ��㷨��ʵ��ϸ�ڷ�װ�ڶ����Ĳ������У��Ӷ���ߴ���Ŀ�ά���ԡ��ɶ��Ժ�����ԡ�

����ģʽͨ���������������

1. ��һ�������Ϊȡ���ڶ����㷨�е�һ�֣�����Щ�㷨���Զ����ڸ���仯ʱ��

2. ����Ҫ������ʱ��̬��ѡ���㷨ʱ����ʹ����ͬ�ӿ���Ҳ����ѡ��ͬ���㷨��

3. ��һ�����ж����Ϊ���壬����ʹ�ò���ģʽ����Щ����ʵ��Ϊ��ͬ�Ĳ����ࡣ

�ܵ���˵������ģʽ��Ŀ����ʹ�㷨��ѡ���ʹ�����㷨��ʵ������룬�Ӷ���ߴ��������ԡ�����չ�ԺͿ�ά���ԡ�
#endif