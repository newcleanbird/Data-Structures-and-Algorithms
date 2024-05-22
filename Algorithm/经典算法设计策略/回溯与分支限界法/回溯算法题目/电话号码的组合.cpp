/*
17. 电话号码的字母组合
中等
2.4K
相关企业
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]

提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
*/

/*
思路：
    题目要求：
        输入:2~9的字符串序列，
        返回：字母组合
        树的深度：字符串序列的长度，比如输入23,就是先在2里选一个，再在3里选一个。
        数的宽度：集合元素：每个数字代表3个元素

*/
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> result;
    string path;
    string phone[10] = {    // 数字->字符串
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz" 
        }; 
    void backtracking(string digits, int index)
    {
        if(path.size() == digits.size()) // 长度符合
        {
            result.push_back(path);
            return;
        }
        int digit = digits[index] - '0'; // 取当前数字
        string letters = phone[digit]; // 数字对应的取字符串
        for(int i = 0; i < letters.size(); i++)
        {
            path.push_back(letters[i]);
            backtracking(digits, index+1); // 在下一个字符串里继续排列
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        path.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};