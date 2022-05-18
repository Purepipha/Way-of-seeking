// String.h -- 实现一个字符串类，并提供比较器，或重载相应的操作符
// 数据结构C++ 2-17
#pragma once
class String
{
private:
    char * _str;
    int _size;
public:
    String() : _str(nullptr), _size(0) { };
    String(const char * str);
    bool operator==(const String & s);
    bool operator<(const String & s);
    bool operator>(const String & s);
    friend int compare(const String & s1, const String & s2);
    ~String() { delete [] _str; _size = 0; }
};
String::String(const char * str)
{
    for (_size = 0; str[_size] != '\0';_size++)
    _str = new char[_size + 1];
    for (int i = 0; i < _size; i++)
        _str[i] = str[i];
    _str[_size] = '\0';
}
int compare (const String & s1, const String & s2)
{
    int min_size =s1._size > s2._size ? s2._size : s1._size;
    for (int i = 0; i < min_size; i++)
        if (s1._str[i] < s2._str[i])
            return -(i + 1);
        else if (s1._str[i] > s2._str[i])
            return i;
    if (s1._size == s2._size)
        return 0;
    else if (s1._size > s2._size)
        return s2._size;
    else
        return -s1._size;
}
bool String::operator==(const String & s)
{
    if (compare(*this,s) == 0)
        return true;
    else
        return false;
}

bool String::operator<(const String & s)
{
    if (compare(*this, s) < 0)
        return true;
    else
        return false;
}

bool String::operator>(const String & s)
{
    if (compare (*this, s) > 0)
        return true;
    else
        return false;
}