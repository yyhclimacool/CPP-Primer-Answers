#include <iostream>
#include <vector>
#include <memory>
#include <set>

//#include "exercise_15_05.h"

//using namespace std;
//
//class Basket {
//public:
//    void add_item(shared_ptr<Quote> &q) {
//        items.insert(q);
//    }
//
//    double total_receipt(std::ostream &os) const {
//        double sum = 0.0;
//        for (auto iter = items.cbegin();
//                iter != items.cend();
//                iter = items.upper_bound(*iter)) {
//            sum += print_total(os, **iter, items.count(*iter));
//        }
//        os << "Total Sale: " << sum << endl;
//        return sum;
//    }
//
//    void add_item(const Quote &q) {
//        items.insert(shared_ptr<Quote>(q.clone()));
//    }
//
//    void add_item(Quote &&q) {
//        items.insert(shared_ptr<Quote>(std::move(q).clone()));
//    }
//private:
//    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
//        return lhs->isbn() < rhs->isbn();
//    }
//    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
//};

int main() {
}
