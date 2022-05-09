template <typename T>
T & Vector<T>::operator[](Rank r)//重载下标操作符
{return _elem[r]; }//assert 0 <= r < _size

template <typename T>
const T & Vector<T>::operator[](Rank r) const//仅限于右值
{return _elem[r];}//assert 0 <= r < _size