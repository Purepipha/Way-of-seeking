// LIS.cpp -- 计算n个数的最长单调递增子序列
// 算法导论 15.4-5
#include <iostream>
#include <algorithm>
int LIS_Get(int ar[], int n, int r[]);

int main()
{
    using namespace std;
    int arr[6] = {0,1,0,3,2,3};
    int resulut[6] = {0};
    int len = LIS_Get(arr, 6, resulut);
    for (int i = 0; i < len; i++)
        cout << resulut[i] << " ";
    cout << endl << "len: ";
    cout << len << endl;
    return 0;
}

int LIS_Get(int ar[], int n, int r[])
{
    int memo[n];
    for (int i = 0; i < n; i++)
        memo[i] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
        {
            if (ar[j] < ar[i])
            {
                memo[i] = std::max<int>(memo[i],memo[j]+1);
            }
        }
    int max_id = 0;
    for (int i = 0; i < n; i++)
        max_id = memo[max_id] >= memo[i] ? max_id : i;
    for (int i = memo[max_id] - 1; i >= 0; i--)
    {
        for (int j = n - 1; j>=0; j--)
            if (memo[j] == i + 1)
            {
                r[i] = ar[j];
                break;
            }
    }
    return memo[max_id];
}