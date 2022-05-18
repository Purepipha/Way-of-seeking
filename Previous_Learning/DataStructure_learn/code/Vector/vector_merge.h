template <typename T>   //有序向量的归并
void Vector<T>::merge(Rank lo, Rank mi, Rank hi){//各自有序的子向量[lo,mi)和[mi,hi)
    T * A = _elem + lo; //合并后的向量A[0,ho-lo) = _elem[lo, hi)
    Rank lb = mi - lo;
    T * B = new T[lb]; //前子向量B[0,lb) = _elem[lo,mi)
    for (Rank i = 0; i < lb;i++)// 复制前子向量
    {B[i] = A[i];}
    Rank lc = hi - mi;
    T * C = _elem + mi; //后子向量C[0,lc) = _elem[mi,hi)
    for (Rank i = 0, j = 0, k = 0;(j < lb) || (k < lc);)
    { //B[j]和C[k]中的小者续至A末尾
        if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
            A[i++] = B[j++];
        if ((k < lc) && (!(j < lb) || (B[j] > C[k])))
            A[i++] = C[k++];
    }
    delete [] B;
}