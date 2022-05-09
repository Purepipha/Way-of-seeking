template <typename T>//向量的起泡排序(跳跃)
void Vector<T>::bubbleSort(Rank lo, Rank hi){//assert:0<=lo<hi<=size
    for (Rank last = --hi; lo < hi; hi = last)
        for (Rank i = last = lo; i < hi; i++)
            if(_elem[i] > _elem[i])//若逆序，则
                std::swap(_elem[last = i], _elem[i+1]);//经过交换使局部有序
}
