// fib.cpp -- 计算第n个斐波那契数
#include <iostream>
#include <ctime>
long long fib_R(int n); // 二分递归
long long fib_LR(int n, long long & prev); // 线性递归
// 算法导论 15.1-5
long long fib_M(int n, long long M[]);         // 记忆递归+Memoization
long long fib_D(int n);         // 动态规划
int main()
{
    using namespace std;
    int n;
    clock_t start, end; // 统计计算时间
    long long result;   // 保存计算结果
    long long prev;     // 保存斐波那契数列前一项
    cout << "Enter a integer: ";
    cin >> n;
    // 迭代版
    start = clock();
    result = fib_D(n);
    end = clock();
    cout << "Iterator version: " << result << " time: "
         << double(end - start)/CLOCKS_PER_SEC << " secs" << endl;
    // 线性递归版
    start = clock();
    result = fib_LR(n, prev);
    end = clock();
    cout << "Line Recursion version: " << result << " time: "
         << double(end - start)/CLOCKS_PER_SEC << " secs" << endl;
    // 二分递归版
    start = clock();
    result = fib_R(n);
    end = clock();
    cout << "Recursion version: " << result << " time: "
         << double(end - start)/CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
long long fib_R(int n)
{
    return n < 2 ? n : fib_R(n - 1) + fib_R(n - 2);
}
long long fib_LR(int n, long long & prev)
{
    if (0 == n)
    {
        prev = 1;
        return 0;
    }
    else
    {
        long long preprev;
        prev = fib_LR(n - 1, preprev) ;
        return preprev + prev;
    }
}
long long fib_M(int n, long long M[])
{
    if (n < 2)
        return M[n] = n;
    if (M[n - 1] > 0 && M[n - 2] > 0) // 前两项存在
        M[n] = M[n - 1] + M[n - 2];
    else // 前两项不存在
        M[n] = fib_M(n - 1, M) + fib_M(n - 2, M);
    return M[n];
}

long long fib_D(int n)
{
    long long g = 0;
    long long f = 1;
    while (n--)
    {
        g = g + f;
        f = g - f;
    }
    return g;
}