// bottom_up_cut_rod.cpp -- DP法
#include <iostream>
#include <algorithm>
int bottom_up_cut_rod(int p[], int n, int r[]);
int main()
{
    using namespace std;
    int price[11] = {0,1,5,8,9,10,17,17,20,24,30};
    int memo[11] = {0};
    int max4 = bottom_up_cut_rod(price,9,memo);
    cout << max4 << endl;
    return 0;
}
int bottom_up_cut_rod(int p[], int n, int r[])
{
    // r[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int q = 0;
        for (int j = 1; j <= i; j++)
            q = std::max<int>(q,p[j] +r[i-j]);
        r[i] = q;
    }
    return r[n];
}