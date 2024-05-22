/*
礼物的最大价值:
题目描述：
    一个m*n的棋盘，每一格都有一个礼物，每个礼物都有一定的价值(价值大于0)。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格，直到到达格子右下角。
    给定一个棋盘，给定上面的价值，请你计算一共能拿到多少价值的礼物。
    程序输入：
    3 3
    1 3 1
    1 5 1
    4 2 1
    答案：12
    输入：
    [1,3,1] 
    [1,5,1]
    [4,2,1]
    输出:12
    路径：1->3->5->2->1

1.确定定义
    注意传入的二维数组为 int[][] [] [] grid；
    新建一个n行m列的与输入同格式二维数组 int [] []dp
    但新建的二维数组dp里要装什么？动动你的小脑袋想想，

    【动态规划通过循环做出每一步的最优解从而自底向上的得出对问题的整体最优解】（这句话在本文至少出现三遍…）,
    那当然显而易见的新建二维数组dp其中 每个元素 是当前循环中的想求的最优解
    看不懂上面这句话的笨蛋 在本文 Ctrl+F 搜索 “吃饭” ，背下例子并把【】的话背三十遍
    为了更清楚的解释我们建的dp数组要装什么玩意，这里举例（作者S1aine真的殚心竭虑地想给你说明白）

2.找初始值
    回忆一下刚才咱们在 “连续子数组的最大和” 里怎么定义初始值的？直接把初值第0个赋予了max和dp[i]
    这里的初值什么？ 第一反应是左上角的grid[0] [0] ，将它作为初始值赋予dp[0] [0]没有问题
    但是同时要结合题干考虑，题干里明确说了每次只能 “向右 或者 向下” 走，那就明显还需要边界的初始值来约束路径
    那边界初始值自然是dp中第0行和第0列了，求第0行和第0列两串初始值

3.思考关系
i,j表示行，列：
    当i = 0, j = 0时，为初始元素
    当i = 0,j != 0时，为第一列元素，只能从上面过来
    当i != 0, j = 0时，为第一行元素，只能从左边来
    当i != 0, j != 0时，可从左边或者上面到来
    {
        dp[0][0] = gird[0][0];
        dp[0][j] = gird[0][j] + grid[0][j - 1];
        dp[i][0] = gird[i][j] + gird[i-1][0];
        dp[i][j] = gird[i][j] + max(dp[i-1][j], dp[i][j-1])
    }
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 输入
    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // for(auto i : arr){
    //     for(auto j : i){
    //         cout << j;
    //     }
    // }
    // system("pause");
    vector<vector<int> > arr_result(n, vector<int>(m));
    // 把初始值补齐
    arr_result[0][0] = arr[0][0];
    // 把第一列当前最佳补齐
    for(int i = 1; i < n; i++)
    {
        arr_result[i][0] = arr_result[i - 1][0] + arr[i][0];
    }
    // 把第一行当前最佳补齐
    for(int j = 1; j < m; j++)
    {
        arr_result[0][j] = arr_result[0][j - 1] + arr[0][j];
    }

    // for(auto i : arr_result){
    //     for(auto j : i){
    //         cout << j;
    //     }
    // }
    // system("pause");

    // 遍历所有位置
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            arr_result[i][j] = max(arr_result[i - 1][j], arr_result[i][j - 1]) + arr[i][j];
        }
    }
    cout << arr_result[n - 1][m - 1];

    system("pause");
}