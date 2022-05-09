template<typename T>//在有序列表内节点p(可能是trailer)的n个真前驱中，找到不大于e的最大者
Posi(T) List<T>::search(T const& e, int n, Posi(T) p) const {
// assert: 0 <= n <= rank(p) < _size
    while (n--){//对于p的最近的n个前驱，从后向前逐个比较
        if ((p = p->pred)->data <= e) break;//直至命中、数值越界或范围越界
    }
// assert: 至此位置p必符合语义约定——尽管此前最后一次关键吗比较可能没有意义(等效于与-inf比较)
    return p;//返回查找终止的位置
}//失败时，返回区间左边界的前驱(可能是header)——调用者可通过valid()判断成功与否