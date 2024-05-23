/*
Doubly Linked List
C++实现的双向链表
*/
#include <iostream>

// 双链表节点定义
class Node {
public:
    int data;          // 数据域
    Node* prev;        // 指向前一个节点的指针
    Node* next;        // 指向后一个节点的指针

    // 构造函数
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// 双链表类
class DoublyLinkedList {
public:
    Node* head;        // 头节点
    Node* tail;        // 尾节点

    // 构造函数
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 析构函数
    ~DoublyLinkedList() {
        clear();
    }

    // 清空链表
    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

    // 在链表末尾添加节点
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 在链表开头添加节点
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 在特定节点后面插入节点
    bool insertAfter(Node* node, int data) {
        if (node == nullptr) return false;
        Node* newNode = new Node(data);
        newNode->prev = node;
        newNode->next = node->next;
        if (node->next) node->next->prev = newNode;
        else tail = newNode; // 插入到尾部
        node->next = newNode;
        return true;
    }

    // 删除指定节点
    bool removeNode(Node* node) {
        if (node == nullptr || !head) return false;
        if (node == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        }
        else if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        return true;
    }

    // 查找并返回节点，如果不存在返回nullptr
    Node* findNode(int data) {
        Node* current = head;
        while (current) {
            if (current->data == data) return current;
            current = current->next;
        }
        return nullptr;
    }

    // 打印链表
    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.append(1);
    list.append(2);
    list.prepend(0);
    list.insertAfter(list.findNode(1), 3);

    std::cout << "初始化列表: ";
    list.printList();

    list.removeNode(list.findNode(3));

    std::cout << "删除元素3后: ";
    list.printList();

    return 0;
}