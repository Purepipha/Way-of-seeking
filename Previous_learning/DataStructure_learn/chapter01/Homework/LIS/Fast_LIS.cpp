// Fast_LIS.cpp -- 时间复杂度O(nlogn)
// 算法导论 15.4-6
#include <iostream>
#include <algorithm>

int binpos(int ar[], int n, int x);
int Fast_LIS(int ar[], int n, int r[]);

int main()
{
    using namespace std;
    int arr[8] = {10,9,2,5,3,7,101,18};
    int test[8] = {0};
    int len = Fast_LIS(arr, 8, test);
    cout << len << endl;
    return 0;
}

int Fast_LIS(int ar[], int n, int r[])
{
    int len = 1;
    r[0] = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (r[len - 1] < ar[i])
            r[len++] = ar[i];
        if (r[len - 1] > ar[i])
        {
            int pos = binpos(r, len, ar[i]);
            r[pos] = ar[i];
        }
    }
    return len;
}

int binpos(int ar[], int n, int x)
{
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (ar[mid] > x)
            hi = mid - 1;
        if (ar[mid] < x)
            lo = mid + 1;
        if (ar[mid] == x)
            return mid;
    }
    return lo;
}