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
����֮ǰ�ṩ��ʾ�������У�װ��ģʽ�ľ���ʵ�����£�

- `Coffee` ������ӿڣ������˿��ȵĻ�����Ϊ��

- `SimpleCoffee` �Ǿ��������ʵ���� `Coffee` �ӿڣ���ʾ�򵥵Ŀ��ȡ�

- `CoffeeDecorator` ��װ�����࣬ʵ���� `Coffee` �ӿڣ�������һ�� `Coffee` ��������ã��� `brew()` �����е��ñ�װ�ζ���� `brew()` ������

- `MilkDecorator` �Ǿ���װ�����࣬�̳��� `CoffeeDecorator`���� `brew()` ��������չ�����ţ�̵Ĺ��ܡ�

�����ʾ���У�`MilkDecorator` ������� `SimpleCoffee` �ࡣͨ���� `SimpleCoffee` ���󴫵ݸ� `MilkDecorator` �Ĺ��캯�������ǿ����ڲ��ı� `SimpleCoffee` �������£���̬��Ϊ����Ӷ���Ĺ��ܣ����ţ�̣���
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
װ��ģʽ��Decorator Pattern����һ�ֽṹ�����ģʽ���������ڲ��ı����ж���ṹ������£���̬�ؽ�����Ϊ���ӵ������ϡ���ģʽͨ������һ����װ�ࣨװ��������������ԭʼ���࣬Ȼ���ڲ�Ӱ��ԭʼ��ṹ������£������µĹ��ܻ����Ρ�

װ��ģʽ����ҪĿ����Ϊ�ˣ�

1. **��̬����չ����Ĺ���**��ͨ��ʹ��װ����������������ʱ��̬��Ϊ��������µ���Ϊ���������޸����д��롣

2. **�����౬ը**��װ��ģʽ�����˴�����������������������������Ӷ�������������������ӡ�

װ��ģʽͨ���������������

- ����Ҫ�ڲ��޸����д��������£���̬������¹��ܻ�����ʱ��

- ����Ҫ�Զ������Ϊ���ж����չ�����������ϻᵼ���౬ըʱ��

- ����Ĺ�����Ҫ������ɲ�ͬ�Ĳ��ʱ������ʹ��װ��ģʽ��ʵ�����ֲַ㡣

�ܵ���˵��װ��ģʽ�ṩ��һ�����ķ�ʽ����̬����ӹ��ܣ�ͬʱ�����˴����޸ĺ�ά���ĸ����ԡ���ʹ�ô��������չ�ԺͿ�ά���ԡ�
#endif