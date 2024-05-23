/*
循环双链表C语言实现
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define true 1
// #define false 0

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// 头部插入
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != *head) temp = temp->next;  // temp位移到最后的节点
        newNode->next = *head;
        newNode->prev = temp;
        (*head)->prev = newNode;
        temp->next = newNode;
        *head = newNode;
    }
}

// 尾部插入（重复代码，实际已包含在主代码中，这里仅做说明）
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) { // 如果链表为空，新节点既是头也是尾
        *head = newNode;
        newNode->next = newNode->prev = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != *head) { // 遍历到链表尾部
            temp = temp->next;
        }
        newNode->next = *head; // 新节点的下一个指向头节点
        newNode->prev = temp;  // 新节点的前一个指向当前尾节点
        temp->next = newNode;  // 当前尾节点的下一个指向新节点
        (*head)->prev = newNode; // 头节点的前一个指向新节点
    }
}


// 中间插入（假设按位置插入，位置从1开始计数）
void insertAtPosition(Node** head, int data, int position) {
    if (position <= 0) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 1; i < position && temp->next != *head; i++, temp = temp->next);
    if (temp->next == *head) { // 说明是尾部插入
        insertAtEnd(head, data);
    }
    else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// 查找节点，返回节点指针，未找到返回NULL
Node* searchNode(Node* head, int data) {
    if (head == NULL) return NULL;
    Node* temp = head;
    do {
        if (temp->data == data) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

// 计算链表长度
int getLength(Node* head) {
    if (head == NULL) return 0;
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 更新节点值
void updateNode(Node* node, int newData) {
    if (node != NULL) node->data = newData;
}

// 清空链表
void clearList(Node** head) {
    if (*head == NULL) return;
    Node* current = *head;
    do {
        Node* nextTemp = current->next;
        free(current);
        current = nextTemp;
    } while (current != *head);
    *head = NULL;
}

void reverseList(Node** head) {
    if (*head == NULL || (*head)->next == *head) return; // 空链表或只有一个节点不需要反转

    Node* current = *head;          // 当前访问节点
    Node* prev = current->prev;     // 存储之前的节点，请注意初始化

    do {
        Node* nextNode = current->next; // 保存下一个节点
        current->next = prev;           // 当前节点的next指向前一个节点
        prev = current;                 // prev前进到当前节点
        current = nextNode;             // current前进到下一个节点
    } while (current != *head); // 直到回到头节点

    // 反转结束后，prev指向了新的头节点（原链表的尾节点）
    // 由于是循环链表，无需特别调整(*head)，因为prev已经是新的头节点
    (*head) = prev;
}


// 安全打印循环双链表
void printList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == head) break; // 确保遍历到头节点时终止循环
    } while (true);
    printf("\n");
}

// 检查循环双链表指针是否设置正确
bool checkCircularDoublyLinkedList(Node* head) {
    if (head == NULL) return true; // 空链表视为有效

    Node* temp = head;
    int nodeCount = 0; // 用于统计节点数量，确保能遍历完所有节点

    // 正向遍历链表，检查每个节点的next和prev指针
    do {
        if (temp->next == NULL || temp->prev == NULL) {
            return false; // 如果任何一个指针为NULL，则链表设置不正确
        }
        temp = temp->next;
        nodeCount++;
    } while (temp != head);

    // 反向遍历
    do {
        if (temp->next == NULL || temp->prev == NULL) {
            return false; // 如果任何一个指针为NULL，则链表设置不正确
        }
        temp = temp->prev;
        nodeCount--;
    } while (temp != head);


    // 额外检查循环次数，确保所有节点都被访问过一次
    if (nodeCount != 0) return false; // 仅有一个或零个节点，不符合循环链表定义

    return true; // 所有检查通过，链表设置正确
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 0); // 头部插入
    insertAtEnd(&head, 1);      // 尾部插入
    insertAtPosition(&head, 2, 2); // 中间插入

    printf("循环双链表的内容:\n");
    printList(head);

    printf("替换节点\n");
    Node* foundNode = searchNode(head, 2);
    if (foundNode) {
        printf("找到节点，值为: %d\n", foundNode->data);
        updateNode(foundNode, 99); // 更新节点值
    }
    printList(head);
    printf("链表长度: %d\n", getLength(head));
    printf("\n");

    printf("反转前的链表内容:\n");
    printList(head);
    reverseList(&head); // 反转链表
    printf("反转后的链表内容:\n");

    if (checkCircularDoublyLinkedList(head)) printf("检查无误\n");
    else printf("有错误!!!\n");

    printList(head);
    printf("\n");

    clearList(&head); // 清空链表
    //printList(head);  // 打印确认链表已清空
    printf("情况列表后，当前长度为：%d", getLength(head));

    return 0;
}