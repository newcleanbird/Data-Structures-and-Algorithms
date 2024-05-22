#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;      // 数据指针
    int length;     // 当前长度
    int capacity;   // 总容量
} SeqList;

// 初始化顺序表
void initSeqList(SeqList* list, int capacity) {
    list->data = (int*)malloc(capacity * sizeof(int));
    list->length = 0;
    list->capacity = capacity;
}

// 插入元素
void insert(SeqList* list, int value) {
    if (list->length == list->capacity) {
        printf("顺序表已满，无法插入元素！\n");
        return;
    }
    list->data[list->length++] = value;
}

// 打印顺序表中的元素
void printSeqList(SeqList* list) {
    printf("顺序表中的元素为：");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 释放顺序表内存
void freeSeqList(SeqList* list) {
    free(list->data);
    list->length = 0;
    list->capacity = 0;
}

int main() {
    SeqList list;
    initSeqList(&list, 5);

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 4);
    insert(&list, 5);

    printSeqList(&list);

    freeSeqList(&list);

    return 0;
}
