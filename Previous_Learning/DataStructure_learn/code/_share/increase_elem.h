template <typename T> struct Increase//函数对象：递增类一个T对象
{
    virtual void operator()(T & e) { e++; }// 假设T可直接递增或重载
};