// 二分查找算法(版本C)：在有序向量的区间[lo,hi)内查找元素e，0<=lo<=hi<=_size
template <typename T>
static Rank binSearch(T * A, T const & e, Rank lo, Rank hi)
{
    while (lo < hi)
    { //每步迭代仅需一次判断，有两个分支
        Rank mi = (lo + hi) >> 1;   //以中点为轴点
        (e < A[mi]) ? hi = mi : lo = mi + 1;    //经比较后确定深入[lo,mi)或(mi,hi)
    } //成功查找不能提前终止
    return --lo; //循环结束时，lo为大于e元素的最小秩，故lo-1即不大于e的元素的最大秩
} //有多个命中元素时，总能返回秩最大者；查找失败时，返回失败的位置