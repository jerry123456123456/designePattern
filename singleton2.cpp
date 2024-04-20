#include <memory>
#include <iostream>
using namespace std;

class Singleton {
public:
    static shared_ptr<Singleton> GetInstance() {
        if (!_instance) {
            _instance = shared_ptr<Singleton>(new Singleton());
        }
        return _instance;
    }

    // 将析构函数改为公有
    ~Singleton() {};

private:
    Singleton() {};

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    // 声明 shared_ptr 为友元,这样智能指针就能够访问类中的私有成员
    friend shared_ptr<Singleton>;

    static shared_ptr<Singleton> _instance;
};

shared_ptr<Singleton> Singleton::_instance = NULL;

int main() {
    shared_ptr<Singleton> instance = Singleton::GetInstance();

    // 在程序结束时会自动调用析构函数释放资源
    return 0;
}

//该智能指针的作用是确保singleton类的实例在不需要的时候能够正确释放内存，避免内存泄漏。
//同时，share_ptr智能指针还可以方便的管理类的生命周期，因为当所有指向该实例的智能指针都超出作用域的时候，实例会被自动销毁
//如果只有一个智能指针独享这个实例，那就用unique_ptr

//代码中没有使用 `std::make_shared`，而是直接使用 `new` 关键字来创建 `Singleton` 对象并将其包装在 `std::shared_ptr` 中。虽然 `std::make_shared` 在很多情况下是推荐的方式，但直接使用 `new` 也是有效的。在某些情况下，直接使用 `new` 可能更适合，例如需要传递额外的参数给构造函数时。

//在你的代码中，`Singleton::GetInstance()` 方法负责返回 `Singleton` 类的实例，并在需要时创建该实例。在 `main()` 函数中，你获取了 `Singleton` 的实例并存储在 `shared_ptr` 中，当程序结束时，`shared_ptr` 会调用析构函数来释放资源。
//总的来说，尽管没有使用 `std::make_shared`，你的代码仍然是有效的并且实现了单例模式。使用 `std::make_shared` 主要是为了避免直接使用 `new` 和 `delete`，从而提高代码的安全性和可读性。

//如果不使用智能指针，见singleton3.cpp