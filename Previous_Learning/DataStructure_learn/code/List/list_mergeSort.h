template <typename T>//列表的归并排序算法：对起始于位置p的n个元素排序
void List<T>::mergeSort(Posi(T) & p, int n){//valid(p) && ranl(p) + n <= _size
    if (n < 2) return;//若待排序范围已足够小，则直接关于；否则...
    int m = n >> 1;//以中点为界
    Posi(T) q = p;
    for (int i = 0; i < m; i++)
        q = q->succ;//据分列表
    mergeSort(p, m); mergeSort(q, n - m);//对前、后子列表分别排序
    merge(p, m, *this, q, n - m);//归并
}//注意，排序后，p仍指向归并区间后的(新)起点