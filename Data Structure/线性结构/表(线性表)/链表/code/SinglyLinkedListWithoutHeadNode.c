/*
Singly Linked List without Head Node 
C实现的单链表(不带头节点)
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;

// 头节点定义
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;

// 创建新节点
LNode* createNode(ElemType value) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

////在第i个位置插入元素e（带头结点）
//bool ListInsert(LinkList& L, int i, ElemType e) {
//    if (i < 1)
//        return false;
//
//    //插入到第1个位置时的操作有所不同！
//    if (i == 1) {
//        LNode* s = (LNode*)malloc(sizeof(LNode));
//        s->data = e;
//        s->next = L;
//        L = s;          //头指针指向新结点
//        return true;
//    }
//
//    //i>1的情况与带头结点一样！唯一区别是j的初始值为1
//    LNode* p;       //指针p指向当前扫描到的结点 
//    int j = 1;        //当前p指向的是第几个结点
//    p = L;          //L指向头结点，头结点是第0个结点（不存数据）
//
//    //循环找到第i-1个结点
//    while (p != NULL && j < i - 1) {     //如果i>lengh, p最后会等于NULL
//        p = p->next;             //p指向下一个结点
//        j++;
//    }
//
//    if (p == NULL)                 //i值不合法
//        return false;
//
//    //在第i-1个结点后插入新结点
//    LNode* s = (LNode*)malloc(sizeof(LNode)); //申请一个结点
//    s->data = e;
//    s->next = p->next;
//    p->next = s;
//    return true;
//}

// 指定结点的后插操作
bool InsertNextNode(LNode* p, ElemType e) {
    if (p == NULL) {
        return false;
    }

    LNode* s = (LNode*)malloc(sizeof(LNode));   // 可以改进为createNode()版本
    //某些情况下分配失败，比如内存不足
    if (s == NULL)
        return false;
    s->data = e;          //用结点s保存数据元素e 
    s->next = p->next;
    p->next = s;          //将结点s连到p之后

    return true;
}                         //平均时间复杂度 = O(1)

// 在第i个位置插入元素e(结合后插操作)
bool ListInsert(LinkList* L, int i, ElemType e) {
    if (i < 1)
        return false;

    LNode* p;       //指针p指向当前扫描到的结点 
    int j = 0;      //当前p指向的是第几个结点
    p = *L;          //L指向头结点，头结点是第0个结点（不存数据）

    //循环找到第i-1个结点
    while (p != NULL && j < i - 1) {     //如果i>lengh, p最后4鸟会等于NULL
        p = p->next;             //p指向下一个结点
        j++;
    }

    return InsertNextNode(p, e);
}

// 前插操作：在p结点之前插入元素e
// 思想：实际上还是后插，将原节点的值替换为新值，新值替换为旧值。
bool InsertPriorNode(LNode* p, ElemType e) {
    if (p == NULL)
        return false;

    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) //内存分配失败
        return false;

    //重点来了！
    s->next = p->next;
    p->next = s;       //新结点s连到p之后
    s->data = p->data; //将p中元素复制到s
    p->data = e;       //p中元素覆盖为e

    return true;
}  //时间复杂度为O(1)

// 删除链表中下标为i的节点，并将删除节点的值通过e指针返回
bool ListDelete(LNode** L, int i, ElemType* e) {
    // 参数检查：i值不合法则直接返回false
    if (i < 1) return false;

    LNode* p = *L; // 初始化p为头节点指针
    int j = 0;     // 当前节点位置计数

    // 寻找第i-1个节点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    // 检查i值是否有效
    if (p == NULL || p->next == NULL) {
        return false; // i值超出链表范围
    }

    LNode* q = p->next; // q指向待删除的节点
    *e = q->data;       // 通过指针e返回删除节点的值
    p->next = q->next;  // 删除q节点
    free(q);            // 释放q节点内存

    return true; // 删除成功
}


// 指定结点的删除
bool DeleteNode(LNode* p) {
    if (p == NULL)
        return false;

    LNode* q = p->next;      //令q指向*p的后继结点
    p->data = p->next->data; //让p和后继结点交换数据域
    p->next = q->next;       //将*q结点从链中“断开”
    free(q);
    return true;
} //时间复杂度 = O(1)

// 按位查找
LNode* GetElem(LinkList L, int i) {
    if (i < 0) return NULL;

    LNode* p;               //指针p指向当前扫描到的结点
    int j = 0;                //当前p指向的是第几个结点
    p = L;                  //L指向头结点,头结点是第0个结点(不存数据)
    while (p != NULL && j < i) {  //循环找到第i个结点
        p = p->next;
        j++;
    }

    return p;               //返回p指针指向的值
}

// 按值查找
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;    //p指向第一个结点
    //从第一个结点开始查找数据域为e的结点
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;           //找到后返回该结点指针，否则返回NULL
}

// 求单链表的长度
int Length(LinkList L) {
    int len = 0;       //统计表长
    LNode* p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

//// 头插法建立单链表
//LinkList List_HeadInsert(LinkList& L) {     //逆向建立单链表
//    LNode* s;
//    int x;
//    L = (LinkList)malloc(sizeof(LNode));    //建立头结点
//    L->next = NULL;                         //初始为空链表,这步不能少！
//
//    scanf("%d", &x);                        //输入要插入的结点的值
//    while (x != 9999) {                     //输入9999表结束
//        s = (LNode*)malloc(sizeof(LNode));  //创建新结点
//        s->data = x;
//        s->next = L->next;
//        L->next = s;                        //将新结点插入表中，L为头指针
//        scanf("%d", &x);
//    }
//    return L;
//}
//
//// 尾插法建立单链表
//LinkList List_TailInsert(LinkList& L) {      //正向建立单链表
//    int x;                                   //设ElemType为整型int
//    L = (LinkList)malloc(sizeof(LNode));     //建立头结点(初始化空表)
//    LNode* s, * r = L;                       //r为表尾指针
//    scanf("%d", &x);                         //输入要插入的结点的值
//    while (x != 9999) {                      //输入9999表结束
//        s = (LNode*)malloc(sizeof(LNode));
//        s->data = x;
//        r->next = s;
//        r = s;                               //r指针指向新的表尾结点
//        scanf("%d", &x);
//    }
//    r->next = NULL;                          //尾结点指针置空
//    return L;
//}

// 链表的逆置
LNode* Inverse(LNode* L)
{
    LNode* p, * q;
    p = L->next;     //p指针指向第一个结点
    L->next = NULL;  //头结点指向NULL

    while (p != NULL) {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
    return L;
}

// 打印链表
void printList(LNode* head) {
    LNode* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 释放链表
void freeList(LNode* head) {
    LNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    LNode* head = createNode(0);
    InsertNextNode(head, 1);
    InsertNextNode(head, 2);
    InsertNextNode(head, 3);

    printList(head);
    freeList(head);
    return 0;

}