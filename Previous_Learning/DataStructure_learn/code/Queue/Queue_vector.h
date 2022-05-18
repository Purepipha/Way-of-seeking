#include "../Vector/Vector.h"
template <typename T>
class Queue : public Vector<T>{
public:
    void enqueue(T const& e){ insert(size() + 1, e); }//入队
    T dequeue() { return remove(0); }//出队
    T& front() { return (*this)[0]; }//返回队首元素
};