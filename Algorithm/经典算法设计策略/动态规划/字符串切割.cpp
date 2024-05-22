/*
描述
给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
例如:
给定s=“nowcode”；
dict=["now", "code"].
返回true，因为"nowcode"可以被分割成"now code".
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true; // 初始状态为true
        for(int i = 1; i <= s.size(); i++)
        {   // dp[i]:第i状态，s.substr(j,i-j):截取的从j到i的片段 判断子串是否在dict中，dict.find()
            for(int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && (dict.find(s.substr(j,i-j)) != dict.end())){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
        // if(dp[s.size()] == 1){
        //     return true;
        // }
        // else{
        //     return false;
        // }
    }
};

int main(){
    Solution result;
    string s = "nowcode";
    unordered_set<string> dict = {"now", "code"};
    cout << result.wordBreak(s, dict);
}