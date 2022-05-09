template <typename T>
Posi(T) ListNode<T>::insertAsSucc(T const & e)
{
    Posi(T) x = new ListNode(e, this, succ);//创建新节点
    succ->pred = x;//更新反向连接
    succ = x;
    return x;//返回新节点位置
}
