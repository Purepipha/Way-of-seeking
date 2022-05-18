// 二分查找算法(版本B)：在有序向量的区间[lo,hi)内查找元素e，0<=lo<=hi<=_size
#include "Vector/Vector.h"
template <typename T>
static Rank binSearch(T * A, T const & e, Rank lo, Rank hi)
{
    while(1 < (hi - lo))
    { //每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
        Rank mi = (hi + lo) >> 1;   // 以中点点为轴点
        (e < A[mi]) ? hi = mi : lo = mi;   // 经比较后确定深入[lo,mi)或者[mi,hi)
    }// 出口时，hi = lo + 1；，查找区间仅含一个元素lo
    return (e == A[lo]) ? lo : -1;
}
