#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体
struct Node {
    int data;
    struct Node* next;
};

// 打印链表
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 在链表末尾插入节点
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// 在链表指定位置插入节点
void insertAt(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = *head;
    newNode->data = data;
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// 删除链表中第一个匹配的节点
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// 修改链表中第一个匹配的节点的值
void modifyNode(struct Node* head, int oldData, int newData) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return;
        }
        current = current->next;
    }
    printf("Node not found\n");
}

// 查找链表中第一个匹配的节点
struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 释放链表内存
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// 主函数
int main() {
    struct Node* head = NULL;

    // 在链表末尾插入节点
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    // 打印链表：1 2 3
    printList(head);

    // 在链表指定位置插入节点
    insertAt(&head, 4, 1);

    // 打印链表：1 4 2 3
    printList(head);

    // 删除链表中第一个匹配的节点
    deleteNode(&head, 2);

    // 打印链表：1 4 3
    printList(head);

    // 修改链表中第一个匹配的节点的值
    modifyNode(head, 4, 5);

    // 打印链表：1 5 3
    printList(head);

    // 查找链表中第一个匹配的节点
    struct Node* searchedNode = searchNode(head, 5);
    if (searchedNode != NULL) {
        printf("Node found: %d\n", searchedNode->data);
    } else {
        printf("Node not found\n");
    }

    // 释放链表内存
    freeList(&head);

    return 0;
}
