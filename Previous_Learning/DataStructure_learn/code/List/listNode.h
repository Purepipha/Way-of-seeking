typedef int Rank;//秩
template <typename T> struct ListNode;
#define Posi(T) ListNode<T> * //列表节点位置

template <typename T> struct ListNode{//列表结点模板类(以双向链表形式实现)
// 成员
    T data; Posi(T) pred; Posi(T) succ;//数值、前驱、后继
// 构造函数
    ListNode() {} //针对header和trailer的构造
    ListNode(T e, Posi(T) p = nullptr, Posi(T) s = nullptr)
        : data(e), pred(p), succ(s) {}//默认构造器
// 操作结构
    Posi(T) insertAsPred(T const & e);//紧靠当前节点之前插入新节点
    Posi(T) insertAsSucc(T const & e);//紧靠当前节点之后插入新节点
};