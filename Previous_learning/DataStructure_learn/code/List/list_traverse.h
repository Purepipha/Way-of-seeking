template <typename T>
void List<T>::traverse(void (*visit)(T &))//借助函数指针机制遍历
{ for (Posi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data); }

template <typename T> template <typename VST>//元素类型，操作器
void List<T>::traverse(VST & visit)//借助函数对象机制遍历
{ for (Posi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data); }