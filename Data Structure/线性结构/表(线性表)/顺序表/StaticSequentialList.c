#include <stdio.h>

#define MaxSize 10   //定义表的最大长度 

// 顺序表结构体定义
typedef struct {
    int data[MaxSize];  // 用静态的"数组"存放数据元素
    int length;         // 顺序表的当前长度
} StaticSequentialList;               // 顺序表的类型定义（静态分配方式）

// 初始化顺序表
void InitList(StaticSequentialList& L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;  //将所有数据元素设置为默认初始值  
    }
    L.length = 0;   // 初始化当前表长为0
}

// 插入操作，在第i个位置插入e
bool ListInsert(StaticSequentialList& L, int i, int e) {
    //判断i的范围是否有效
    if (i < 0 || i > L.length)
        return false;
    if (L.length >= MaxSize) //当前存储空间已满，不能插入(理论上等于就可以)
        return false;

    for (int j = L.length - 1; j >= i+1; j--) {    //将第i个元素及其之后的元素后移
        L.data[j] = L.data[j - 1];  // 以赋值的形式，由后往前，将前一个元素移到后一个位置上
    }
    L.data[i] = e;      //在位置i处放入e
    L.length++;         //长度加1
    return true;
}

// 删除操作，删除第i个位置的元素，并用e返回其值
bool LisDelete(StaticSequentialList& L, int i, int& e) { // e用引用型参数 
    //判断i的范围是否有效
    if (i < 0 || i >= L.length)
        return false;

    e = L.data[i];    //将被删除的元素赋值给e

    for (int j = i; j < L.length - 1; j++) {    //将第i个后的元素前移
        L.data[j] = L.data[j+1];    // 依次从删除点从前往后以赋值的形式移动元素。
    }
    L.length--;      //长度减1
    return true;
}

// 判断顺序表是否为空
int IsEmpty(StaticSequentialList L) {
    return L.length == 0;
}

// 求表长
int Length(StaticSequentialList L) {
    return L.length;
}

// 按位查找操作，返回第i个元素的值
int GetElem(StaticSequentialList L, int i) {
    if (i >= 0 && i < L.length)
        return L.data[i];
    else
        return -1; // 或者其他错误代码表示位置不合法
}

// 按值查找操作，返回第一个与e相等的元素的位置，找不到返回-1
int LocateElem(StaticSequentialList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i;
    }
    return -1;
}

// 输出顺序表所有元素
void PrintList(StaticSequentialList L) {
    printf("Sequence List: \n");
    for (int i = 0; i < L.length; i++)
        printf("第%d个元素是:%d \n", i, L.data[i]);
    printf("\n");
}

// 销毁操作，这里因为是静态分配，不真正释放内存，但可以清空表
void DestroyList(StaticSequentialList& L) {
    L.length = 0; // 清空顺序表，实际内存不释放
}

int main() {
    StaticSequentialList L;
    InitList(L); // 初始化顺序表

    // 查询表长
    printf("当前表长为：%d \n", Length(L));

    // 为了测试，直接从0开始插满整个顺序表
    for (int i = 0; i < MaxSize; i++)
    {
        ListInsert(L, i, i+1);
    }
    PrintList(L);
    // 查询表长
    printf("当前表长为：%d \n", Length(L));


    // 再随机增加一个元素
    if (!ListInsert(L, 9, 11))
    {
        printf("插入失败 \n");
    }
    else {
        printf("插入成功 \n");
    }
    // 删除两个元素
    int e;
    if (!LisDelete(L, 0, e))
    {
        printf("删除失败 \n");
    }
    else {
        printf("删除成功，删除的元素为：%d \n", e);
    }

    // 查询表长
    printf("当前表长为：%d \n", Length(L));

    // 再插入元素
    if (!ListInsert(L, 9, 11))
    {
        printf("插入失败 \n");
    }
    else {
        printf("插入成功 \n");
    }

    // 查询表长
    printf("当前表长为：%d \n", Length(L));

    PrintList(L);

    return 0;
}