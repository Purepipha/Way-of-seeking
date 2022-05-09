template <typename T>
List<T>::~List(){//析构函数
    clear(); delete header; delete trailer;//清空列表，释放头、尾节点
}