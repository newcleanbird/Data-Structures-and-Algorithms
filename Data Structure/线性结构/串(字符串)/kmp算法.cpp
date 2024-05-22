/*
什么是KMP
    因为是由这三位学者发明的：Knuth，Morris和Pratt，所以取了三位学者名字的首字母。所以叫做KMP
KMP有什么用
    KMP主要应用在字符串匹配上。
    KMP的主要思想是当出现字符串不匹配时，可以知道一部分之前已经匹配的文本内容，可以利用这些信息避免从头再去做匹配了。
    所以如何记录已经匹配的文本内容，是KMP的重点，也是next数组肩负的重任。

KMP算法：在文本串中匹配模式串
文本串：aabaabaaf   长度o
模式串：aabaaf      长度m

暴力匹配：O(o*m)

KMP算法：
    思想：从不匹配的点向前，求最长相等前后缀，然后从最长前缀处开始继续匹配
    前缀：包含首字母，不包含尾字母的所有子串    a aa aab aaba aabaa
    后缀：不包含首字母，包含尾字母的所有子串    f af aaf baaf abaaf
    前缀表：前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。
            a a b a a f
            0 1 0 1 2 0
    {
        前缀表：
        模式串：aabaaf
        a       0
        aa      1
        aab     0
        aaba    1
        aabaa   2
    }
    求最长相等前后缀(公共前后缀) :
        当不匹配时，往前跳到前缀的后面，下标，长度=前缀表的值=相等前后缀的长度
    next数组(可能会对prefix进行调整)告诉要回退到哪里    (prefix前缀表)
    {
        一般有三种实现：
        prefix前缀表：0 1  0 1 2  0
        整体右移：   -1 0  1 0 1  2
        整体减一     -1 0 -1 0 1 -1
    }

实现：
    求前缀表：
    函数原型：
        void getNext(int* next, const string& s)
    步骤：
    (1)初始化
    (2)处理前后缀不相同的情况
    (3)处理前后缀相同的情况
    (4)next
    i:后缀末尾  j:前缀末尾(代表i包括i之前的子串的最长相等前后缀的长度)
    {
        void getNext(int* next, const string &s)
        {
            // 初始化：
            int j = 0;
            next[0] = 0;
            for(int i = 1; i < s.size(); i++)
            {
                // 前后缀不同的情况
                while(j > 0 && s[i] != s[j]){ // 冲突
                    j = next[j-1]; // 看前一位的next值进行回退
                }
                // 前后缀相同的情况
                if(s[i] == s[j])
                {
                    j++; // 相等，则最长相等前后缀+1， 此时i 和 j匹配上了
                    // next更新
                    next[i] = j; // 更新next数组的值
                    // i在循环里，会自动递增
                }
            }
        }
    }


*/

/*
前缀表（不减一）C++实现
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};



*/

/*
前缀表统一减一 C++代码实现
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j]; // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};


*/