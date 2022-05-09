template <typename T>//无序列表内节点p(可能是trailer)的n个真前驱寻找e
Posi(T) List<T>::find(T const & e, int n, Posi(T) p) const{
    while (0 < n--){//(0 <= n <= rank(p) < _size)
        if ((p = p->pred)->data == e)//逐个比对，直至命中或越界
            return p;
    }
    return nullptr;//p越出左边界意味着区间内不含e，查找失败
}//失败时，返回NULL 复杂度：O(n)