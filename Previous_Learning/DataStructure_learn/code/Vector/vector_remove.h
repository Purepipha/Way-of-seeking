template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];     // 备份
    remove(r, r + 1);   // "区间删除"，将单元素视作区间特例
    return e;       // 返回被删除元素
}   //O(n-r), 0 <= r < _size