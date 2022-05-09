// max.cpp -- get max value in A[]
// 习题1-15
#include <iostream>
int maxI(int A[], int n)
{ //求数组最大值算法(迭代版)
    int max = INT16_MIN; //O(1):初始化最大值
    for (int i = 0; i < n; i++) //O(n):对全部O(n)个元素，逐一
        max = max < A[i] ? A[i] : max; //O(1):比较并更新
    return max; //O(1):返回最大值
}// O(1)+O(n)*O(1)+O(1) = O(n)
int maxR(int A[], int n)
{ //求数组最大值算法(递归版)
    if (n < 2) //平凡情况：递归基
        return A[n - 1]; //直接按(非递归式)计算
    return maxR(A, n - 1) > A[n - 1] ? maxR(A, n - 1) : A[n - 1]; //在前n-1项最大值与第n-1项之间，取大者
    // if (n < 1) // wrong, n > 0,elem of A is A[0] - A[n-1]
    //     return A[0];
    // return maxR(A, n - 1) > A[n] ? maxR(A, n - 1) : A[n];
} //O(1) * 递归深度 = O(1) * (n + 1) = O(n)
int maxR1(int A[], int lo, int hi)
{
    if (lo + 1 ==hi)
        return A[lo];
    else
    {
        int mi = (hi + lo) >> 1;
        return maxR1(A, lo, mi) > maxR1(A, mi, hi) ? maxR1(A, lo, mi) : maxR1(A, mi, hi);
    }
}

int main()
{
    using namespace std;
    int arr[5] = {1, 6, 9, 5, 4};
    int max = maxR1(arr, 0, 5);
    cout << max << endl;
    return 0;
}