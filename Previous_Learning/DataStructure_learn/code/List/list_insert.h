template <typename T>
Posi(T) List<T>::insertAsFirst(T const & e){
    _size++; return header->insertAsSucc(e);//e作为首节点插入
}

template <typename T>
Posi(T) List<T>::insertAsLast(T const & e){
    _size++; return trailer->insertAsPred(e);//e当作末节点插入
}

template <typename T>
Posi(T) List<T>::insertA(Posi(T) p, T const & e){
    _size++; return p->insertAsSucc(e);//e当作p的后继插入(After)
}

template <typename T>
Posi(T) List<T>::insertB(Posi(T) p, T const & e){
    _size++; return p->insertAsPred(e);//e当作p的前驱插入(Before)
}