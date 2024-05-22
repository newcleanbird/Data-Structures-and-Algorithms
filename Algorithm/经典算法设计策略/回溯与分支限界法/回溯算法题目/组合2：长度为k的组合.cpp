/*
77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
 

提示：

1 <= n <= 20
1 <= k <= n
*/

/*
组合问题->回溯法
题目：集合n([1,n]个数)，长度为k的组合
1.确定递归函数的参数以及返回值
    需要用到，集合元素->n,path长度->k,开始搜索的位置startindex
2.确定递归的终止条件,收集解
    题目要求长度为k的组合，因此只要搜索到了长度为k的组合，那么即终止。 path.size() == k
    收集解：result.push_back(path);
3.确定单层搜索(递归)的逻辑
    从i=instartindex开始搜索，终止条件是将集合中的都搜索一遍(或者可个数小于需要的个数即推出)
    搜索：访问当前节点(i)时，将节点值加入到path中
    递归：继续搜索
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int n,int k,int startindex)
    {
        if(path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for(int i = startindex; i <= n; i++) // 从startindex开始搜索到n
        {
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
    
    
};

/*
剪枝操作：
    接下来看一下优化过程如下：
    已经选择的元素个数：path.size();
    还需要的元素个数为: k - path.size();
    在集合n中至多要从该起始位置 : n - (k - path.size()) + 1，开始遍历
    为什么有个+1呢，因为包括起始位置，我们要是一个左闭的集合。
    举个例子，n = 4，k = 3， 目前已经选取的元素为0（path.size为0），n - (k - 0) + 1 即 4 - ( 3 - 0) + 1 = 2。
    从2开始搜索都是合理的，可以是组合[2, 3, 4]。
*/
// 剪枝版：
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int n,int k,int startindex)
    {
        if(path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for(int i = startindex; i <= n-(k-path.size())+1; i++) // 从startindex开始搜索到n,但是实际当i大于一定的情况时，已经没有意义了
        {
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
    
    
};