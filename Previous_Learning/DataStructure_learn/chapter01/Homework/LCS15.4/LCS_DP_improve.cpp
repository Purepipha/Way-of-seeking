// LCS_DP_improve.cpp -- 优化LCS的DP解法，使空间复杂度为常数复杂度，同时得到LCS的组成
// 课后作业3
// 空间复杂度O(1)时间复杂度O(mn*min(m,n))
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using std::string;

int timeschar(string s, char ch);               // 计算ch在s中出现的次数
int searchpos(string s, char ch, int n);        // 计算第n个ch出现的位置
int LCS_DP_improve(string A, string B, string & C);

int main()
{
    using namespace std;
    string str1 = "immaculate";
    string str2 = "computer";
    string str;
    int len = LCS_DP_improve(str1, str2, str);
    cout << str << endl;
    cout << "Length: " << len << endl;
    return 0;
}
int timeschar(string s, char ch)
{
    int len = s.size();
    int times = 0;
    for (int i = 0; i < len; i++)
        if (s[i] == ch)
            times++;
    return times;
}
int searchpos(string s, char ch, int n)
{
    int len = s.size();
    int timesch = 0;
    for (int i = 0; i < len; i++)
        if (s[i] == ch)
        {
            timesch++;
            if (timesch == n)
                return i;
        }
    return -1;          // 没有找到，本问题不存在
}
int LCS_DP_improve(string A, string B, string & C)
{
    int lenA = A.size();
    int lenB = B.size();
    int minlen = lenA > lenB ? lenB : lenA; // 计算A和B的最小长度
    int ir = -1;     // 每次喜欢开始的位置
    int jr = -1;     // 同ir
    string tempA;    // 记录每次寻找的位置
    for (int k = 0; k < minlen; k++)
    {
        int minpos = lenA + lenB;         // 记录相等时最小的x，y的坐标，初始为最大值
        char ch;    //记录找到的字母
        for (int i = ir + 1; i < lenA; i++)
            for (int j = jr + 1; j < lenB; j++)
                if(A[i] == B[j])
                {
                    if (minpos > i + j)
                    {
                        minpos = i + j;
                        ch = A[i];
                    }
                }
        if (minpos == lenA + lenB)      // 终止循环的条件
            break;
        C.push_back(ch);
        int timech = timeschar(C, ch);
        ir = searchpos(A, ch, timech);
        jr = minpos - ir;
    }
    return C.size();
}

