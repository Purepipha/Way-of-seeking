// power2BF_I.cpp -- 幂指数2^n算法(蛮力迭代版)，n >= 0
#include <iostream>

__int64_t power2BF_I (int n)
{ //幂指数2^n算法(蛮力迭代版)， n >= 0
    __int64_t pow = 1;  // O(1):累积器初始化为2^0
    while (n-- > 0) // O(n):迭代n轮，每轮都
        pow <<= 1;   // O(1):将累积器翻倍，注意翻倍应该是<<=
    return pow; // O(1)：返回累积器
} // O(n) = O(2^r),r为输入指数n的比特位数

__int64_t power2_I(int n)
{ // 幂指数2^n算法(优化迭代版)，n >= 0
    __int64_t pow = 1; //O(1):累积器初始化为2^0
    __int64_t p = 2; //O(1):累乘项初始化为2
    while (0 < n)
    { //O(logn)：迭代O(logn)轮，每轮都
        if ( n & 1) //O(1):根据当前比特位是否为1,决定是否
            pow *= p; // O(1)：将当前累乘项计入累积器
        p *= p;// O(1):累乘项自乘
        // if (n % 2 == 0)
        //     pow = sqr((pow << 1));
        // else
        //     pow = sqr((pow << 1)) << 1;
        n >>= 1;
    }
    return pow;
}
inline __int64_t sqr(__int64_t a) { return a * a; }
__int64_t power2_R(int n)
{ // 幂函数2^n算法(蛮力递归版),n >= 0
    // if (0 == n) return 1;
    return (n & 1) ? sqr(power2_R(n >> 1)) << 1 : sqr( power2_R( n >> 1));// 递归
} // O(n) = O(2^r),r为输入指数n的比特位数

__int64_t power2BF_R (int n)
{ // 幂指数2^n算法(蛮力递归版)， n >= 0
    return (1 > n) ? 1 : power2BF_R(n - 1) << 1; // 递归
    // if (n == 0)
    //     return 1; // n = 1
    // return power2BF_R(n - 1) << 1;
} // O(n) = O(2^r),r为输入指数n的比特位数

int main()
{
    using namespace std;
    cout << "Enter a number:";
    int n;
    cin >> n;
    cout << "Recurision: " << power2BF_R(n) << endl;
    cout << "Iterator: " << power2BF_I(n) << endl;
    cout << "power2_R(): " << power2_R(n) << endl;
    cout << "power2_I(): " << power2_I(n) << endl;
    return 0;
}