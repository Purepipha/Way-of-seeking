template <typename T>
int List<T>::clear(){//清空列表
    int oldSize = _size;//记录原来的长度
    while (_size > 0) { remove(header->succ); }//反复删除首节点，直至列表为空
    return oldSize;//返回删除元素个数
}