template <typename T> //T为基本类型，或已重载赋值运算符
void Vector<T>::copyFrom(T const * A, Rank lo, Rank hi){//以数组取件A[lo,hi)为蓝本复制向量
    _elem = new T[_capacity = DEFAULT_CAPACITY < 2*(hi - lo) ? 2*(hi - lo) : DEFAULT_CAPACITY];  // 分配空间
    for (_size = 0; lo < hi; _size++, lo++) // A[lo,hi)内的元素逐一
        _elem[_size] = A[lo];   //复制到_elem[0,hi - lo)中
}//用const修饰，保证A中的元素不致被篡改；运行时间=O(hi-lo)
