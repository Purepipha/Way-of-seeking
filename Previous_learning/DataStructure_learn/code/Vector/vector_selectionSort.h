#include "Vector.h"
template <typename T>//向量选择排序
void Vector<T>::selectionSort(Rank lo, Rank hi){//assert:0 < lo <=hi <=_size
    while (lo < hi--)
        swap(_elem[maxItem(lo, hi)], _elem[hi]);//将[hi]与[lo,hi]中的最大者交换
}

template <typename T>
Rank Vector<T>::maxItem(Rank lo, Rank hi){//在[lo,hi]内找出最大值
    Rank mx = hi;
    while (lo < hi--)//逆向扫描
        if(_elem[hi] > _elem[mx])//严格比较
            mx = hi;//max有多个时保证后者优先，进而保证selectionSort稳定
    return mx;
}
// my write
// template <typename T>//向量选择排序
// void Vector<T>::selectionSort(Rank lo, Rank hi){//assert:0 < lo <=hi <=_size
//     for (Rank r = hi, hi > lo; hi--){
//         swap(_elem[maxItem(lo, hi)], _elem[hi]);//将[hi]与[lo,hi]中的最大者交换
//     }
// }
