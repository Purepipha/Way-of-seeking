template <typename T>//将e作为秩为r元素插入
Rank Vector<T>::insert(Rank r, T const & e){//assert:0 <= r <= size
    expand();   // 若有必要，扩容
    for (int i = _size; i > r; i--)// O(n-r):自后向前
        _elem[i] = _elem[i - 1];// 后继元素顺次后移一个单元
    _elem[r] = e;   // 置入新元素
    _size++;        // 更新向量规模
    return r;       // 返回秩
}
