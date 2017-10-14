#ifndef _BULK_QUOTE_HPP_
#define _BULK_QUOTE_HPP_

#include "15_3_Quote.hpp"

#include <string>

class Bulk_quote : public Quote{
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
            Quote(book, p), quantity(qty), discount(disc){}
        double net_price(std::size_t n) const override;
    private:
        std::size_t quantity = 0;
        double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const {

}

#endif
