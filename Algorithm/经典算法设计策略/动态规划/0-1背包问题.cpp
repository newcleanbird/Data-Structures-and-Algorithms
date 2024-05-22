/*
0-1背包问题：有一些物品(只有)，选择放入有限的背包，求最大价值
基本概念：
    背包：容量V
    物品：价值w；体积v；每个物品的数量n
本质：每个物品选(1)不选(0)
*/

/*
动态规划：
    定义dp：dp[i][j]:[0,i]物品随意放容积为j的背包
            不放物品:dp[i][j] = dp[i-1][j]; // 和放i-1个物品的情况一样
            放物品:dp[i][j] = dp[i-1][j-weight[i]] + value[i];
    递推公式：dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
    初始化：dp[i][0] = 0;（第一列容积为0，全为0）
            dp[0][j] = 根据物品0的质量进行初始化
    遍历:(二维两层for是可以颠倒的)
        for()遍历物品
            for() 遍历容积
                递推公式
*/
/*
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000

输入样例
4 5
1 2
2 4
3 4
4 5

输出样例：
8


*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,v;    // 物品数量:n   背包体积：v
    cin >> n >> v;
    int weight[n], value[n]; // weight:各个物品的重量    value:各个物品的价格
    for(int i = 0; i < n; i++) // 输入0~n个物品
    {
        cin >> weight[i] >> value[i];
    }
    vector<vector<int>> dp(n, vector<int>(v + 1, 0));// 状态:dp[i][j] [0,i]物品随意放进容积为j的背包的价格
    // int dp[n][v];   
    // 初始化
    for(int j = weight[0]; j <= v; j++)
    {
        dp[0][j] = value[0];
    }

    // 遍历
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= v; j++)
        {
            if(j < weight[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }
        }
    }
    cout << dp[n-1][v];
    system("pause");
    
}

// void test_2_wei_bag_problem1() {
//     vector<int> weight = {1, 3, 4};
//     vector<int> value = {15, 20, 30};
//     int bagweight = 4;

//     // 二维数组
//     vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

//     // 初始化
//     for (int j = weight[0]; j <= bagweight; j++) {
//         dp[0][j] = value[0];
//     }

//     // weight数组的大小 就是物品个数
//     for(int i = 1; i < weight.size(); i++) { // 遍历物品
//         for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
//             if (j < weight[i]) dp[i][j] = dp[i - 1][j];
//             else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

//         }
//     }

//     cout << dp[weight.size() - 1][bagweight] << endl;
// }

// int main() {
//     test_2_wei_bag_problem1();
// }