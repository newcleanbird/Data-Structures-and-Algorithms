/*349. 两个数组的交集
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/

/*
使用哈希表的思路：
    将num1放入unordered_set中，因为元素是唯一的，且为了查询迅速，因此选用底层是哈希表的unordered_set存放数据。
    然后对num2中的元素依次在哈希表中寻找，如果符合，则加入新的unordered_set中，最后输出unordered_set即可。


*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1(nums1.begin(), nums1.end());
        unordered_set<int> uset2;
        for(auto i : nums2)
        {
            if(uset1.find(i) != uset1.end())
            {
                uset2.insert(i);
            }
        }
    vector<int> res(uset2.begin(), uset2.end());
        return res;
    }
};