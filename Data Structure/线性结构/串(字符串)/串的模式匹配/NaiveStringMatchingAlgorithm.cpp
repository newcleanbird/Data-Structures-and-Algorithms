/*
naive string-matching algorithm
朴素字符串匹配算法
*/

#include <iostream>
#include <string>

int bruteForceSearch(const std::string& haystack, const std::string& needle) {
    // 获取文本串和模式串的长度
    int n = haystack.length();
    int m = needle.length();

    // 如果模式串比文本串长，则不可能找到匹配
    if (m > n) return -1;

    // 主循环：遍历文本串的每一个可能的起始位置
    for (int i = 0; i <= n - m; ++i) {
        // 副循环：比较当前位置i开始的m个字符是否与模式串匹配
        bool match = true;
        for (int j = 0; j < m; ++j) {
            if (haystack[i + j] != needle[j]) {
                match = false;
                break;
            }
        }
        // 如果匹配成功，返回模式串在文本串中的起始位置
        if (match) return i;
    }

    // 如果没有找到匹配，返回-1或其他约定的失败指示符
    return -1;
}

int main() {
    std::string text = "Hello, this is a simple pattern matching example.";
    std::string pattern = "pattern";
    int index = bruteForceSearch(text, pattern);

    if (index != -1) {
        std::cout << "Pattern found at index: " << index << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }

    return 0;
}