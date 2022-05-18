// 求解整数n的费马拉格朗日分解
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
int getSqrt(int n){//找到不超过n的平方根的最大整数
    double i = sqrt(n);
    return int(i);
}
int sumSqrt(vector<int> vi){//求向量所有的平方和
    int sum = 0;
    for (int i = 0; i < vi.size(); i++)
        sum += (vi[i] * vi[i]);
    return sum;
}
void solve_FL(int n){//求解费马拉格朗日分解结果
    vector<vector<int>> res;//存储计算结果
    vector<int> vi(4,0);//存储一组结果
    int sq = getSqrt(n);
    for (int i = sq; i >= 0; i--){//从sq开始遍历，依次递减
        vi[0] = i;
        for (int j = i; j >= 0; j--){//从i开始遍历，依次递减
            if (sumSqrt(vi) > n)//如果结果大于n，回溯
                continue;
            vi[1] = j;
            for (int k = j; k >= 0; k--){//从j开始遍历
                if (sumSqrt(vi) > n)//如果结果大于n，回溯
                    continue;
                vi[2] = k;
                for (int l = k; l >= 0; l--){//从k开始遍历，回溯
                    vi[3] = l;
                    if (sumSqrt(vi) == n){
                        res.push_back(vi);
                    }
                }
            }
        }
    }
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int n;
    while (cin >> n){
        solve_FL(n);
    }
    return 0;
}