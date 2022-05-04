#include<string>
struct Sales_data {
    //构造函数
    Sales_data() = default;
    Sales_data(const std::string& s) : bookNo(s) {}
    Sales_data(const std::string& s, unsigned n, double p) : 
               bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream& is);
    // 成员函数
    //问题：
    //例如在Sales_data成员函数中，this的类型是Sales_data * const 。
    //尽管this是隐式的，但它仍然面要遵循初始化规则， 意味着（在默认情况下）我们不能把this绑定到一个常量对象上
    //所以普通成员函数（不加const）不能接收常量类对象的调用
    //解决办法：
    //紧跟在参数列表后面的const表示this是一个指向常量的指针。
    //像这样使用const的成员函数被称作常量成员函数( const member function ) 。
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // 成员变量
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
// 值得注意的是，即使bookNo 定义在isbn 之后， isbn 也还是能够使用bookNo 。
// 编译器分两步处理类： 首先编译成员
// 的声明，然后才轮到成员函数体（ 如果有的话）。因此， 成员函数体可以随意使用类中的
// 其他成员而无须在意这些成员出现的次序。
};
// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);