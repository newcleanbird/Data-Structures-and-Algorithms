/*
202. 快乐数
简单
1.2K
相关企业
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

 

示例 1：

输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
示例 2：

输入：n = 2
输出：false
 

提示：

1 <= n <= 231 - 1


*/

/*
    unordered_set:利用哈希表，进行查询是否重复。
*/
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int get_sum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> uset;
        while(1)
        {
            if(n == 1)
            {
                return true;
            }
            else if(uset.find(n) != uset.end()) // 说明重复过
            {
                return false;
            }
            else{
                uset.insert(n);
            }
            n = get_sum(n);
        }
    }
};