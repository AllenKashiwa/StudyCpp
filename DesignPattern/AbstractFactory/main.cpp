#include <iostream>
// 产品
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

class Border {
public:
    virtual void display() = 0;
};

class WinBorder :public Border {
public:
    void display()
    {
        std::cout << "WinBorder display" << std::endl;
    }
};

class MacBorder :public Border {
public:
    void display()
    {
        std::cout << "MacBorder display" << std::endl;
    }
};

// 工厂
class WindowFactory {
public:
    virtual Button* createButton() = 0;
    virtual Border* createBorder() = 0;
};

class WinWindowFactory : public WindowFactory {
public:
    WinButton* createButton() {
        return new WinButton();
    }

    WinBorder* createBorder() {
        return new WinBorder();
    }
};

class MacWindowFactory : public WindowFactory {
public:
    MacButton* createButton() {
        return new MacButton();
    }

    MacBorder* createBorder() {
        return new MacBorder();
    }
};

int main() {
    WindowFactory* windowFactory = new WinWindowFactory();
    Button* btn = windowFactory->createButton();
    Border* border = windowFactory->createBorder();
    btn->display();
    border->display();

    delete border;
    delete btn;
    delete windowFactory;

    windowFactory = new MacWindowFactory();
    btn = windowFactory->createButton();
    border = windowFactory->createBorder();
    btn->display();
    border->display();

    delete border;
    delete btn;
    delete windowFactory;

    return 0;
}