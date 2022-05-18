template <typename T>//列表插入排序算法：对起始位置p的n个元素排序
void List<T>::insertionSort(Posi(T) p, int n){//valid(p) && rank(p) + n <= _size
    for (int r = 0; r < n; r++){//逐一为各节点
        insertA(search(p->data, r, p), p->data);//查找合适位置并插入
        p = p->succ; remove(p->pred);//转向下一节点，删除原来节点
    }
}//复杂度:O(n^2)

// my insertionSort()
// Rank r = 0;
// Posi(T) q;
// while (n--){
//     q = search(p->data,r, p);//查找插入位置
//     insertA(q, p->data);//插入
//     p = p->succ;//节点后移
//     remove(p->pred);
//     r++;
// }