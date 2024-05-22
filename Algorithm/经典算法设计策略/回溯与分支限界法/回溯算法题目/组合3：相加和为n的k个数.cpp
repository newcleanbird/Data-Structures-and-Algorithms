/*
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
示例 3:

输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
 
提示:

2 <= k <= 9
1 <= n <= 60

*/

/*
题目要求：
    集合：1~9 每个数字用一次(组合问题) 长度为k、和为n的组合
    树的深度：由k控制，path的长度不能超过k
    树的宽度：由集合控制，即集合的范围(元素个数)

vector<int> path;
vector<vector<int>> result;

1.递归函数的参数：
void backtracking(int targetSum, int k, int sum, int startindex) 目标和,控制组合(path)里的元素个数,收集路径path已有的和,控制for循环从哪里开始寻找

2.递归终止条件：
if(path.size() == k) // 结果路径(path.size())已经达到搜索数量要求(k),即k控制深度，深度到了就停止搜索
结果在叶子节点，终止时，如果发现和符合要求，则加入结果result
targetSum == sum

3.单层搜索到逻辑


*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int targetSum, int k, int sum, int startindex)// 目标和，path宽度，当前path和，开始搜索位置
    {
        if(path.size() == k) // 搜索结束
        {
            if(targetSum == sum)
            {
                result.push_back(path);
            }
            return;
        }
        for(int i = startindex; i <= 9; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i+1);
            path.pop_back();
            sum -=i;
        }
    }
    
     
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return result;
    }
};

// 剪枝
/*
    一共是1~9,path宽度要求是k,如果当前遍历剩余的数量小于k，则结束
    剩余数量：9-i
    结束:9-i < k
    不结束: 9 - i >= k 即 i <= 9-k

*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int targetSum, int k, int sum, int startindex)// 目标和，path宽度，当前path和，开始搜索位置
    {
        if(path.size() == k) // 搜索结束
        {
            if(targetSum == sum)
            {
                result.push_back(path);
            }
            return;
        }
        for(int i = startindex;  i <= 9 - (k - path.size()) + 1; i++)
        {
            sum += i;
            path.push_back(i);
            if (sum > targetSum) { // 剪枝操作
                sum -= i; // 剪枝之前先把回溯做了
                path.pop_back(); // 剪枝之前先把回溯做了
                return;
            }
            backtracking(targetSum, k, sum, i+1);
            path.pop_back();
            sum -=i;
        }
    }
    
     
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return result;
    }
};

