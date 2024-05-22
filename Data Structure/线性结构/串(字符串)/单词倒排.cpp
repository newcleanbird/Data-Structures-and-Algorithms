/*
HJ31 单词倒排
描述
对字符串中的所有单词进行倒排。

说明：

1、构成单词的字符只有26个大写或小写英文字母；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；

数据范围：字符串长度满足 1 \le n \le 10000 \1≤n≤10000 
输入描述：
输入一行，表示用来倒排的句子

输出描述：
输出句子的倒排结果

示例1
输入：
I am a student
复制
输出：
student a am I
复制
示例2
输入：
$bo*y gi!r#l
复制
输出：
l r gi y bo

*/



#include <iostream>
#include <string>

using namespace std;

void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
    int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
    for (int i = 0; i < s.size(); ++i) { //
        if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
            if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
            while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow); //slow的大小即为去除多余空格后的大小。
}

string reverseWords(string s) {
    removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
    reverse(s, 0, s.size() - 1);
    int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
            reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
            start = i + 1; //更新下一个单词的开始下标start
        }
    }
    return s;
}


int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s);

}
// 64 位输出请用 printf("%lld")