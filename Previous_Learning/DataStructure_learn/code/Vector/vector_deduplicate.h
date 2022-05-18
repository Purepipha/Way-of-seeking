template <typename T>
int Vector<T>::deduplicate(){//删除无序向量中重复元素(高效版)
    int oldSize = _size;//记录原规模
    for (Rank i = 1; i <_size;)//自前向后逐个考察_elem[1,_size)
        if (find(_elem[i], 0, i) < 0)//在前缀[0,i)寻找与之雷同者
            i++;//若无雷同则继续考察其后继
        else
            remove(i);//否则删除当前元素
    return oldSize - _size;//被删除元素总数
}
