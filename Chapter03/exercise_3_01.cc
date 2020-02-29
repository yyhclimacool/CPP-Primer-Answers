#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold;
    double revenue;
};

istream &read(istream &is, Sales_data &sd) {
    double price = 0;
    is >> sd.bookNo >> sd.units_sold >> price;
    sd.revenue = sd.units_sold * price;
    return is;
}

ostream &print(ostream &os, const Sales_data &sd) {
    os << sd.bookNo << " " << sd.units_sold << " " << sd.revenue << endl;
    return os;
}

int main() {
    int start = 50, sum = 0;
    while (start++ <= 100) sum += start;
    cout << "sum(50->100) = " << sum << endl;

    start = 10;
    while (start >= 0) cout << (start--) << "\t";
    cout << endl;

    int val1 = 0, val2 = val1;
    cout << "Enter two numbers:\t";
    cout << endl;
    cin >> val1 >> val2;
    while (val1 <= val2) {
        cout << val1++ << " ";
    }
    cout << endl;

    /////////////////////////////////////////
    // 读取记录并打印
    Sales_data data;
    while (read(cin, data)) {
        print(cout, data);
    }

    // 输出两个相同isbn的和
    Sales_data data1, data2;
    read(cin, data1);
    read(cin, data2);
    Sales_data sumd;
    if (data1.bookNo != data2.bookNo) {
        cerr << "ISBN not equal: " << data1.bookNo << "-" << data2.bookNo << endl;
        return -1;
    }
    sumd.bookNo = data1.bookNo;
    sumd.units_sold = data1.units_sold + data2.units_sold;
    sumd.revenue = data1.revenue + data2.revenue;
    print(cout, sumd);

    // 输出多个和，确保isbn相同
    Sales_data total, val;
    while (read(cin, val)) {
        total.bookNo = val.bookNo;
        total.units_sold += val.units_sold;
        total.revenue += val.revenue;
    }
    print(cout, total);
}
