template <typename T> void increase(List<T> & L)//统一递增列表各项元素
{ L.traverse(Increase<T>()); }//以Increase为基本操作遍历