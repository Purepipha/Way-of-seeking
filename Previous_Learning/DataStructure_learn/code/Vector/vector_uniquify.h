template <typename T>
int Vector<T>::uniquify()
{
    // int oldSize = _size;
    Rank i = 0, j = 0;
    while (++j < _size) // 找到第一个不相等的值，赋给++i
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    _size = ++i;    // 更新向量规模
    shrink();       // 如果必要，缩小容量
    return j - i;   // 返回删除元素个数
        // for(j; j <_size; j++)
        //     if (_elem[i] != _elem[j])
        //         _elem[++i] = _elem[j];
}