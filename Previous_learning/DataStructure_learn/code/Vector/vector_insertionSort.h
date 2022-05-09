template <typename T>//向量的插入排序
void Vector<T>::insertionSort(Rank lo, Rank hi){
    for (Rank r = lo + 1; r < hi; r++){//从lo后面的第一个元素开始遍历
        insert(find(_elem[r], lo, r), remove(r));//将该元素移动到适合的位置
    }
}