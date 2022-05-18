template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{// 0 <=lo<=hi<=n
    if (hi == lo)   // 出于效率，单独处理退化情况
        return 0;
    while (hi < _size)  // O(n - hi):[hi,n)顺次前移
        _elem[lo++] = _elem[hi++];
    _size = lo; // 更新规模
    shrink();
    return hi - lo;
    // for (int i = lo; i < lo + _size - hi; i++)
    //     _elem[i] = _elem[i + hi - lo];
    // _size = _size -hi + lo;
    // shrink();
    // return hi - lo;
}