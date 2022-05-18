template <typename T>
void Vector<T>::expand(){// 向量空间不足时扩容
    if(_size < _capacity)// 尚未满员时，不必扩容
        return;
    _capacity = _capacity < DEFAULT_CAPACITY ? DEFAULT_CAPACITY : _capacity;//不低于最小容量
    T * oldElem = _elem;    // 将原有的数据记录
    _elem = new T[_capacity <<= 1]; // 容量加倍
    for (int i = 0; i < _size; i++) // 复制原向量内容
        _elem[i] = oldElem[i];      // T为基本类型或已重载运算符"="
    delete []oldElem;   // 释放原空间
}   // 得益于向量的封装，扩容之后数据区的物理地址有所改变，却不致出现野指针