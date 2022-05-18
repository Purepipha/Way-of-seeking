// extend_memo_cut_rod.cpp -- 自顶向下 + 返回切割方案
// 算法导论 15.1-4
#include <iostream>
#include <algorithm>
int extend_memo_cut_rod(int p[], int n, int r[], int s[]);
int main()
{
    using namespace std;
    int price[11] = {0,1,5,8,9,10,17,17,20,24,30};
    int memo[11] = {0};
    int first_len[11] = {0};
    int max4 = extend_memo_cut_rod(price,10,memo,first_len);
    for (int i = 1; i <= 10; i++)
    {
        cout << memo[i] << "\t";
    }
    cout << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << first_len[i] << "\t";
    }
    return 0;
}
int extend_memo_cut_rod(int p[], int n, int r[], int s[])
{
    if (n == 0)
        return r[n] = 0;
    if (r[n] > 0)
        return r[n];
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (r[n] < p[i] + extend_memo_cut_rod(p, n - i, r, s))
            {
                r[n] = p[i] + extend_memo_cut_rod(p, n - i, r, s);
                s[n] = i;
            }
        }
    }
    return r[n];
}