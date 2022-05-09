#include "fib.h"//引入Fib数列类
template <typename T>   // 在有序向量区间[lo, hi)查找元素e
static Rank fibSearch(T * S, T const & e, Rank lo, Rank hi)
{
    Fib fib(hi - lo);
    while (lo < hi)
    {
        while (hi - lo < fib.get()) fib.prev();
        Rank mi = lo + fib.get() - 1;   // 确定形如Fib(k) - 1的轴点
        (e < S[mi]) ? hi = mi : lo = mi + 1;//比较后确定深入前半段[lo,mi)或后半段(mi,hi)
    } // 成功查找不能提前终止
    return --lo;  //循环结束时，lo为大于e的元素的最小秩，故lo-1即不大于e的元素的最大秩
}   // 命中多个元素时，不能保证返回最大者；失败时，能够返回失败的位置
