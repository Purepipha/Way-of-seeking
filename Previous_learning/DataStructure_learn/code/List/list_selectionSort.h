template <typename T>//列表的选择排序算法，对起始于位置p的n个元素进行排序
void List<T>::selectionSort(Posi(T) p, int n){//valid(p) && rank(p) + n <= _size
    Posi(T) head = p->pred; Posi(T) tail = p;
    for (int r = 0; r < n; r++)//找到排序区间的尾节点
        tail = tail->succ;//待排序区间为(head,tail)
    while (n > 1){//在至少剩两个节点一牵，在待排序区间内
        Posi(T) max = selectMax(head->succ, n);//找到最大元素的位置，歧义时后者优先
        swap(max->data, tail->data);//交换两者元素，效率高
        // insertB(tail, remove(max));//将其移至末尾(作为有序区间新的首元素)
        tail = tail->pred; n--;
    }
}
// 移动方法效率低，通常为其他基本操作时间的两个数量级及以上
// 改进措施是交换tail与max指向的数据

// my write selectionSort()
// while(n > 1){//至少剩下两个节点以前,在待排序区间内
//     Posi(T) max = selectMax(p, n);//找到最大元素的位置
//     tail->insertAsPred(max->data);//插入最大元素
//     tail = tail->pred;
//     remove(max);
//     n--;
// }