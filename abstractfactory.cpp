#include <iostream>
/////////////////////////////////////////////////////////////////////////
// ������״��
class Shape {
public:
    virtual void draw() = 0;
};

// ������״�ࣺ����
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Rectangle: draw() method" << std::endl;
    }
};

// ������״�ࣺԲ��
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Circle: draw() method" << std::endl;
    }
};
/////////////////////////////////////////////////////////////////////////
// ������ɫ��
class Color {
public:
    virtual void fill() = 0;
};

// ������ɫ�ࣺ��ɫ
class Red : public Color {
public:
    void fill() override {
        std::cout << "Inside Red: fill() method" << std::endl;
    }
};

// ������ɫ�ࣺ��ɫ
class Blue : public Color {
public:
    void fill() override {
        std::cout << "Inside Blue: fill() method" << std::endl;
    }
};
/////////////////////////////////////////////////////////////////////////
// ���󹤳���
class AbstractFactory {
public:
    virtual Shape* create_shape() = 0;
    virtual Color* create_color() = 0;
};

// ������״������
class ShapeFactory : public AbstractFactory {
public:
    Shape* create_shape() override {
        return new Rectangle();
    }

    Color* create_color() override {
        return nullptr; // �����𴴽���ɫ����
    }
};

// ������ɫ������
class ColorFactory : public AbstractFactory {
public:
    Shape* create_shape() override {
        return nullptr; // �����𴴽���״����
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
���󹤳�ģʽ��һ�ִ��������ģʽ�����ṩ��һ�ִ���һϵ����ػ���������Ľӿڣ�������ָ�������ࡣ�ڳ��󹤳�ģʽ�У��ͻ���ͨ�����ù����ӿ�������һ����صĲ�Ʒ���󣬶�����Ҫ���ľ���Ĳ�Ʒ�ࡣ���ַ�ʽ����ʹϵͳ��������ԣ��ܹ������л�������Ʒ�������Ӱ��ͻ��˴��롣

���󹤳�ģʽͨ���漰���½�ɫ��

1. **���󹤳���Abstract Factory����** �����˴�����Ʒ����Ľӿڣ�����һ�鴴����ͬ���Ͳ�Ʒ�ķ�����

   

2. **���幤����Concrete Factory����** ʵ���˳��󹤳��ӿڣ��ھ��幤����ʵ���˴���һ����ز�Ʒ�ķ�����

   

3. **�����Ʒ��Abstract Product����** �����˲�Ʒ����Ľӿڣ������Ʒ�ཫʵ����Щ�ӿڡ�

   

4. **�����Ʒ��Concrete Product����** ʵ���˳����Ʒ�ӿڵľ����Ʒ�ࡣ

���󹤳�ģʽ��Ҫ����������⣺

1. **��װ�仯��** ���󹤳�ģʽ������Ĵ������̷�װ�ڹ����ӿ��У��ͻ��˲���Ҫ�˽����Ĳ�Ʒ�࣬�Ӷ�ʹ�ͻ��˴���������Ʒ�������������滻������Ʒ���塣

   

2. **��Ʒ���һ���ԣ�** ���󹤳�ģʽȷ�������Ĳ�Ʒ������ͬһ��Ʒ��ģ����ֲ�Ʒ֮���һ���ԣ������ڴ�������Ԫ��ʱ�����ְ�ť���ı����Ԫ�صķ��ͳһ��

   

3. **������չ��** ����Ҫ����µĲ�Ʒ��ʱ��ֻ��Ҫ�����µľ��幤����;����Ʒ�࣬������Ҫ�޸����д��룬���Ͽ���ԭ��

�ܵ���˵�����󹤳�ģʽ�ṩ��һ�ִ���һ����ض���Ľӿڣ�������������Ҫ���������ض���ʱ���ִ��������ԺͿ���չ�ԡ�
#endif