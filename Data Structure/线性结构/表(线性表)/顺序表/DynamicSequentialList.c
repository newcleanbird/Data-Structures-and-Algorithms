#include <stdio.h>
#include <stdlib.h> // 用于malloc和free

#define ElemType int
#define InitSize 100

// 动态顺序表结构体定义
typedef struct {
    void* data;          // 指针，指向动态分配的数组首地址，使用void*以支持不同数据类型
    int MaxSize;         // 最大长度
    int length;          // 当前长度
} SeqList;               // 动态分配数组顺序表的类型定义

// 初始化顺序表
void InitList(SeqList* L) {
    L->data = malloc(InitSize * sizeof(ElemType)); // 分配初始空间
    if (!L->data) {
        exit(EXIT_FAILURE); // 内存分配失败处理
    }
    L->MaxSize = InitSize;
    L->length = 0;
}

// 判断顺序表是否为空
int IsEmpty(SeqList L) {
    return L.length == 0;
}

// 求表长
int Length(SeqList L) {
    return L.length;
}

// 按值查找操作，返回第一个与e相等的元素的位置，找不到返回-1
int LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (*((ElemType*)L.data + i) == e) // 类型转换，访问元素
            return i;
    }
    return -1;
}

// 按位查找操作，返回第i个元素的值
ElemType GetElem(SeqList L, int i) {
    if (i >= 0 && i < L.length)
        return *((ElemType*)L.data + i); // 类型转换，访问元素
    else
        return (ElemType)-1; // 或者其他错误代码表示位置不合法
}

// 扩容操作
void IncreaseSize(SeqList* L) {
    L->MaxSize *= 2; // 扩容策略：原大小翻倍
    L->data = realloc(L->data, L->MaxSize * sizeof(ElemType));
    if (!L->data) {
        exit(EXIT_FAILURE); // 内存重分配失败处理
    }
}

// 插入操作，在第i个位置插入e
int Insert(SeqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return 0; // 插入位置不合法
    }
    if (L->length >= L->MaxSize) {
        IncreaseSize(L); // 如果需要，先扩容
    }
    for (int j = L->length; j >= i; j--) {
        *((ElemType*)L->data + j) = *((ElemType*)L->data + j - 1);
    }
    *((ElemType*)L->data + i - 1) = e;
    L->length++;
    return 1;
}

// 删除操作，删除第i个位置的元素，并用e返回其值
int Delete(SeqList* L, int i, ElemType* e) {
    if (i < 1 || i > L->length) {
        return 0; // 删除位置不合法
    }
    *e = *((ElemType*)L->data + i - 1);
    for (int j = i; j < L->length; j++) {
        *((ElemType*)L->data + j - 1) = *((ElemType*)L->data + j);
    }
    L->length--;
    return 1;
}

// 输出顺序表所有元素
void PrintList(SeqList L) {
    printf("动态顺序表的全部元素: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", *((int*)L.data + i)); // 假设ElemType为int，仅作示例
    }
    printf("\n");
}

// 销毁操作，释放动态分配的内存
void DestroyList(SeqList* L) {
    free(L->data);
    L->data = NULL;
    L->MaxSize = 0;
    L->length = 0;
}

int main() {
    SeqList* L = new SeqList;
    InitList(L); // 初始化顺序表

    PrintList(*L);
    // 插入
    if (!Insert(L, 1, 1))
    {
        printf("插入失败 \n");
    }
    else {
        printf("插入成功 \n");
    }
    PrintList(*L);

    DestroyList(L); // 使用完毕，释放内存
    return 0;
}

