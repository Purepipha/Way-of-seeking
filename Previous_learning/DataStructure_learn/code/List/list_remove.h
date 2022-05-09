template <typename T>
T List<T>::remove(Posi(T) p){//删除合法节点p，返回其数值。
    T e = p->data;//备份待删除节点的数值
    p->pred->succ = p->succ;//修改前驱的后继
    p->succ->pred = p->pred;//修改后继的前驱
    delete p; _size--;//释放节点，更新规模
    return e;//返回备份节点的值
}