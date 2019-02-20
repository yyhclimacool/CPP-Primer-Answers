#include <iostream>                                                                                                     
#include <string>

// 和其他成员一样，静态成员可以是public的或private的。
class Account {
    public:
        Account(const std::string &name, double a) : owner(name), amount(a) {}
        // 成员函数不用通过作用于运算符就能直接使用静态成员
        void calculate() { amount += amount * interestRate; }
        // 静态成员函数不包含this指针，因此，静态成员函数不能声明为const
        // 也不能显示或隐式使用this指针
        static double rate() { return interestRate; }
        static void rate(double);
    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate() { interestRate = 0.1; };
};

// 静态成员函数既能定义在类内部，也能定义在类外部
// 在外部定义时不需要重复static关键字
void Account::rate(double newRate) {
    interestRate = newRate;
}

// 类似于全局变量，静态数据成员定义在任何函数之外
// 定以后，将一直存在于程序的整个生命周期中
// initRate在作用域运算符之后，因此这里能够访问
double Account::interestRate = initRate(); 

int main () {
    Account a1("kevin", 100);
    std::cout << a1.rate() << std::endl;
    // 虽然静态成员不与任何对象关联，但任然可以通过对象或指向对象的指针访问
    a1.rate(0.2);
    std::cout << a1.rate() << std::endl;
    // 也可以使用作用域运算符直接访问
    Account::rate(0.3);
    std::cout << a1.rate() << std::endl;
}
