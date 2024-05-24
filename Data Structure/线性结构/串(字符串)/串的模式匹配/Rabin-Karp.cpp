/*
Rabin-Karp
C++实现
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 计算哈希值的函数，这里使用一个简单的哈希函数作为示例
unsigned long long hashFunction(const string& s, int prime = 101, int mod = 1e9 + 9) {
    unsigned long long hashValue = 0;
    for (char c : s) {
        hashValue = (hashValue * prime + c) % mod;
    }
    return hashValue;
}

vector<int> rabinKarp(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();
    if (m > n) return result; // 如果模式串比文本串长，直接返回空结果

    // 计算模式串的哈希值和文本串第一个窗口的哈希值
    unsigned long long patternHash = hashFunction(pattern);
    unsigned long long windowHash = hashFunction(text.substr(0, m));

    // 预计算用于滚动哈希的prime^(m-1) % mod
    unsigned long long primePower = 1;
    for (int i = 1; i < m; ++i) {
        primePower = (primePower * 101) % 1000000007;
    }

    // 主循环：滑动窗口
    for (int i = 0; i <= n - m; ++i) {
        // 如果当前窗口的哈希值与模式串哈希值相同，则进行字符级比较
        if (windowHash == patternHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) result.push_back(i); // 确认匹配，添加索引
        }

        // 滚动哈希：移除左侧字符影响，添加右侧新字符影响
        if (i < n - m) {
            windowHash = ((windowHash - (text[i] * primePower) % 1000000007 + 1000000007) % 1000000007 * 101 + text[i + m]) % 1000000007;
        }
    }

    return result;
}

int main() {
    string text = "abracadabra";
    string pattern = "abra";
    vector<int> indices = rabinKarp(text, pattern);

    if (!indices.empty()) {
        cout << "Pattern found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    }
    else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}