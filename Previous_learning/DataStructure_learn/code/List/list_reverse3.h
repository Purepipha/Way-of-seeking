template <typename T>
void List<T>::reverse(){//前后倒置
    if (_size < 2) return;//平凡情况
    Posi(T) p = header; Posi(T) q = trailer;
    for (int i = 1; i < _size; i += 2){//从首末节点开始，由外而内，捉对地
        swap((p = p->succ)->data, (q = q->pred)->data);//交换两边数据
    }
}
// my write
// void List<T>::reverse(){//前后倒置
//     if (_size < 2) return;//平凡情况
//     Posi(T) p; Posi(T) q;
//     for (p = header->succ, q = trailer->pred; p != q; p = p->succ, q = q->pred){//分别从首尾依次遍历
//         swap(p->data, q->data);//交换两边数据
//     }
// }