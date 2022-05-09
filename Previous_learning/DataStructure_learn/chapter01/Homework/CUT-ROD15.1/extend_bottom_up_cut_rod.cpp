// extend_bottom_up_cut_rod.cpp -- DP法+输出长度
#include <iostream>
#include <algorithm>
int extend_bottom_up_cut_rod(int p[], int n, int r[], int s[]);
int main()
{
    using namespace std;
    int price[11] = {0,1,5,8,9,10,17,17,20,24,30};
    int memo[11] = {0};
    int first_len[11] = {0};
    int max4 = extend_bottom_up_cut_rod(price,10,memo,first_len);
    for (int i = 1; i <= 10; i++)
    {
        cout << memo[i] << "\t";
    }
    cout << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << first_len[i] << "\t";
    }
    cout << endl;
    return 0;
}
int extend_bottom_up_cut_rod(int p[], int n, int r[], int s[])
{
    // r[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int q = 0;
        for (int j = 1; j <= i; j++)
            if (q < p[j] + r[i - j])
            {
                q = p[j] + r[i - j];
                s[i] = j;
            }
        r[i] = q;
    }
    return r[n];
}