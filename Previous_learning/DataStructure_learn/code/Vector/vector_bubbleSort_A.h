template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){//assert:0<=lo<hi<=size
    while(lo < --hi){//反复起泡扫描
        for(Rank i = lo; i < hi; i++)
            if(_elem[i] > _elem[i+1])
                std::swap(_elem[i], _elem[i + 1]);
    }
}
