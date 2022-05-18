template <typename T> void List<T>::init(){//列表初始化，创建列表对象时统一调用
    header = new ListNode<T>;//创建头哨兵节点
    trailer = new ListNode<T>;//创建尾哨兵节点
    header->succ = trailer; header->pred = nullptr;
    trailer->pred = header; trailer->succ = nullptr;
    _size = 0;//记录规模
}