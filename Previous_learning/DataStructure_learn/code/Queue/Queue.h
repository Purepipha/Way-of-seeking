#include "../List/List.h"
template <typename T>
class Queue : public List<T>{
public://size()、empty()以及其他开放接口均可沿用
    void enqueue(T const& e) { insertAsLast(e); }//入队，队尾插入
    T dequeue() { return remove(first()); }//出队，队首删除
    T& front() { return first()->data; }//队首
};