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
���ģʽ��Composite Pattern����һ�ֽṹ�����ģʽ��������ͻ���ͳһ����������Ͷ�����ϣ������Ӷ��󣩵������ʹ�ÿͻ����ڴ������������϶���ʱ����һ���ԡ����ģʽ��������֯�����νṹ������Ҷ�ڵ��ʾ�������󣬶���֧�ڵ��ʾ������ϡ�

���ģʽ����ҪĿ���ǣ�

1. **ͳһ�������Ͷ������**�����ģʽ����ͻ�����ͳһ�ķ�ʽ����������Ͷ�����ϣ������������ǡ�

2. **�򻯿ͻ��˴���**���ͻ��˴��벻��Ҫ���Ķ����ǵ�����������϶��󣬴Ӷ����˿ͻ��˴���ĸ����ԡ�

3. **�ݹ���Ͻṹ**��ͨ�����ģʽ�����Եݹ����϶����γ����νṹ��ʹ�ô����ӵ�Ƕ�׽ṹ��ü򵥡�

���ģʽͨ���������������

- ������������νṹ��������Ҫ��ͳһ�ķ�ʽ����������Ͷ������ʱ��

- ��ϣ���ͻ��˴����ܹ��Ե����������϶������һ�µĲ���ʱ��

- ����Ҫ��������������ϵĲ�νṹ����ϣ���Եݹ鷽ʽ�������ֽṹʱ��

�ܵ���˵�����ģʽͨ����������֯�����νṹ��ʹ�ÿͻ��˿���һ�µش���������Ͷ�����ϣ��Ӷ����˴���ĸ����Բ�����˴���Ŀ�ά���ԡ�
#endif