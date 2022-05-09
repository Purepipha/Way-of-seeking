template <typename T>
int Vector<T>::deduplicate(){//删除无序向量中重复元素(繁琐版)
int oldSize = _size;//记录原向量规模
int i = -1;//从最前端开始
while(++i < _size - 1){//从前向后，逐一
    int j = i + 1;
    while(j < _size)
        if(_elem[i] == _elem[j]) remove(_elem[j]);//若雷同，则删除后者
        else j++;//并继续扫描
    }
return oldSize - _size;//响亮规模变化量，即被删除元素总数
}