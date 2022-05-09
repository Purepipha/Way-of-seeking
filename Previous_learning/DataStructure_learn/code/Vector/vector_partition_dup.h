template <typename T>//轴点构造算法：通过调整元素位置构造区间[lo,hi)的轴点，并返回秩//FIXME
Rank Vector<T>::partition(Rank lo, Rank hi){//DUP版：可优化处理多个关键码雷同的退化情况
swap(_elem[lo],_elem[lo + rand()%(hi - lo)]);//任选一个元素与首元素交换
hi--; T pivot = _elem[lo];//以首元素为候选轴点——经以上交换，等效于随机选取
while(lo < hi){//从向量的两端交替地向中间扫描
    while(lo < hi)
        if(pivot < _elem[hi])//在大于pivot的前提下
            hi--；//向左拓展右端子向量
        else
            {_elem[lo++] = _elem[hi];break;}//将其归入左端子向量
    while(lo < hi)
        if(_elem[lo] < pivot)//在小于pivot的前提下
            lo++;//向右拓展左端子向量
        else
            {_elem[hi--]=_elem[lo];break;}//将其归入右端子向量
    }//assert:lo == hi
    _elem[lo] = pivot;//将备份的轴点记录于前、后子向量之间
    return lo;
}