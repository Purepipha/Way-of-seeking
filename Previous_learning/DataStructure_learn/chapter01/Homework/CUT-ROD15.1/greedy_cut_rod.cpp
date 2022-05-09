// greedy_cut_rod.cpp -- greedy algorithm 找反例
// 算法导论 15.1-2
#include <iostream>
int max_index(double a[], int n);
int * greedy_cut_rod(int p[], int n, int r[]);
int main()
{
    using namespace std;
    int price[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int memo[11] = {0};
    int *first_len = greedy_cut_rod(price, 10, memo);
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
    delete []first_len;
    return 0;
}
int max_index(double a[], int n)
{
    int id = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[id] < a[i])
            id = i;
    }
    return id;
}
int * greedy_cut_rod(int p[], int n, int r[])
{
    // r[0] = 0;
    int * s = new int[n+1];
    double po[n];
    for (int i = 1; i <= n; i++)
        po[i] = double(p[i]) / i;
    for (int i = 1; i <= n; i++)
    {
        int id = max_index(po, i);
        s[i] = id;
        r[i] += p[id];
        int t = i - id;
        while (t > 0)
        {
            id = max_index(po, t);
            r[i] += p[t];
            t = t - id;
        }
    }
    return s;
}