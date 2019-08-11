#pragma once

#include "exercise_15_03.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc) 
        : Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(size_t cnt) const override {
        if (cnt >= min_qty) {
            return cnt * (1 - discount) * price;
        } else {
            return cnt * price;
        }
    }
    virtual void debug() const override {
        Quote::debug();
        cout << "Bulk_quote: min_qty = " << min_qty << ", discount = " << discount << endl;
    }

    virtual Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    virtual Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

