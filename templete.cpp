#include <iostream>

// AbstractClass 是抽象类，定义了模板方法和抽象方法
class AbstractClass {
public:
    // 模板方法，定义了算法的骨架
    void templateMethod() {
        step1();
        step2();
        step3();
    }

    // 抽象方法，需要子类实现
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
};

// ConcreteClass 是具体子类，实现了抽象方法
class ConcreteClass : public AbstractClass {
public:
    void step1() override {
        std::cout << "Step 1" << std::endl;
    }

    void step2() override {
        std::cout << "Step 2" << std::endl;
    }

    void step3() override {
        std::cout << "Step 3" << std::endl;
    }
};

int main() {
    AbstractClass* myObject = new ConcreteClass();
    myObject->templateMethod();

    delete myObject;

    return 0;
}

#if 0
模板模式是一种行为设计模式，它定义了一个算法的框架，将算法的具体步骤延迟到子类中实现。模板模式通过定义一个算法的骨架，将算法中不变的部分放在父类中实现，而将可变的部分延迟到子类中实现，从而实现代码复用和减少重复。

模板模式解决了以下问题：

1. **代码复用**：模板模式通过将算法的通用部分放在父类中实现，实现了代码的复用。子类只需要实现特定的步骤，从而避免了重复编写相似的代码。

2. **提高扩展性**：模板模式通过定义算法的框架，使得子类可以灵活地扩展或修改算法中的特定步骤，而不影响算法的整体结构。

3. **实现开闭原则**：模板模式符合开闭原则，通过在父类中定义算法的骨架，可以在不修改父类的情况下扩展或修改子类的行为。

4. **约束子类行为**：模板模式限制了子类可以实现的算法的范围，确保了算法的执行顺序和逻辑。

总的来说，模板模式适用于当算法中存在一组共同的步骤，但其中某些步骤的具体实现可能会有所不同的情况。通过模板模式，可以将通用的算法步骤放在父类中实现，而将可变的部分延迟到子类中实现，从而提高代码的复用性和灵活性。
#endif