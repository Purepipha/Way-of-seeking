#include "fib.h"//引入Fib数列类
//Fibonacci查找算法(版本A):在有序向量的区间[lo,hi)内查找元素e,0<=lo<=hi<=_size
template <typename T>
static Rank fibSearch(T * S, T const & e, Rank lo, Rank hi){
//用O(log_phi(n = hi - lo))时间创建Fib数列
    for(Fib fib(hi - lo);lo < hi;){//Fib数列制表备查；此后每步迭代仅一次比较、两个分支
    while (hi - lo < fib.get()) fib.prev();//自后向前顺序查找(分摊O(1))
    Rank mi = lo + fib.get() - 1;//确定形如Fib(k)-1的轴点
    if (e < S[mi]) hi = mi;     //深入前半段[lo,mi)继续查找
    else if (S[mi] < e) lo = mi + 1;    //深入后半段(mi,hi)继续查找
    else return mi;//在mi处命中
    } //成功查找可以提前终止
    return -1;  // 查找失败
}   //命中多个元素时，不能保证返回最大者；失败时，简单的返回-1而不能指示失败的位置