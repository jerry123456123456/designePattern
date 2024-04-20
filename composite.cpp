#include <iostream>
#include <vector>

class Component {
public:
    virtual void operation() = 0;
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual Component* getChild(int index) { return nullptr; }
};

class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation\n";
    }
};


class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void operation() override {
        std::cout << "Composite operation\n";
        for (Component* child : children) {
            child->operation();
        }
    }

    void add(Component* component) override {
        children.push_back(component);
    }

    void remove(Component* component) override {
        // Remove the component from children
    }

    Component* getChild(int index) override {
        if (index < children.size()) {
            return children[index];
        }
        return nullptr;
    }
};

int main() {
    Composite* composite = new Composite();
    composite->add(new Leaf());
    
    Composite* subComposite = new Composite();
    subComposite->add(new Leaf());
    subComposite->add(new Leaf());
    composite->add(subComposite);

    composite->operation();

    delete composite;
    
    return 0;
}

#if 0
组合模式（Composite Pattern）是一种结构型设计模式，它允许客户端统一处理单个对象和对象组合（包含子对象）的情况，使得客户端在处理单个对象和组合对象时具有一致性。组合模式将对象组织成树形结构，其中叶节点表示单个对象，而分支节点表示对象组合。

组合模式的主要目的是：

1. **统一处理对象和对象组合**：组合模式允许客户端以统一的方式处理单个对象和对象组合，无需区分它们。

2. **简化客户端代码**：客户端代码不需要关心对象是单个对象还是组合对象，从而简化了客户端代码的复杂性。

3. **递归组合结构**：通过组合模式，可以递归地组合对象，形成树形结构，使得处理复杂的嵌套结构变得简单。

组合模式通常用于以下情况：

- 当对象具有树形结构，并且需要以统一的方式处理单个对象和对象组合时。

- 当希望客户端代码能够对单个对象和组合对象进行一致的操作时。

- 当需要构建包含对象组合的层次结构，并希望以递归方式处理这种结构时。

总的来说，组合模式通过将对象组织成树形结构，使得客户端可以一致地处理单个对象和对象组合，从而简化了代码的复杂性并提高了代码的可维护性。
#endif