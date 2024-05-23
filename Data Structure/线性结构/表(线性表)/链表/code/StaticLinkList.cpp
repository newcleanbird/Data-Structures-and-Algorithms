/*
Static Link List
静态链表 C++实现
*/

#include<iostream>
using namespace std;

const int MaxSize = 100;

template<typename DataType>
struct SNode {
    DataType data;
    int next; // 类似于指针的下一个地址
};

template<typename DataType>
class StaticlinkList {
public:
    StaticlinkList();
    StaticlinkList(DataType a[], int n);
    ~StaticlinkList();
    int Length();
    DataType Get(int i);
    int Locate(DataType x);
    void Insert(int i, DataType x);
    DataType Delete(int i);
    bool Empty();
    void PrintList();
private:
    SNode<DataType> SList[MaxSize];
    int first, avail;
};

// 无参构造方法
template<typename DataType>
StaticlinkList<DataType>::StaticlinkList() {
    for (int i = 0; i < MaxSize; ++i) {
        SList[i].data = DataType(); // 初始化为默认值，对于内置类型是0
        SList[i].next = i + 1;
    }
    first = 0;
    SList[first].next = -1;
    SList[MaxSize - 1].next = -1;
    avail = 1; // 指向第一个可用的位置
}

// 自定义构造方法
template<typename DataType>
StaticlinkList<DataType>::StaticlinkList(DataType a[], int n) {
    for (int i = 0; i < MaxSize; ++i) {
        SList[i].data = DataType();
        SList[i].next = i + 1;
    }

    first = 0;
    SList[first].next = -1;
    SList[MaxSize - 1].next = -1;
    avail = 1;

    if (n > MaxSize) n = MaxSize; // 防止越界

    for (int i = 0; i < n; ++i) {
        Insert(i, a[i]);
    }
}

// 析构函数
template<typename DataType>
StaticlinkList<DataType>::~StaticlinkList() {}

// 获取链表长度
template<typename DataType>
int StaticlinkList<DataType>::Length() {
    int count = 0;
    int temp = first;
    while (SList[temp].next != -1) {
        temp = SList[temp].next;
        ++count;
    }
    return count;
}

// 获取查询位置的内容
template<typename DataType>
DataType StaticlinkList<DataType>::Get(int i) {
    if (i < 0 || i >= this->Length()) throw "位置信息异常";
    int temp = first;
    for (int j = 0; j < i; ++j)
        temp = SList[temp].next;
    return SList[temp].data;
}

// 获取第一个出现的位置
template<typename DataType>
int StaticlinkList<DataType>::Locate(DataType x) {
    int temp = first;
    for (int i = 0; i < Length(); ++i) {
        if (SList[temp].data == x)
            return i;
        temp = SList[temp].next;
    }
    return -1; // 如果没有找到，返回-1
}

// 插入一个内容
template<typename DataType>
void StaticlinkList<DataType>::Insert(int i, DataType x) {
    if (i < 0 || i > Length()) throw "插入位置信息异常";
    if (Length() == MaxSize) throw "链表已满";

    int s = avail;
    avail = SList[avail].next;
    SList[s].data = x;
    SList[s].next = -1; // 初始化next为-1，避免误用

    int temp = first;
    for (int j = 0; j < i; ++j)
        temp = SList[temp].next;

    SList[s].next = SList[temp].next;
    SList[temp].next = s;
}

// 删除一个内容
template<typename DataType>
DataType StaticlinkList<DataType>::Delete(int i) {
    if (i < 0 || i >= this->Length()) throw "删除位置信息异常";

    int temp = first;
    for (int j = 0; j < i; ++j)
        temp = SList[temp].next;

    int s = SList[temp].next;
    SList[temp].next = SList[s].next;
    DataType x = SList[s].data;
    SList[s].data = DataType(); // 清空数据
    SList[s].next = avail;
    avail = s;
    return x;
}

// 判断表是否为空
template<typename DataType>
bool StaticlinkList<DataType>::Empty() {
    return first == -1;
}

// 输出表中的内容
template<typename DataType>
void StaticlinkList<DataType>::PrintList() {
    int temp = first;
    while (SList[temp].next != -1) {
        cout << SList[temp].data << "\t";
        temp = SList[temp].next;
    }
    cout << endl;
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9 };
    StaticlinkList<int> sList(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "初始链表：" << endl;
    sList.PrintList();

    sList.Insert(2, 4); // 在位置2插入4
    cout << "插入4后的链表：" << endl;
    sList.PrintList();

    cout << "删除位置3的元素：" << sList.Delete(3) << endl;
    cout << "删除后的链表：" << endl;
    sList.PrintList();

    cout << "链表长度：" << sList.Length() << endl;

    return 0;
}