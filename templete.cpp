#include <iostream>

// AbstractClass �ǳ����࣬������ģ�巽���ͳ��󷽷�
class AbstractClass {
public:
    // ģ�巽�����������㷨�ĹǼ�
    void templateMethod() {
        step1();
        step2();
        step3();
    }

    // ���󷽷�����Ҫ����ʵ��
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
};

// ConcreteClass �Ǿ������࣬ʵ���˳��󷽷�
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
ģ��ģʽ��һ����Ϊ���ģʽ����������һ���㷨�Ŀ�ܣ����㷨�ľ��岽���ӳٵ�������ʵ�֡�ģ��ģʽͨ������һ���㷨�ĹǼܣ����㷨�в���Ĳ��ַ��ڸ�����ʵ�֣������ɱ�Ĳ����ӳٵ�������ʵ�֣��Ӷ�ʵ�ִ��븴�úͼ����ظ���

ģ��ģʽ������������⣺

1. **���븴��**��ģ��ģʽͨ�����㷨��ͨ�ò��ַ��ڸ�����ʵ�֣�ʵ���˴���ĸ��á�����ֻ��Ҫʵ���ض��Ĳ��裬�Ӷ��������ظ���д���ƵĴ��롣

2. **�����չ��**��ģ��ģʽͨ�������㷨�Ŀ�ܣ�ʹ���������������չ���޸��㷨�е��ض����裬����Ӱ���㷨������ṹ��

3. **ʵ�ֿ���ԭ��**��ģ��ģʽ���Ͽ���ԭ��ͨ���ڸ����ж����㷨�ĹǼܣ������ڲ��޸ĸ�����������չ���޸��������Ϊ��

4. **Լ��������Ϊ**��ģ��ģʽ�������������ʵ�ֵ��㷨�ķ�Χ��ȷ�����㷨��ִ��˳����߼���

�ܵ���˵��ģ��ģʽ�����ڵ��㷨�д���һ�鹲ͬ�Ĳ��裬������ĳЩ����ľ���ʵ�ֿ��ܻ�������ͬ�������ͨ��ģ��ģʽ�����Խ�ͨ�õ��㷨������ڸ�����ʵ�֣������ɱ�Ĳ����ӳٵ�������ʵ�֣��Ӷ���ߴ���ĸ����Ժ�����ԡ�
#endif