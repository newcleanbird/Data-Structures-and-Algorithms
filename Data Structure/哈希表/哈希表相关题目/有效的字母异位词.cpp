/*
Leetcode：242.有效的字母异位词

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
 
提示:
1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母
 
进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

*/
/*
哈希表在本体的作用：
    定义一个长度为26的哈希表(数组)，将目标字符串中所有的字符放入哈希表中，记录其数量。
    再将要判断的字符串在表中查找，如果数量一致，则是字母异位词。

    哈希表就是能够很快查询。


*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26);
        for(auto i : s)
        {
            arr[i-'a']++;
        }
        for(auto i : t)
        {
            arr[i-'a']--;
        }
        for(auto i : arr)
        {
            if(i != 0)
            {
                return false;
            }
        }
        return true;
    }
};