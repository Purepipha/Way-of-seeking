#include "../Vector/Vector.h"
template <typename T>
class Stack : public Vector<T>{
public:
    void push(T const& e) { insert(size(), e); }//入栈：等效于将新元素作为向量的末元素插入
    T pop() {return remove(size() - 1);}//出栈：等效于向量的末元素
    T & top() { return (*this)[size() - 1]; }//取顶，直接返回向量的末元素
};