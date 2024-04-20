#include <iostream>
#include <memory>

// ��Ʒ��
class Product {
public:
    virtual void operation() = 0;
};

// �����Ʒ�� A
class ConcreteProductA : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProductA operation" << std::endl;
    }
};

// �����Ʒ�� B
class ConcreteProductB : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProductB operation" << std::endl;
    }
};

// ������
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
    
    // ������Ʒ A
    std::shared_ptr<Product> productA = factory.createProduct(1);
    productA->operation();
    
    // ������Ʒ B
    std::shared_ptr<Product> productB = factory.createProduct(2);
    productB->operation();

    return 0;
}

#if 0
����ģʽ��һ�ִ��������ģʽ�����ṩ��һ�ִ�������Ľӿڣ��������������ʵ�����ĸ��ࡣ����ģʽͨ������һ����������Ľӿڣ��������ʵ�������̷�װ�ڹ������У��Ӷ�ʵ�ֶ���Ĵ�����ʹ�ô���ķ��롣

����ģʽ������������⣺

1. **��װ����Ĵ�������**������ģʽ�������ʵ�������̷�װ�ڹ������У��ͻ��˴���ֻ��Ҫ��ע���ʹ�ö��󣬶�������Ķ���Ĵ������̡�

2. **��������ʹ�úʹ���**������ģʽ������Ĵ�����ʹ�ý���ͻ��˴��벻��Ҫֱ����������Ķ����ֻ࣬��Ҫͨ������������ȡ����Ķ���ʵ����

3. **֧�ִ�����չ**������ģʽͨ������һ����������Ľӿڣ��������ɵ���չ������µĶ������ͣ�������Ҫ�޸����еĿͻ��˴��롣

4. **���ض���ľ���ʵ��**������ģʽ�������ض���ľ���ʵ��ϸ�ڣ�ֻ��¶���ͻ���һ������Ľӿڣ��Ӷ���ߴ���İ�ȫ�ԺͿ�ά���ԡ�

�ܵ���˵������ģʽ�����ڵ��ͻ�����Ҫ���ݲ�ͬ�������������������ͬ���͵Ķ���ʱ�����ߵ�����Ĵ������̱Ƚϸ���ʱ��ͨ������ģʽ������ʵ�ֶ���Ķ�̬�����������ʵ�������̵ķ�װ���Լ��ͻ�������������Ľ���Ӷ���ߴ��������ԺͿ�ά���ԡ�
#endif