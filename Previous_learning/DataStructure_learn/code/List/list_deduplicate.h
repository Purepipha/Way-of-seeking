template <typename T>
int List<T>::deduplicate(){//无序列表去重
    if (_size < 2) return 0;//平凡列表自然无重复
    int oldSize = _size;
    Posi(T) p = header;//p从首结点开始
    Rank r = 0;
    while (trailer != (p = p->succ)){//依次直到尾节点
        Posi(T) q = find(p->data, r, p);//在p的r个真前驱中查找p->data
        q ? remove(q) : r++;//若存在，则删除之，否则秩加1
    }
    return oldSize - _size;//返回去除元素的个数
}
// 自己写的
    // while (p != trailer){//依次到尾节点
    //     if (find((p = p->succ)->data, q, p) != nullptr) remove(p);//在p之前可以找到p，删除p
    //     else//找不到p++
    //         q++;
    // }