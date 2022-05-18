template <typename T>//有序列表的归并：当前列表中自p起的n个元素，与列表L中自q起的m个元素
void List<T>::merge(Posi(T) & p, int n, List<T> & L, Posi(T) & q, int m){
// assert: this.valid(p) && rank(p) + n <= _size && this.sorted(p,n)
//         L.valid(q) && rank(q) + m <= L.size && L.sorted(q,m)
// 注意：在归并排序之类的场合，有可能 this == L && rank(p) + n == rank(q)
    Posi(T) pp = p->pred;//借助前驱(可能是header)，以便返回前...
    while (0 < m){//在q尚未移出区间之前
        if ((0 < n) && (p->data <= q->data))//若p仍在区间内且v(p) <= v(q),则
            { if (q == (p = p->succ)) break; n--;}//p归入合并的列表，并替换为其直接后继
        else//若p已超出右界或v(q) < v(p),则
            { insertB(p, L.remove((q = q->succ)->pred)); m--; }//将q转移至p之前
    }
    p = pp->succ;//确定归并区间的新起点
}