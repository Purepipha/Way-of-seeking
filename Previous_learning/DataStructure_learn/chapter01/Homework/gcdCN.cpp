// gcdCN.cpp -- 计算两个数的最大公约数
// 习题1-25
#include <iostream>
__int64_t gcdCN(__int64_t a, __int64_t b);
__int64_t mygcdCN(__int64_t a, __int64_t b);

__int64_t mygcdCN(__int64_t a, __int64_t b)
{
    int p = 1;// a和b的2^r公因子p
    while (a % 2 == 0 && b % 2 == 0) //若a和b同时为偶数
    {// p累乘2；a b同时除2
        p *= 2;
        a /= 2;
        b /= 2;
    } // 保证不可能a和b同时为偶数
    while (!(a & 1)) a >>= 1; // 若a偶b奇，删除a的所有因子2
    while (!(b & 1)) b >>= 1; // 若b偶a奇，删除b的所有因子2
    __int64_t t = abs(a - b);
    while (t != 0)
    {
        while (t % 2 == 0)
            t /= 2;
        a >= b ? a = t : b = t;
        t = abs(a - b);
    }
    return a*p;
}
__int64_t gcdCN(__int64_t a, __int64_t b)
{ // assert: 0 < min(a, b);
    int r = 0;// a和b的2^r形式的公因子
    while (!((a & 1) || (b & 1)))
    {// 若a和b均为偶数
        a >>= 1; // a右移
        b >>= 1; // b右移
        r++; // r累加
    }
    while(1)
    {
        while (!(a & 1)) a >>= 1; // 若a偶b奇，删除a的所有因子2
        while (!(b & 1)) b >>= 1; // 若b偶a奇，删除b的所有因子2
        (a > b) ? a = a - b : b = b - a;// 简化为gcd(max(a,b) - min(a,b), min(a,b))
        if (0 == a) return b << r; // 简化至平凡情况：gcd(0,b) = b
        if (0 == b) return a << r; // 简化至平凡情况：gcd(a,0) = a
    }
}

int main()
{
    using namespace std;
    __int64_t a = 128;
    __int64_t b = 64;
    __int64_t c = gcdCN(a, b);
    cout << "gcdCN(): " << c << endl;
    c = mygcdCN(a, b);
    cout << "mygcdCN(): " << c << endl;
    return 0;
}