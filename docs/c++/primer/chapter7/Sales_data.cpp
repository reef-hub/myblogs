#include"Sales_data.h"
#include<iostream>
Sales_data::Sales_data(std::istream& is) {
    read(is, *this);
}
 double Sales_data::avg_price() const {
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
 }

 Sales_data& Sales_data::combine(const Sales_data& rhs) {
     units_sold += rhs.units_sold;
     revenue += rhs.revenue;
     return *this;
 }
 // 输入的交易信息包括ISBN、售出总数和售出价格
 //第一点， read和print 分别接受一个各自IO类型的引用作为其参数，
 //这是因为I O 类不能被拷贝， 因此我们只能通过引用来传递它们。
 //而且，因为读取和写入的操作会改变流的内容，所以两个函数接受的都是普通引用，而非对常址的引用。
std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << item.isbn() <<" "<< item.units_sold << " "
       << item.revenue <<" "<< item.avg_price();
       return os;    
}
std::istream& read(std::istream& is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
