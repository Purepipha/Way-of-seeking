// bottom_up_cut_rod_c.cpp -- 增加成本c
// 算法导论 15.1-3
#include <iostream>
#include <algorithm>
const int c = 2;    // 每次切割增加的成本c
int bottom_up_cut_rod(int p[], int n, int r[]);
int main()
{
    using namespace std;
    int price[11] = {0,1,5,8,9,10,17,17,20,24,30};
    int memo[11] = {0};
    int max4 = bottom_up_cut_rod(price,10,memo);
    for (int i = 1; i <= 10; i++)
    {
        cout << memo[i] << "\t";
    }
    return 0;
}
int bottom_up_cut_rod(int p[], int n, int r[])
{
    for (int i = 1; i <= n; i++)
    {
        int q = 0;
        for (int j = 1; j <= i; j++)
        {
            if (j < i)
            {
                q = std::max<int>(q, p[j] + r[i - j] - c);
            }
            else
            {
                q = std::max<int>(q, p[j] + r[i - j]);
            }
        }
        r[i] = q;
    }
    return r[n];
}