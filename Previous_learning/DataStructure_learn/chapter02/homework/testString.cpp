// testString.cpp -- 测试String类
// 数据结构C++ 2-17
#include "String.h"
#include <iostream>
int main()
{
    using namespace std;
    String s1("abcde");
    String s2("edfgl");
    String s3("aacdf");
    String s4("abcde");
    if (s1 < s2)
        cout << "s1 < s2" << endl;
    if (s1 == s4)
        cout << "s1 = s4" << endl;
    if (s1 > s3)
        cout << "s1 > s3" << endl;
    return 0;
}