template <typename T>
void Vector<T>::shrink(){//装填因子过小时压缩向量所占空间
    if (_capacity < DEFAULT_CAPACITY << 1) return; //不致收缩到DEFAULT_CAPACITY以下
    if (_size << 2 > _capacity) return; // 以25%为界
    T * oldElem = _elem;
    _elem = new T[_capacity >>= 1]; // 容量减小一半
    for (int i = 0; i < _size; i++) // 复制原向量内容
        _elem[i] = oldElem[i];
    delete [] oldElem; // 释放原空间
}