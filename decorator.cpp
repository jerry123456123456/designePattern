#include <iostream>

// Component
class Coffee {
public:
    virtual void brew() = 0;
};

// ConcreteComponent
class SimpleCoffee : public Coffee {
public:
    void brew() override {
        std::cout << "Brewing simple coffee" << std::endl;
    }
};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    void brew() override {
        decoratedCoffee->brew();
    }
};

// ConcreteDecorator
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    void brew() override {
        CoffeeDecorator::brew();
        addMilk();
    }

    void addMilk() {
        std::cout << "Adding milk" << std::endl;
    }
};

#if 0
在我之前提供的示例代码中，装饰模式的具体实现如下：

- `Coffee` 是组件接口，定义了咖啡的基本行为。

- `SimpleCoffee` 是具体组件，实现了 `Coffee` 接口，表示简单的咖啡。

- `CoffeeDecorator` 是装饰器类，实现了 `Coffee` 接口，并持有一个 `Coffee` 对象的引用，在 `brew()` 方法中调用被装饰对象的 `brew()` 方法。

- `MilkDecorator` 是具体装饰器类，继承了 `CoffeeDecorator`，在 `brew()` 方法中扩展了添加牛奶的功能。

在这个示例中，`MilkDecorator` 类包裹了 `SimpleCoffee` 类。通过将 `SimpleCoffee` 对象传递给 `MilkDecorator` 的构造函数，我们可以在不改变 `SimpleCoffee` 类的情况下，动态地为其添加额外的功能（添加牛奶）。
#endif

int main() {
    Coffee* simpleCoffee = new SimpleCoffee();
    Coffee* coffeeWithMilk = new MilkDecorator(simpleCoffee);

    coffeeWithMilk->brew();

    delete simpleCoffee;
    delete coffeeWithMilk;

    return 0;
}

#if 0
装饰模式（Decorator Pattern）是一种结构型设计模式，它允许在不改变现有对象结构的情况下，动态地将新行为附加到对象上。该模式通过创建一个包装类（装饰器），来包裹原始的类，然后在不影响原始类结构的情况下，增加新的功能或责任。

装饰模式的主要目的是为了：

1. **动态地扩展对象的功能**：通过使用装饰器，可以在运行时动态地为对象添加新的行为，而无需修改现有代码。

2. **避免类爆炸**：装饰模式避免了创建大量子类来处理各种组合情况，从而避免类的数量急剧增加。

装饰模式通常用于以下情况：

- 当需要在不修改现有代码的情况下，动态地添加新功能或责任时。

- 当需要对对象的行为进行多次扩展，而子类的组合会导致类爆炸时。

- 当类的功能需要被分离成不同的层次时，可以使用装饰模式来实现这种分层。

总的来说，装饰模式提供了一种灵活的方式来动态地添加功能，同时避免了代码修改和维护的复杂性。它使得代码更具扩展性和可维护性。
#endif