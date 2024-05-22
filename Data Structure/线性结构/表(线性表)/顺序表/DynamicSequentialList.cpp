#include <iostream>
using namespace std;

// const int InitSize = 10; // 初始容量
typedef int ElementType; // 元素类型，这里以int为例

class DynamicSequentialList {
public:
    DynamicSequentialList(int InitSize) : data(new ElementType[InitSize]), length(0), maxSize(InitSize) {}

    ~DynamicSequentialList() {
        delete[] data;
    }

    // 判断是否为空
    bool isEmpty() const {
        return length == 0;
    }

    // 获取当前长度
    int getSize() const {
        return length;
    }

    // 在末尾添加元素，自动扩容
    void pushBack(ElementType val) {
        if (length == maxSize) {
            resize();
        }
        data[length++] = val;
    }

    // 插入元素到指定位置，自动扩容
    void insert(int pos, ElementType val) {
        if (pos < 0 || pos > length) {
            cout << "插入位置不合法！" << endl;
            return;
        }

        if (length == maxSize) {
            resize();
        }

        for (int i = length; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[pos] = val;
        length++;
    }

    // 删除指定位置的元素
    void remove(int pos) {
        if (pos < 0 || pos >= length) {
            cout << "删除位置不合法！" << endl;
            return;
        }

        for (int i = pos; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }

    // 查找元素位置，找不到返回-1
    int find(ElementType val) const {
        for (int i = 0; i < length; i++) {
            if (data[i] == val) {
                return i;
            }
        }
        return -1;
    }

    // 打印数组内容
    void print() const {
        cout << "动态顺序表内容如下：" << endl;
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    ElementType* data; // 动态分配的数组
    int length;       // 当前元素数量
    int maxSize;      // 当前数组容量

    // 扩容函数
    void resize() {
        maxSize *= 2; // 扩容一般为原大小的两倍
        ElementType* newData = new ElementType[maxSize];
        for (int i = 0; i < length; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

int main() {
    DynamicSequentialList arr(10);

    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    arr.print(); // 打印

    arr.insert(1, 4); // 在位置1插入4
    arr.print(); // 再次打印

    arr.remove(2); // 删除位置2的元素
    arr.print(); // 再次打印

    int pos = arr.find(5);
    if (pos != -1) {
        cout << "元素5的位置是：" << pos << endl;
    }
    else {
        cout << "元素5不在表中。" << endl;
    }

    return 0;
}