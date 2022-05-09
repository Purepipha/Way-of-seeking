#include "listNode.h"//引入模板节点类

template <typename T> class List{//别表模板类
private:
    int _size; Posi(T) header; Posi(T) trailer;//规模、头哨兵、尾哨兵
protected:
    void init();//列表创建时的初始化
    int clear();//清楚所有节点
    void copyNodes(Posi(T) p, int n);//复制自列表位置起的第n项
    void merge(Posi(T) &, int, List<T>&, Posi(T) &, int);//归并
    void mergeSort(Posi(T) & p, int n);//对从p开始连续的n个节点归并排序
    void selectionSort(Posi(T) p, int n);//对从p开始连续的n个节点选择排序
    void insertionSort(Posi(T) p, int n);//对从p开始连续的n个节点插入排序
public:
//构造函数
    List() {init();}//默认
    List(List<T> const & L);//整体复制列表L
    List(List<T> const & L, Rank r, int n);//复制列表L自第r项起的第n项
    List(Posi(T) p, int n);//复制列表中自位置p起的n项
//析构函数
    ~List();//释放(包含头、尾哨兵在内的)所有节点
//只读访问接口
    Rank size() const { return _size; }//规模
    bool empty() const { return _size <= 0; }//判空
    T& operator[](Rank r)const;//重载，支持寻秩访问(效率低)
    Posi(T) first() const { return header->succ; }//首节点位置
    Posi(T) last() const { return trailer->pred; }//末节点位置
    bool valid(Posi(T) p)//判断p对外是否合法
    { return p && (p != header) && (p != trailer); }//将头尾节点等同于NULL
    int disoredred() const;//判断列表是否排序
    Posi(T) find(T const & e) const//无序列表查找
    { return find(e, _size, trailer); }
    Posi(T) find(T const & e, int n, Posi(T) p) const;//无序区间查找
    Posi(T) search(T const & e) const//有序列表查找
    { return search(e, _size, trailer); }
    Posi(T) search(T const & e, int n, Posi(T) p) const;//有序区间查找
    Posi(T) selectMax(Posi(T), int n) const;//在p及其n-1个后继中选出最大者
    Posi(T) selectMax() { return selectMax(header->succ, _size);}//整体最大者
//可写访问接口
    Posi(T) insertAsFirst(T const & e);//将e当作首节点插入
    Posi(T) insertAsLast(T const & e);//将e当作末节点插入
    Posi(T) insertA (Posi(T) p, T const & e);//将e当作p的后继插入
    Posi(T) insertB (Posi(T) p, T const & e);//将e当作p的前驱插入
    T remove(Posi(T) p);//删除合法位置p处的节点，则返回被删除节点
    void merge(List<T> & L) { merge(first(), size, L, L.first(), L.size());}//全列表归并
    void sort(Posi(T) p, int n);//列表区间排序
    void sort() { sort(first(), _size); }//列表整体排序
    int deduplicate();//无序去重
    int uniquify();//有序去重
    void reverse();//前后倒置
//遍历
    void traverse(void(*) (T &));//遍历，依次实施visit指针(函数指针，只读或局部性修改)
    template <typename VST>//操作器
    void traverse(VST &);//遍历，依次实施visit操作(函数对象，可全局性修改)
};//List