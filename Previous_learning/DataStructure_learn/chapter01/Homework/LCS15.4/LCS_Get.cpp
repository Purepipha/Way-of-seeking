// LCS_Gwt.cpp -- get a LCS of two strings
// 算法导论 15.4-1 + 15.4-2 + 15.4-3
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using std::string;
int LCS_Get(string A, string B);  // 普通递归法，无法存储返回结果
int memo_LCS_Get(string A, string B, int dp[]); // 自上向下记忆递归法 Memoization
// FIXME修复下面的程序，运行结果不同
int bottom_up_LCS_Get(string A, string B, string * C);  // DP 自底向上法 15.4_1 and 15.4-2

int main()
{
    using namespace std;
    clock_t start, end;
    string nums1 = "10010101";
    string nums2 = "010110110";
    string nums;
    int dp[(nums1.length()+1)*(nums2.length()+1)] = {0};    // 需要零初始化
    start = clock();
    int len_get = LCS_Get(nums1, nums2);
    end = clock();
    cout << "Recursion version time: " << double(end - start) / CLOCKS_PER_SEC << endl;
    start = clock();
    int len_memo = memo_LCS_Get(nums1, nums2, dp);
    end = clock();
    cout << "Iterate version time: " << double(end - start) / CLOCKS_PER_SEC << endl;
    cout << "Recursion length: " << len_get << endl;
    cout << "Iterate length: " << len_memo << endl;
    int len = bottom_up_LCS_Get(nums1,nums2, &nums);
    cout << "Maximun length of LCS is " << len << endl;
    cout << "LCS: " << nums << endl;
    return 0;
}

int LCS_Get(string A, string B)
{
    int lenA = A.length();
    int lenB = B.length();
    if (lenA == 0 || lenB == 0)
        return 0;
    if (A[lenA-1] == B[lenB-1])
    {
        A.pop_back();
        B.pop_back();
        return LCS_Get(A,B) + 1;
    }
    else
    {
        string A1 = A;
        string B1 = B;
        A1.pop_back();
        B1.pop_back();
        return std::max<int>(LCS_Get(A1,B),LCS_Get(A,B1));
    }
}

int memo_LCS_Get(string A, string B, int dp[])
{
    int lenA = A.length();
    int lenB = B.length();
    for (int i = 1; i <= lenA; i++)
        for (int j = 1; j <= lenB; j++)
        {
            if (A[i-1] == B[j - 1])
                dp[i* (lenB+1) + j] = dp[(i-1)*(lenB+1) + j - 1] + 1;
            else
            {
                dp[i* (lenB+1) + j] = std::max<int>(dp[(i-1)*(lenB+1) + j],
                    dp[i * (lenB + 1) + j-1]);
            }
        }
    return dp[lenA*(lenB+1)+lenB];
}

int bottom_up_LCS_Get(string A, string B, string * C)
{
    int lenA = A.length();
    int lenB = B.length();
    int DP[lenA+1][lenB+1] = {0};
    for (int i = 1; i <= lenA; i++)
        for (int j = 1; j <= lenB; j++)
        {
            if (A[i-1] == B[j - 1])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
            {
                DP[i][j] = std::max<int>(DP[i-1][j], DP[i][j-1]);
            }
        }
    int i = lenA;
    int j = lenB;
    while (i > 0 && j > 0)
    {
        if (DP[i][j] == DP[i-1][j-1]+1)
        {
            C->push_back(A[i-1]);
            i--;
            j--;
        }
        if (DP[i][j] == DP[i][j-1])
        {
            j--;
        }
        if (DP[i][j] == DP[i-1][j-1])
        {
            i--;
        }
    }
    C->reserve();
    return DP[lenA][lenB];
}