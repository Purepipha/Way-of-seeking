template <typename T>
void List<T>::reverse(){//前后倒置
    if (_size < 2) return;
    Posi(T) p; Posi(T) q;
    for (p = header, q = p->succ; p != trailer; p = q, q = p->succ){
        p->pred = q;//自前向后，依次颠倒节点的前驱指针
    }
    trailer->pred = nullptr;//单独设置尾节点的前驱指针
    for (p = header, q = p->pred; p != trailer; p = q, q = p->pred){
        q->succ = p;//自前向后，依次颠倒节点的后继指针
    }
    header->succ = nullptr;//单独设置头结点的后继指针
    swap(header, trailer);//头尾节点交换
}