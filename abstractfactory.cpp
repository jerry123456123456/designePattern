#include <iostream>
/////////////////////////////////////////////////////////////////////////
// 抽象形状类
class Shape {
public:
    virtual void draw() = 0;
};

// 具体形状类：矩形
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Rectangle: draw() method" << std::endl;
    }
};

// 具体形状类：圆形
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Circle: draw() method" << std::endl;
    }
};
/////////////////////////////////////////////////////////////////////////
// 抽象颜色类
class Color {
public:
    virtual void fill() = 0;
};

// 具体颜色类：红色
class Red : public Color {
public:
    void fill() override {
        std::cout << "Inside Red: fill() method" << std::endl;
    }
};

// 具体颜色类：蓝色
class Blue : public Color {
public:
    void fill() override {
        std::cout << "Inside Blue: fill() method" << std::endl;
    }
};
/////////////////////////////////////////////////////////////////////////
// 抽象工厂类
class AbstractFactory {
public:
    virtual Shape* create_shape() = 0;
    virtual Color* create_color() = 0;
};

// 具体形状工厂类
class ShapeFactory : public AbstractFactory {
public:
    Shape* create_shape() override {
        return new Rectangle();
    }

    Color* create_color() override {
        return nullptr; // 不负责创建颜色对象
    }
};

// 具体颜色工厂类
class ColorFactory : public AbstractFactory {
public:
    Shape* create_shape() override {
        return nullptr; // 不负责创建形状对象
    }

    Color* create_color() override {
        return new Blue();
    }
};

int main() {
    AbstractFactory* shape_factory = new ShapeFactory();
    Shape* rectangle = shape_factory->create_shape();
    rectangle->draw();

    AbstractFactory* color_factory = new ColorFactory();
    Color* blue = color_factory->create_color();
    blue->fill();

    delete rectangle;
    delete blue;
    delete shape_factory;
    delete color_factory;

    return 0;
}

#if 0
抽象工厂模式是一种创建型设计模式，它提供了一种创建一系列相关或依赖对象的接口，而无需指定具体类。在抽象工厂模式中，客户端通过调用工厂接口来创建一组相关的产品对象，而不需要关心具体的产品类。这种方式可以使系统更具灵活性，能够轻松切换整个产品家族而不影响客户端代码。

抽象工厂模式通常涉及以下角色：

1. **抽象工厂（Abstract Factory）：** 定义了创建产品对象的接口，包括一组创建不同类型产品的方法。

   

2. **具体工厂（Concrete Factory）：** 实现了抽象工厂接口，在具体工厂中实现了创建一组相关产品的方法。

   

3. **抽象产品（Abstract Product）：** 定义了产品对象的接口，具体产品类将实现这些接口。

   

4. **具体产品（Concrete Product）：** 实现了抽象产品接口的具体产品类。

抽象工厂模式主要解决以下问题：

1. **封装变化：** 抽象工厂模式将对象的创建过程封装在工厂接口中，客户端不需要了解具体的产品类，从而使客户端代码与具体产品类解耦，可以灵活地替换整个产品家族。

   

2. **产品族的一致性：** 抽象工厂模式确保创建的产品是属于同一产品族的，保持产品之间的一致性，例如在创建界面元素时，保持按钮、文本框等元素的风格统一。

   

3. **易于扩展：** 当需要添加新的产品族时，只需要创建新的具体工厂类和具体产品类，而不需要修改现有代码，符合开闭原则。

总的来说，抽象工厂模式提供了一种创建一组相关对象的接口，帮助我们在需要创建多个相关对象时保持代码的灵活性和可扩展性。
#endif