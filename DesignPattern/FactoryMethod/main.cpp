#include <iostream>

// 1.工厂方法模式
class Button {
public:
    virtual void display() = 0;
};

class WinButton :public Button {
public:
    void display()
    {
        std::cout << "WinButton display" << std::endl;
    }
};

class MacButton :public Button {
public:
    void display()
    {
        std::cout << "MacButton display" << std::endl;
    }
};

class ButtonFactory1 {
public:
    virtual Button* createButton() = 0;
};

class WinButtonFactory :public ButtonFactory1 {
public:
    Button* createButton() {
        return new WinButton();
    }
};

class MacButtonFactory :public ButtonFactory1 {
public:
    Button* createButton() {
        return new MacButton();
    }
};

// 简单工厂模式
enum BUTTON_TYPE { WINDOWS, MAC };
class ButtonFactory2 {
public:
    Button* createButton(enum BUTTON_TYPE btnType) {
        if (btnType == WINDOWS)
            return new WinButton();
        else if (btnType == MAC)
            return new MacButton();
        else
            return NULL;
    }
};

int main()
{
    // 工厂方法模式
    ButtonFactory1* factory1 = new WinButtonFactory();
    Button* btn1 = factory1->createButton();
    btn1->display();
    factory1 = new MacButtonFactory();
    btn1 = factory1->createButton();
    btn1->display();

    delete btn1;
    delete factory1;

    // 简单工厂模式
    ButtonFactory2* factory2 = new ButtonFactory2();
    Button* btn2 = factory2->createButton(WINDOWS);
    btn2->display();
    btn2 = factory2->createButton(MAC);
    btn2->display();

    delete btn2;
    delete factory2;

    return 0;
}