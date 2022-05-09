template <typename T>//向量的起泡排序(提前终止版)
void Vector<T>::bubbleSort(Rank lo, Rank hi){//assert:0<=lo<hi<=size
    for (bool sorted = false; sorted = !sorted;)
        for (Rank i = lo; i < hi - 1; i++)
            if(_elem[i] > _elem[i])//若逆序，则
                std::swap(_elem[i], _elem[i+1]), sorted = false;
                //经过交换使局部有序——当然，至此还不能确定已整体有序
}
