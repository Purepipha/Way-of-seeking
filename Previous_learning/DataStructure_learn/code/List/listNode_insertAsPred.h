template <typename T>
Posi(T) ListNode<T>::insertAsPred(T const & e)
{
    Posi(T) x = new ListNode(e, pred, this);//创建新节点
    pred->succ = x;//更新正向连接
    this->pred = x;
    return x;//返回新节点位置
}
