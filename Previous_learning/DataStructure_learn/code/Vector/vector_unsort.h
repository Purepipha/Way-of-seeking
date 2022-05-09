template <typename T> void Vector<T>::unsort(Rank lo, Rank hi){//等概率随机置乱区间[lo,hi)
T * V = _elem + lo;//将子向量视作另一向量V[0,hi-lo)
for (Rank i = hi - lo; i > 0; i--)//自后向前
    swap(V[i-1],V[rand() % i]);//将V[i-1]与V[0,i)某一元素随机交换
}