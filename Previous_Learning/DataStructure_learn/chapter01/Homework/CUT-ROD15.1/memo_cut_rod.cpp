// memo_cut_rod.cpp -- dp法+自顶向下
#include <iostream>
#include <algorithm>
int memo_cut_rod(int p[], int n, int r[]);
int main()
{
    using namespace std;
    int price[11] = {0,1,5,8,9,10,17,17,20,24,30};
    int memo[11] = {0};
    int max4 = memo_cut_rod(price,9,memo);
    cout << max4 << endl;
    return 0;
}
int memo_cut_rod(int p[], int n, int r[])
{
    if (n == 0)
        return r[n] = 0;
    if (r[n] > 0)
        return r[n];
    else
    {
    for (int i = 1; i <= n; i++)
        r[n] = std::max<int>(r[n],p[i] + memo_cut_rod(p, n - i,r));
    }
    return r[n];
}