// fib.h -- definition of class Fib
// 习题1-22
#pragma once
/****************** Fib 接口定义
class Fib
{
public:
    Fib(int n) // 初始化为不小于n的最小Fibonacci项(如，Fib(6) = 8),O(log\phi(n))
    int get()  // 获取当前Fibonacci项(如，若当前为8,则返回8)，O(1)时间
    int next() // 转至下一Fibonacci项(如，若当前为8,则返回13)，O(1)时间
    int prev() // 转至上一Fibonacci项(如，若当前为8,则返回5)，O(1)时间
};
**************************/
class Fib
{
private:
    int f, g; // f = fib(k -1), g = fib(k)。均为int型，很快会数值溢出
public:
    Fib(int n) // 初始化为不小于n的最小Fibonacci项
    { f = 1; g = 0; while(g < n) next(); } // fib(-1),fib(0),O(log_phi(n)) 时间
    int get() { return g; }  // 获取当前Fibonacci项，O(1)时间
    int next() { g += f; f = g -f; return g; } // 转至下一Fibonacci项，O(1)时间
    int prev() { f = g - f; g -= f; return g; } // 转至上一Fibonacci项，O(1)时间
};