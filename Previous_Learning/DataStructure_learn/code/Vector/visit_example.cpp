// visit_example.cpp -- 实现加一，减一，加倍，求和操作
// 加一
#include "Vector.h"
#include "vector_implementation.h"
template <typename T>   // 假设T可直接递增或已重载"++"
struct Increase     // 函数对象：通过重载()实现
{
    virtual void operator()(T & e) {e++;}
};
template <typename T>   // 由于Increase是一个函数对象，在使用它时需要创建该对象
void increase(Vector<T> & V)
{
    Increase<T> fIncrease;
    V.traverse(fIncrease);
}
// 减一
template <typename T>   // 假定T可直接递减或重载"--"
void Decrease(T & e)    // 模板函数指针
{
    e--;
}
template <typename T>
void decrease(Vector<T> & V)
{
    V.traverse(Decrease);
}
// 加倍
template <typename T>
class Redouble
{
private:
    int _n;  // 倍数
public:
    Redouble(int n = 2) : _n(n) {}
    virtual void operator()(T & e) { e *= _n; }
};
template <typename T>
void redouble(Vector<T> & V)
{
    Redouble<T> fRedouble;
    V.traverse(fRedouble);
}
// 求和
template <typename T>
class Sum
{
private:
    T _sum_value;
public:
    Sum(T sum_value = 0) : _sum_value(sum_value){ }
    virtual void operator()(T & e) { _sum_value += e; }
    T value() { return _sum_value; }
};

template <typename T>
T sum(Vector<T> & V)
{
    Sum<T> sum1;
    V.traverse(sum1);
    return sum1.value();
}
const int N = 5;
#include <iostream>
int main()
{
    using namespace std;
    Vector<int> nums(9);
    for (int i = 0; i < N; i++)
        nums.insert(i,i+1);
    int sums = sum(nums);
    cout << sums << endl;
    return 0;
}