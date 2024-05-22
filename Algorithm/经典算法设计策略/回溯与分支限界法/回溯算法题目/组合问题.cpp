/*
暴力解法：有多少个数就需要多少层for循环，因此需要回溯算法
回溯算法：其实回溯算法是通过递归控制有多少层for循环，递归里每一层就是一层for循环，下一层递归就是另一层for循环。集合大小为几，就嵌套多少层for循环
    回溯三部曲：
        确定递归函数的参数以及返回值
        确定递归的终止条件
        确定单层搜索(递归)的逻辑
*/

/*
确定递归函数的参数以及返回值
    递归函数：void backtracking(n, k)n:集合的数 k:集合的大小 startindex:要搜索的起始位置
    一维数组path:收集路径，即解
    二维数组result：存放多个一维数组path，是最终的结果集
确定递归的终止条件

void backtracking(n, k)
{
    if(path.size() == k)    一个解中元素已达要求(比如组合问题中，已经有4个数)
    { 
        result.push_back(path); // 收集
        return 
    }
    //确定单层搜索(递归)的逻辑
    for(i = startindex; i <= n; i++) // 单层搜索
    {
        path.push(i);
        backtarcking(n, k, i+1);
        // 回溯过程
        path.pop(); // 回溯到上一层，将拿到的排除，才能在原本位置上加入新集合里的元素，达成不用的排列。

    }
}

*/