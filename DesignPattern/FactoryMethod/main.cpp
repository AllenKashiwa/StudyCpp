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
    Button* btn = factory1->createButton();
    btn->display();
    factory1 = new MacButtonFactory();
    btn = factory1->createButton();
    btn->display();
    delete factory1;

    // 简单工厂模式
    ButtonFactory2* factory2 = new ButtonFactory2();
    btn = factory2->createButton(WINDOWS);
    btn->display();
    btn = factory2->createButton(MAC);
    btn->display();

    delete btn;
    return 0;
}