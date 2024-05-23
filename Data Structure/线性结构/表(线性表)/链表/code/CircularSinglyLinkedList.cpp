/*
Circular Singly Linked List
C++实现的循环单向链表
*/
#include <iostream>

// 单向循环链表节点定义
class Node {
public:
    int data;          // 数据域
    Node* next;        // 指向下一个节点的指针

    // 构造函数
    Node(int data) : data(data), next(nullptr) {}
};

// 单向循环链表类
class CircularSinglyLinkedList {
private:
    Node* head;        // 头节点

public:
    // 构造函数
    CircularSinglyLinkedList() : head(nullptr) {}

    // 析构函数
    ~CircularSinglyLinkedList() {
        clear();
    }

    // 清空链表
    void clear() {
        Node* current = head;
        if (head) {
            do {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
        }
        head = nullptr;
    }

    // 在链表末尾添加节点
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    // 在链表开头添加节点
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            newNode->next = head;
            head = newNode;
            current->next = head;
        }
    }

    // 删除具有特定值的第一个节点
    bool remove(int data) {
        if (head == nullptr) return false;

        Node* current = head;
        Node* prev = nullptr;
        do {
            if (current->data == data) {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    // 如果删除的是头节点
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = current->next;
                    temp->next = head;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        return false; // 未找到要删除的节点
    }

    // 查找并返回数据域为给定值的第一个节点，否则返回nullptr
    Node* find(int data) {
        if (head == nullptr) return nullptr;
        Node* current = head;
        do {
            if (current->data == data) return current;
            current = current->next;
        } while (current != head);
        return nullptr;
    }

    // 打印链表
    void printList() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularSinglyLinkedList csll;
    csll.append(1);
    csll.append(2);
    csll.append(3);
    csll.prepend(0);
    csll.printList(); // 输出: 0 1 2 3 

    csll.remove(2);
    csll.printList(); // 输出: 0 1 3 

    if (csll.find(3)) {
        std::cout << "Found value 3 in the list." << std::endl;
    }
    else {
        std::cout << "Value 3 not found in the list." << std::endl;
    }

    return 0;
}


