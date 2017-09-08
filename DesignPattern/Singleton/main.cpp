// 单例模式（Singleton Pattern）确保一个类只有一个实例，并提供对该实例的全局访问。
#include <iostream>

// 1. 试用于单线程的懒汉写法
class Singleton1
{
public:
    static Singleton1* getInstance() {
        if (0 == m_pInstance)
            m_pInstance = new Singleton1();
        return m_pInstance;
    }
    void doSomething() {
        std::cout << "Singleton1 doSomething" << std::endl;
    }
private:
    Singleton1() {}
    ~Singleton1() {}
    static Singleton1* m_pInstance;
};

Singleton1* Singleton1::m_pInstance = 0;

// 2. 试用于多线程的写法
class Singleton2
{
public:
    static Singleton2* getInstance() {
        if (nullptr == m_pInstance)
        {
            // lock();      //需要具体实现
            if (0 == m_pInstance)
                m_pInstance = new Singleton2();
            // unlock();    //需要具体实现
        }
        return m_pInstance;
    }
    void doSomething() {
        std::cout << "Singleton2 doSomething" << std::endl;
    }
private:
    Singleton2() {}
    ~Singleton2() {}
    static Singleton2* m_pInstance;
};

Singleton2* Singleton2::m_pInstance = 0;

// 3. 利用静态变量的写法，线程安全且简单
class Singleton3 {
private:
    Singleton3() {}
    ~Singleton3() {}
    // C++ 03
    // ========
    // 声明拷贝构造函数和赋值函数，但不予实现避免多个实例
    // Singleton3(const Singleton&);                // 不予实现
    // void operator=(Singleton3 const&);           // 不予实现
public:
    // C++ 11 可以直接使用delete关键字
    Singleton3(const Singleton3& other) = delete;
    void operator=(const Singleton3&) = delete;
    static Singleton3& getInstance() {
        static Singleton3 instance;
        return instance;
    }
    void doSomething() {
        std::cout << "Singleton3 doSomething" << std::endl;
    }
};

int main()
{
    Singleton1::getInstance()->doSomething();
    Singleton2::getInstance()->doSomething();
    Singleton3::getInstance().doSomething();
    return 0;
}