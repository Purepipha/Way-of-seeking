template <typename T>
int Vector<T>::deduplicate(){//删除无序向量中重复元素(高效版)
    int oldSize = _size;//记录原规模
    for (Rank i = 1; i <_size; i++)//逐一考察_elem[i]
        Rank j = find(_elem[i], 0, i);//在_elem[i]的前去中寻找与之雷同者(至多一个)
        if(0<=j)remove(j);//若存在，则删除之
    return oldSize - _size;//被删除元素总数
}

