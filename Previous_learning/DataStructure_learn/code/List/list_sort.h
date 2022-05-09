template <typename T>
void List<T>::sort(Posi(T) p, int n){//列表区间排序
    switch (rand() % 3){//随机选择排序算法，可根据具体问题的特点灵活选取或扩充
        case 0 : insertionSort(p, n);break;//插入排序
        case 1 : selectionSort(p, n);break;//选择排序
        case 2 : mergeSort(p, n);break;//归并排序
    }
}