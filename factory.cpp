#include <iostream>
#include <memory>

// 产品类
class Product {
public:
    virtual void operation() = 0;
};

// 具体产品类 A
class ConcreteProductA : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProductA operation" << std::endl;
    }
};

// 具体产品类 B
class ConcreteProductB : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProductB operation" << std::endl;
    }
};

// 工厂类
class Factory {
public:
    std::shared_ptr<Product> createProduct(int type) {
        switch (type) {
            case 1:
                return std::make_shared<ConcreteProductA>();
            case 2:
                return std::make_shared<ConcreteProductB>();
            default:
                return nullptr;
        }
    }
};

int main() {
    Factory factory;
    
    // 创建产品 A
    std::shared_ptr<Product> productA = factory.createProduct(1);
    productA->operation();
    
    // 创建产品 B
    std::shared_ptr<Product> productB = factory.createProduct(2);
    productB->operation();

    return 0;
}

#if 0
工厂模式是一种创建型设计模式，它提供了一种创建对象的接口，但允许子类决定实例化哪个类。工厂模式通过定义一个创建对象的接口，将对象的实例化过程封装在工厂类中，从而实现对象的创建和使用代码的分离。

工厂模式解决了以下问题：

1. **封装对象的创建过程**：工厂模式将对象的实例化过程封装在工厂类中，客户端代码只需要关注如何使用对象，而无需关心对象的创建过程。

2. **解耦对象的使用和创建**：工厂模式将对象的创建和使用解耦，客户端代码不需要直接依赖具体的对象类，只需要通过工厂类来获取所需的对象实例。

3. **支持代码扩展**：工厂模式通过定义一个创建对象的接口，可以轻松地扩展和添加新的对象类型，而不需要修改现有的客户端代码。

4. **隐藏对象的具体实现**：工厂模式可以隐藏对象的具体实现细节，只暴露给客户端一个抽象的接口，从而提高代码的安全性和可维护性。

总的来说，工厂模式适用于当客户端需要根据不同的条件或参数来创建不同类型的对象时，或者当对象的创建过程比较复杂时。通过工厂模式，可以实现对象的动态创建、对象的实例化过程的封装，以及客户端与具体对象类的解耦，从而提高代码的灵活性和可维护性。
#endif