/*
Horspool
*/

#include <cstdio>
#include <cstring>

#include <iostream>
#include <string>
#include <vector>

std::vector<int> horspoolSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> indexes;
    int pattLen = pattern.length();
    int textLen = text.length();

    if (pattLen == 0 || pattLen > textLen) return indexes;

    // 构建跳跃表
    std::vector<int> shiftTable(256, pattLen); // 初始化所有字符的跳跃位移为模式串长度
    for (int i = 0; i < pattLen - 1; ++i)
        shiftTable[pattern[i]] = pattLen - 1 - i; // 更新表中字符的跳跃位移

    int idx = 0; // 文本串中的搜索起点
    while (idx <= textLen - pattLen) {
        int j;
        for (j = pattLen - 1; j >= 0 && pattern[j] == text[idx + j]; --j) {}

        if (j < 0) { // 匹配成功
            indexes.push_back(idx);
            idx++; // 移动到下一个可能的起始位置，避免重复匹配
        }
        else {
            // 不匹配，根据字符在模式串中的位置跳转
            idx += shiftTable[text[idx + pattLen - 1]];
        }
    }

    return indexes;
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    std::vector<int> matchIndexes = horspoolSearch(text, pattern);

    if (!matchIndexes.empty()) {
        std::cout << "Pattern found at positions: ";
        for (int index : matchIndexes)
            std::cout << index << " ";
        std::cout << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }

    return 0;
}