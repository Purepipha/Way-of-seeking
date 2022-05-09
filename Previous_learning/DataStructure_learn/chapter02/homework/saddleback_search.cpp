// saddleback_search.cpp -- A[0.n)[0,n)为整数矩阵，二维向量，搜索A中不大于x的最大者
// 数据结构C++ 习题2-22
#include <iostream>

int binSearch(int A[], int e, int lo, int hi)
{
    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;
        (e < A[mid]) ? hi = mid : lo = mid + 1;
    }
    return --lo;
}
void report(int x)
{
    std::cout << x << std::endl;
}
void saddleback(int ** A, int x, int n)
{
    int i = 0;
    int j = binSearch(A[0], x, 0, n);
    while (i < n && -1 < j)
    {
        if (A[i][j] < x)
            i++;
        else if (x < A[i][j])
            j--;
        else
        {
            report(A[i][j]);
            i++;
            j--;
        }
    }
    report(A[--i][j]);
}

int main()
{
    using namespace std;
    int ** arr;
    arr = new int *[4];
    for (int i = 0; i < 4; i++)
        arr[i] = new int[4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = 4 * i + 2 * j;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    saddleback(arr, 11, 4);
    return 0;
}