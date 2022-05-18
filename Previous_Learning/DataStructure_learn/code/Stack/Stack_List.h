#include "../List/List.h"
template <typename T>
class Stack : public List<T>{
public:
    void push(T const& e) { insertAsLast(e); }//入栈
    T pop() { return remove(last()); }//出栈
    T& top() { return last()->data; } //取栈顶
};