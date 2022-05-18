template <typename T>
Rank Vector<T>::find(T const & e, Rank lo, Rank hi) const // O(hi - lo) = O(n)
{   // 0 <= lo <= hi <_size
    while ((lo < hi--) && (e != _elem[hi])) // 逆向查找
    return hi;  // 返回值小于lo即意味着失败；否则即命中者的秩(有多个是，返回最大者)
}