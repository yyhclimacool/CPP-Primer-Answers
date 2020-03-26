//#include "exercise_15_05.h"
//
//class Disc_quote : public Bulk_quote {
//public:
//    Disc_quote() = default;
//    Disc_quote(const string &book, double p, size_t qty, double disc)
//        : Bulk_quote(book, p, qty, disc) {}
//    virtual double net_price(size_t n) const override {
//        if (n <= min_qty)
//            return price * n * (1 - discount);
//        else 
//            return price * n;
//    }
//    virtual void debug() const override {
//        Bulk_quote::debug();
//        cout << "Disc_quote has no members" << endl;
//    }
//    ~Disc_quote() = default;
//};
//
