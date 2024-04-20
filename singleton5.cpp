#include<iostream>
#include<mutex>
#include<atomic>
using namespace std;

//load可以看见其他线程最新操作的数据，store修改数据让其他线程可见
//memory_order_acquire和memory_order_release之间所夹的代码既不会被优化到上面，也不会被优化到下面
//
class singleton{
public:
    static singleton* GetInstance(){
        singleton *tmp=_instance.load(memory_order_relaxed);  //这个_instance定义是原子变量,就代表这条语句不可拆分,load是可见，获取最新数据，而relaxed指松散型可以随便优化
        atomic_thread_fence(memory_order_acquire);   //内存栅栏解决了可见性问题和执行序问题,在这里使用，如果在构造函数里还使用了原子变量，就可以使用relaxed，因为这个是最快的
        //内存栅栏防止后面的代码编译到前面的代码的前面，保证了之前的读操作对后面的读操作可见
        if(tmp==NULL){
            lock_guard<mutex> lock(_mutex);  //即使是原子操作，也无法完全替代互斥锁的作用。原子操作可以确保数据的一致性和可见性，但并不能解决并发访问带来的竞态条件。
            tmp=_instance.load(memory_order_relaxed);
            if(tmp==NULL){
                tmp=new singleton;
            }

            atomic_thread_fence(memory_order_release);
            _instance.store(tmp,memory_order_relaxed);
            atexit(Destructor);
        }
        return tmp;
    }
private:
    static void Destructor(){
        singleton* tmp=_instance.load(memory_order_relaxed);
        if(tmp!=NULL){
            delete tmp;       
        }
    }
    singleton(){};
    ~singleton(){};
    //单例模式，就是一个类中只允许初始化一个实例，那就要禁用其他
    singleton(const singleton&)=delete;
    singleton& operator=(const singleton&)=delete;
    singleton(singleton&&)=delete;
    singleton& operator=(singleton&&)=delete;
    static atomic<singleton*> _instance;
    static mutex _mutex;
};

atomic<singleton*> singleton::_instance;
mutex singleton::_mutex;

int main(){
    return 0;
}

//这个代码虽然霸气，但是有些复杂