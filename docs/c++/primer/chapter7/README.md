# 定义抽象数据类型

1、设计Sales_data类
添加成员函数isbn，并支持+、=、+=、<<和>>运算符。
综上所述，Sales_data的接口应该包含以下操作：
- 一个isbn成员函数，用于返回对象的ISBN编号
- 个combine成员函数，用于将一个Sales_data对象加到另一个对象上
- 一个名为add的函数，执行两个Sales_data对象的加法
- 一个read函数，将数据从istream读入到Sales_data对象中
- 一个print函数，将Sales_data对象的值输出到ostream