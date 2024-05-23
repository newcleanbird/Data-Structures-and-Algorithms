#pragma once
// 带头+双向+循环链表增删查改实现
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
} ListNode;

// 双链表申请一个新节点
ListNode* BuyListNode(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		perror("BuyListNode::malloc");
		exit(EXIT_FAILURE); // 更改为exit以确保程序终止
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// 创建返回链表的头结点
ListNode* ListCreate() {
	ListNode* head = BuyListNode(-1);
	head->next = head;
	head->prev = head;
	return head;
}

// 双向链表打印
void ListPrint(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->next;
	printf("head<=>");
	while (cur != pHead) {
		printf("%d", cur->data);
		if (cur->next != pHead) printf("=>");
		cur = cur->next;
	}
	printf("\n");
	return;
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = pHead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;
	return;
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	if (tail == pHead)
		return;
	tail->prev->next = pHead;
	pHead->prev = tail->prev;
	free(tail);
	tail = NULL;
	return;
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	newnode->next = pHead->next;
	pHead->next->prev = newnode;
	pHead->next = newnode;
	newnode->prev = pHead;
	return;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* tmp = pHead->next;
	if (tmp == pHead)
		return;
	tmp->next->prev = pHead;
	pHead->next = tmp->next;
	free(tmp);
	tmp = NULL;
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead;
	while (cur->data != x)
	{
		cur = cur->next;
		if (cur == pHead)
			return NULL;
	}
	return cur;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	pos->prev = newnode;
	newnode->next = pos;
	return;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
	return;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(pHead);
	return;
}

int main() {
	ListNode* head = ListCreate();

	// 测试尾部插入
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	printf("After PushBack: ");
	ListPrint(head);

	// 测试头部插入
	ListPushFront(head, 0);
	printf("After PushFront: ");
	ListPrint(head);

	// 查找元素
	ListNode* found = ListFind(head, 2);
	assert(found != NULL && found->data == 2);
	printf("Found element 2.\n");

	// 在2后面插入4
	ListInsert(found, 4);
	printf("After Insert 4 after 2: ");
	ListPrint(head);

	// 删除4
	ListErase(found->next);
	printf("After Erase 4: ");
	ListPrint(head);

	// 删除头部元素
	ListPopFront(head);
	printf("After PopFront: ");
	ListPrint(head);

	// 删除尾部元素
	ListPopBack(head);
	printf("After PopBack: ");
	ListPrint(head);

	// 销毁链表
	ListDestory(head);

	return 0;
}
