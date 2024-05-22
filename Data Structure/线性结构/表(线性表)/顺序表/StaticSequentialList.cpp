#include <iostream>
using namespace std;

#define MaxSize 10 // 静态顺序表的最大容量

// 顺序表结构体定义
struct SeqList {
    int data[MaxSize]; // 存储数据的数组
    int length;       // 当前顺序表的长度
};

// 初始化顺序表
void InitSeqList(SeqList& L) {
    L.length = 0; // 初始长度为0
}

// 判断顺序表是否为空
bool IsEmpty(SeqList L) {
    return L.length == 0;
}

// 向顺序表中插入元素，这里简单实现尾部插入，需要考虑溢出情况
bool Insert(SeqList& L, int pos, int val) {
    if (pos < 1 || pos > L.length + 1 || L.length >= MaxSize) {
        cout << "插入位置不合法或顺序表已满！" << endl;
        return false;
    }

    for (int i = L.length; i >= pos; i--) {
        L.data[i] = L.data[i - 1];
    }

    L.data[pos - 1] = val;
    L.length++;
    return true;
}

// 删除顺序表中的元素，这里实现删除指定位置的元素，需要考虑空表情况
bool Delete(SeqList& L, int pos) {
    if (pos < 1 || pos > L.length) {
        cout << "删除位置不合法！" << endl;
        return false;
    }

    for (int i = pos - 1; i < L.length - 1; i++) {
        L.data[i] = L.data[i + 1];
    }

    L.length--;
    return true;
}

// 查找元素在顺序表中的位置，返回位置或-1表示未找到
int Locate(SeqList L, int val) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == val) {
            return i + 1; // 返回位置加1以符合用户习惯
        }
    }
    return -1;
}

// 打印顺序表
void Print(SeqList L) {
    cout << "顺序表内容如下：" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SeqList L;
    InitSeqList(L);

    Insert(L, 1, 1); // 在表头插入
    Insert(L, 2, 2);
    Insert(L, 3, 3);

    Print(L); // 打印顺序表

    Delete(L, 2); // 删除第二个元素
    Print(L); // 再次打印

    int pos = Locate(L, 3);
    if (pos != -1) {
        cout << "元素3的位置是：" << pos << endl;
    }
    else {
        cout << "元素3不在表中。" << endl;
    }

    return 0;
}
