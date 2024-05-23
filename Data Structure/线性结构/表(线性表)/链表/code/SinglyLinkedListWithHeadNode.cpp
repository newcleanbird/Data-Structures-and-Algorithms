/*
Singly Linked List with Head Node 
C++实现的单链表(带头节点)
*/

#include<bits/stdc++.h>

using namespace std;

/* 定义单链表的节点 */
// class LinkNode
class Node
{
public:
    int data;  // 节点的值
    Node* next;  // 后继指针
    Node() // 默认构造函数
    {
        this->data = 0;   // 初始化节点值为0
        this->next = nullptr; // 后继指针为空
    }
    Node(int val) // 构造函数，初始化结点的data和指针域
    {
        this->data = val;
        this->next = nullptr;
    }
    void printNode() // 成员函数，打印该结点的数据
    {
        std::cout << data << std::endl;
    }
};

// 定义单链表
class List
{
private:
    Node* m_pList;  // 链表头结点指针
    int m_iLength;  // 链表长度

public:
    List();
    ~List();
    void ClearList();                                    // 清空整个链表
    bool ListEmpty();                                    // 判断链表是否为空
    bool ListInsertHead(Node* pNode);                    // 头部插入一个节点
    bool ListInsertTail(Node* pNode);                    // 尾部插入一个节点
    bool ListInsert(int i, Node* pNode);                 // 从任意位置插入节点
    bool ListDelete(int i, Node* pNode);                 // 从任意位置删除结点
    bool ListGetElem(int i, Node* pNode);                // 查找第i个元素
    int  LocateElem(Node* pNode);                        // 查找结点的位序
    bool PriorElem(Node* pCurrentNode, Node* pPreNode);  // 找指针的前驱指针
    bool NextElem(Node* pCurrentNode, Node* pNextNode);  // 找指针的后继指针
    void ListTraverse();                                 // 链表的遍历
};

// #include "List.h" 

List::List()    // 默认构造函数
{
    m_pList = new Node;
    m_pList->data = 0;
    m_pList->next = NULL;
    m_iLength = 0;
}

void List::ClearList()  // 清空整个链表
{
    Node* currentNode = m_pList->next; // 声明一个指针，指向头指针后第一个元素
    while (currentNode != NULL)
    {
        Node* temp = currentNode->next; // 声明一个临时结点指针，指向下一个结点
        delete currentNode;             // 释放原结点
        currentNode = temp;             // 将临时指针赋值给原指针，指向下一个结点
    }
    m_pList->next = NULL;               // 头指针下一个为空

}

