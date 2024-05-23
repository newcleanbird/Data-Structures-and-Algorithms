/*
KMP 算法
C++实现
*/


#include <iostream>
#include <vector>
#include <string>

// 构建KMP算法的前缀函数（部分匹配表）
std::vector<int> buildPrefixFunction(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> prefixFunc(m, 0); // 初始化前缀函数数组
    int k = 0; // 前缀/后缀的长度

    for (int q = 1; q < m; ++q) {
        // 不匹配时，利用已知的部分匹配信息避免重新开始比较
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefixFunc[k - 1];
        }

        // 匹配时，延长前缀/后缀的长度
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefixFunc[q] = k;
    }

    return prefixFunc;
}

// KMP算法实现
int KMP(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> prefixFunc = buildPrefixFunction(pattern); // 获取前缀函数

    int q = 0; // 模式串中的位置
    for (int i = 0; i < n; ++i) {
        // 不匹配时，利用prefixFunc[q-1]找到新的起始比较位置
        while (q > 0 && text[i] != pattern[q]) {
            q = prefixFunc[q - 1];
        }

        // 匹配时，移动到下一个字符
        if (text[i] == pattern[q]) {
            q++;
        }

        // 当模式串完全匹配时，返回匹配的起始位置
        if (q == m) {
            return i - m + 1;
        }
    }

    return -1; // 未找到匹配
}

int main() {
    std::string text = "hello world, welcome to the world of programming";
    std::string pattern = "world";
    int index = KMP(text, pattern);
    if (index != -1) {
        std::cout << "Pattern found at index: " << index << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }
    return 0;
}