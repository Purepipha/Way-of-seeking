template <typename T>//从起始于位置p的n个元素选出最大者
Posi(T) List<T>::selectMax(Posi(T) p, int n) const {
    Posi(T) max = p;//最大节点暂定为p
    for (Posi(T) cur = p; n > 1; n--)//从首节点p出发，将后续节点逐一与max比较
        if ((cur = cur->succ)->data >= max->data)//若当前元素不小于max，则
            max = cur;//更新最大元素位置
    return max;//返回最大节点位置
}//复杂度:O(n^2)
// my write selectMax
// while (n--){
//     if (p->data >= max->data)
//         max = p;
//     p = p->succ;
// }