bool List::ListEmpty()  // 判断链表是否为空 
{
    if (m_iLength == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

List::~List()
{
    ClearList();    // 清空整个链表
    delete m_pList; // 清除头指针
    m_pList = NULL; // 头指针设置为NULL
}

bool List::ListInsertHead(Node* pNode)      // 头部插入一个节点
{
    Node* temp = m_pList->next;             // 头节点后第一个元素
    Node* newNode = new Node;               // 创建一个新的节点
    if (newNode == NULL)
        return false;
    newNode->data = pNode->data;    // 数据赋给新结点
    m_pList->next = newNode;        // 头结点指向新结点
    newNode->next = temp;           // 新结点的指针指向下一个结点
    m_iLength++;                    // 更新链表长度
    return true;
}

bool List::ListInsertTail(Node* pNode)  // 尾部插入一个节点
{
    Node* currentNode = m_pList;
    while (currentNode->next != NULL)
        currentNode = currentNode->next;   // 遍历到尾结点
    Node* newNode = new Node;       // 创建一个新的节点
    if (newNode == NULL)
        return false;
    newNode->data = pNode->data;    // 数据赋给新结点
    newNode->next = NULL;           // 新结点的指针设置为NULL   
    currentNode->next = newNode;    // 原最后一个结点的指针指向新节点
    m_iLength++;                    // 更新链表长度
    return true;
}

bool List::ListInsert(int i, Node* pNode)   // 从任意位置插入节点
{
    if (i<0 || i>m_iLength)                 // 判断插入点是否合理 
        return false;
    Node* currentNode = m_pList;            // 从头结点处新建指针
    for (int k = 0; k < i; k++)             // 一直遍历到插入处的前一个结点
    {
        currentNode = currentNode->next;
    }

    Node* newNode = new Node;               // 新建一个结点
    if (newNode == NULL)
        return false;
    newNode->data = pNode->data;            // 数据赋给新结点
    newNode->next = currentNode->next;      // 新结点指针指向指向插入位置的结点
    currentNode->next = newNode;            // 上一个结点指针指向新结点
    m_iLength++;                            // 更新长度
    return true;

}

bool List::ListDelete(int i, Node* pNode)   // 从任意位置删除结点
{
    if (i < 0 || i >m_iLength)
        return false;
    Node* currentNode = m_pList;
    Node* currentNodeBefore = NULL;
    for (int k = 0; k <= i; k++)
    {
        currentNodeBefore = currentNode;    // 一路遍历，指向删除前的结点
        currentNode = currentNode->next;    // 一路遍历，指向删除的结点
    }
    currentNodeBefore->next = currentNode->next;    // 将删除结点的指针赋给前一个结点 即，让上一个结点跨过删除结点，指向下一个结点
    pNode->data = currentNode->data;                // 把删除结点的数据拷贝给形参结点指针指向的数据域
    delete currentNode;                             // 释放该结点(内存空间)
    currentNode = NULL;                             // 该指针设为空指针(防止野指针引起不安全的访问)
    m_iLength--;
    return true;
}

bool List::ListGetElem(int i, Node* pNode)
{
    if (i < 0 || i >m_iLength)
        return false;
    Node* currentNode = m_pList;
    for (int k = 0; k <= i; k++)
    {
        currentNode = currentNode->next;
    }
    pNode->data = currentNode->data;
    return true;
}

int List::LocateElem(Node* pNode)
{
    Node* currentNode = m_pList;
    int count = 0;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        if (currentNode->data == pNode->data)
        {
            return count;
        }
        count++;
    }
    return -1;
}

bool List::PriorElem(Node* pCurrentNode, Node* pPreNode)
{
    Node* currentNode = m_pList;
    Node* tempNode = NULL;
    while (currentNode->next != NULL)
    {
        tempNode = currentNode;
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data)
        {
            if (tempNode == m_pList)
                return false;
            else
            {
                pPreNode->data = tempNode->data;
                return true;
            }

        }
    }
    return false;
}

bool List::NextElem(Node* pCurrentNode, Node* pNextNode)
{
    Node* currentNode = m_pList;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data)
        {
            if (currentNode->next == NULL)
            {
                return false;
            }
            else
            {
                pNextNode->data = currentNode->next->data;
                return true;
            }

        }
    }
    return false;
}

void List::ListTraverse()
{
    Node* currentNode = m_pList;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        currentNode->printNode();
    }

}

/* 测试.cpp */

// #include "List.h"
// #include<iostream>
// using namespace std;

int main()
{
    Node node1;
    node1.data = 3;
    Node node2;
    node2.data = 4;
    Node node3;
    node3.data = 5;
    Node node4;
    node4.data = 6;

    Node node5;
    node5.data = 7;

    Node temp;

    List* pList = new List();
    pList->ListInsertTail(&node1);
    pList->ListInsertTail(&node2);
    pList->ListInsertTail(&node3);
    pList->ListInsertTail(&node4);

    pList->ListInsert(1, &node5);

    // pList->ListDelete(1, &temp);

    // pList->ListGetElem(1, &temp);
    pList->NextElem(&node5, &temp);
    pList->ListTraverse();
    cout << "temp=" << temp.data << endl;
    delete pList;
    pList = NULL;
    return 0;
}

