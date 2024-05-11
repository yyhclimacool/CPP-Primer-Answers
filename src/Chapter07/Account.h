#include <string>

class Account {
public:
    Account(std::string name, double am) : owner_(name), amount_(am) {}
    ~Account() = default;
    std::string getname() const { return owner_; }
    double calculate() { amount_ += amount_ * interestRate_; return amount_; }
    static double rate() { return interestRate_; }
    static void rate(double);
private:
    std::string owner_;
    double amount_;
    static double interestRate_;
    static double initRate();
};
