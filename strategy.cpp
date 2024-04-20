#include <iostream>

// 策略接口
class Strategy {
public:
    virtual void execute() = 0;
};

// 具体策略类A
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy A" << std::endl;
    }
};

// 具体策略类B
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy B" << std::endl;
    }
};

// 上下文类
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

    // 重新使用原来的策略
    context.restoreOriginalStrategy();
    context.executeStrategy();

    return 0;
}

#if 0
策略模式是一种行为设计模式，它定义了一系列算法，并将每种算法封装成单独的策略类，使得这些算法可以相互替换，而且客户端代码不受影响。在策略模式中，算法的选择可以在运行时动态改变，从而实现算法的灵活性和可扩展性。

策略模式的目的是将算法的定义、使用和管理分离，以便能够独立地变更和切换不同的算法策略，而不需要修改客户端代码。通过策略模式，我们可以将算法的实现细节封装在独立的策略类中，从而提高代码的可维护性、可读性和灵活性。

策略模式通常用于以下情况：

1. 当一个类的行为取决于多种算法中的一种，且这些算法可以独立于该类变化时。

2. 当需要在运行时动态地选择算法时，即使在相同接口下也可以选择不同的算法。

3. 当一个类有多个行为变体，可以使用策略模式将这些变体实现为不同的策略类。

总的来说，策略模式的目的是使算法的选择和使用与算法的实现相分离，从而提高代码的灵活性、可扩展性和可维护性。
#endif