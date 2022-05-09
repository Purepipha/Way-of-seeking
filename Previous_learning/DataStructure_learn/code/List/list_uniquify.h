template <typename T>
int List<T>::uniquify(){//有序列表去重
    int oldSize = _size;//记录列表原有长度
    Posi(T) p = first();//p为各区段起点
    Posi(T) q;//q为p后继
    while (trailer != (q = p->succ)){
        if (p->data != q->data) p = q;//若不相等，则转向下一区段
        else remove(q);//若雷同，删除后者
    }
    return oldSize - _size;//返回删除元素个数
}//复杂度O(n)
// wrong code
// while (trailer != (p=p->succ)){
//         if(p->data == p->succ->data) remove(p);
//     }