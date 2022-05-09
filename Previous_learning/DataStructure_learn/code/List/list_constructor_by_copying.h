template <typename T>//复制列表中自位置p起始的n项(assert:p为合法位置，且至少有n-1个后继结点)
List<T>::List(Posi(T) p, int n) { copyNodes(p, n); }

template <typename T>//整体复制列表L
List<T>::List(List<T> const & L) { copyNodes(L.first(), _size); }

template <typename T>//复制L中自r项起的第n项
List<T>::List(List<T> const & L, int r, int n) { copyNodes(L[r], n); }