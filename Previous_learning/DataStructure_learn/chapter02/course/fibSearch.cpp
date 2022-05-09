// fibSearch.cpp -- 斐波那契查找
// versionA
#include "Vector/Vector.h"
template <typename T>   // 在有序向量区间[lo, hi)查找元素e
static Rank fibSearch(T * S, T const & e, Rank lo, Rank hi)
{
    Fib fib(hi - lo);
    while (lo < hi)
    {
        while (hi - lo < fib.get()) fib.prev();
        Rank mi = lo + fib.get() - 1;   // 确定形如Fib(k) - 1的轴点
        if (e < S[mi]) hi = mi;     // 深入前半段[lo,mi)
        else if (S[mi] < e) lo = mi + 1;    // 深入后半段(mi,hi)
        else return mi;
    } // 成功查找可以提前终止
    return -1;  // 查找失败
}   // 命中多个元素时，不能保证返回最大者；失败时，简单的返回-1而不能指示失败的位置