#pragma once
// Vector definition
#include <iostream>
#define DEFAULT_CAPACITY 3  //默认初始容量(实际应用中可设置为更大)
using Rank = int;
#define MERGE_CAPACITY 1000//vector
template <typename T>
class Vector{// 向量模板类
protected:
    Rank _size; //规模
    int _capacity; //容量
    T * _elem; //数据区
    T * B = new T[MERGE_CAPACITY]; //megre_imporve needed
    void copyFrom(T const * A, Rank lo, Rank hi); //复制数组区间A[lo,hi)
    void expand(); //空间不足时扩容
    void shrink(); //装填因子过小时压缩
    bool bubble(Rank lo, Rank hi);  //扫描交换
    void bubbleSort(Rank lo, Rank hi);  //起泡排序算法
    Rank maxItem(Rank lo, Rank hi); //选取最大元素
    void merge(Rank lo, Rank mi, Rank hi);  //归并算法
    void merge_improve(Rank lo, Rank mi, Rank hi);//改进归并算法
    void mergeSort(Rank lo, Rank hi);   //归并排序算法
    void heapSort(Rank lo, Rank hi);    //堆排序(稍后结合完全堆讲解)
    Rank partition(Rank lo, Rank hi);   //轴点构造算法
    void quickSort(Rank lo, Rank hi);   //快速排序算法
    void insertionSort(Rank lo, Rank hi);//插入排序算法
    void selectionSort(Rank lo, Rank hi);//选择排序算法
    void shellSort(Rank lo, Rank hi);   //希尔排序算法
public:
//构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //容量为c、规模为s、所有元素初始为v
    {_elem = new T[_capacity = c];for(_size = 0; _size < s; _elem[_size++] = v);}
    Vector(T const * A, Rank n) {copyFrom(A, 0, n);}//数组整体复制
    Vector(T const * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }//区间
    Vector(Vector<T> const & V) {copyFrom(V._elem, 0, V._size);}//向量整体复制
    Vector(Vector<T> const & V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }//区间
// 析构函数
    ~Vector() { delete []_elem; delete [] B;}//释放内部空间
// 只读访问接口
    Rank size() const {return _size;}//规模
    bool empty() const {return !_size;}//判空
    Rank find(T const & e) const {return find(e, 0, _size);}//无序向量整体查找
    Rank find(T const & e, Rank lo, Rank hi) const;//无序向量区间查找
    Rank search(T const & e) const//有序向量整体查找
    { return (0 >= _size) ? -1 : search(e, 0, _size);}
    Rank search(T const & e, Rank lo, Rank hi) const;//有序向量区间查找
    friend std::ostream & operator<<(std::ostream & os, T const & v)
    {os << v;return os;}//

// 可写访问接口
    T & operator[](Rank r);//重载下标操作符，可以类似于数组形式引用各元素
    const T & operator[](Rank r)const; //仅限于做右值的重载版本
    Vector<T> & operator=(Vector<T> const &);//重载赋值操作符，以便直接克隆向量
    T remove(Rank r);//删除秩为r的元素
    int remove(Rank lo, Rank hi);//删除区间[lo,hi)之内的元素
    Rank insert(Rank r, T const& e);//插入元素
    void sort(Rank lo, Rank hi);//对[lo,hi)进行排序
    void sort(){ sort(0, _size);}//整体排序
    void unsort(Rank lo, Rank hi);//对[lo,hi)置乱
    int deduplicate();//无序去重
    int uniquify();//有序去重
// test needed
    // void mergesort_improve(Rank lo, Rank hi);
    // void merge_slow(Rank lo, Rank mi, Rank hi);
    // void mergesort(Rank lo, Rank hi);
// 遍历
    void traverse(void(*) (T &));//遍历(使用函数指针，只读或者局部性修改)
    template<typename VST> void traverse(VST &);//遍历(使用函数对象，可全局性修改)
};//Vector

// // test mergesort needed
// template <typename T>   //有序向量的归并
// void Vector<T>::merge_improve(Rank lo, Rank mi, Rank hi){//各自有序的子向量[lo,mi)和[mi,hi)
//     T * A = _elem + lo; //合并后的向量A[0,ho-lo) = _elem[lo, hi)
//     Rank lb = mi - lo;
//     // T * B = new T[lb]; //前子向量B[0,lb) = _elem[lo,mi)
//     for (Rank i = 0; i < lb; i++){// 复制前子向量
//         B[i] = A[i];
//     }
//     Rank lc = hi - mi;
//     T * C = _elem + mi; //后子向量C[0,lc) = _elem[mi,hi)
//     for (Rank i = 0, j = 0, k = 0;(j < lb) || (k < lc);)
//     { //B[j]和C[k]中的小者续至A末尾
//         if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
//             A[i++] = B[j++];
//         if ((k < lc) && (!(j < lb) || (B[j] > C[k])))
//             A[i++] = C[k++];
//     }
//     // delete [] B;
// }

// template <typename T> // 向量归并排序
// void Vector<T>::mergesort_improve(Rank lo, Rank hi)
// { // 0 <= lo <= hi <= _size
//     if (hi - lo < 2) // 单元素区间自然有序，否则..
//         return;
//     Rank mi = (lo + hi) >> 1; // 以中点为界
//     mergesort_improve(lo,mi);
//     mergesort_improve(mi,hi); // 分别排序
//     merge_improve(lo, mi, hi); // 归并
// }

// template <typename T>   //有序向量的归并
// void Vector<T>::merge_slow(Rank lo, Rank mi, Rank hi){//各自有序的子向量[lo,mi)和[mi,hi)
//     T * A = _elem + lo; //合并后的向量A[0,ho-lo) = _elem[lo, hi)
//     Rank lb = mi - lo;
//     T * B = new T[lb]; //前子向量B[0,lb) = _elem[lo,mi)
//     for (Rank i = 0; i < lb;i++)// 复制前子向量
//     {B[i] = A[i];}
//     Rank lc = hi - mi;
//     T * C = _elem + mi; //后子向量C[0,lc) = _elem[mi,hi)
//     for (Rank i = 0, j = 0, k = 0;(j < lb) || (k < lc);)
//     { //B[j]和C[k]中的小者续至A末尾
//         if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
//             A[i++] = B[j++];
//         if ((k < lc) && (!(j < lb) || (B[j] > C[k])))
//             A[i++] = C[k++];
//     }
//     delete [] B;
// }

// template <typename T> // 向量归并排序
// void Vector<T>::mergesort(Rank lo, Rank hi)
// { // 0 <= lo <= hi <= _size
//     if (hi - lo < 2) // 单元素区间自然有序，否则..
//         return;
//     Rank mi = (lo + hi) >> 1; // 以中点为界
//     mergesort(lo,mi);
//     mergesort(mi,hi); // 分别排序
//     merge_slow(lo, mi, hi); // 归并
// }