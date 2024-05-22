#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义树节点结构体，包含数据和父节点的索引
struct TreeNode {
    int data;          // 节点的数据
    int parentIndex;   // 父节点在数组中的索引，默认为-1表示无父节点（根节点）
};

class TreeWithParent {
public:
    TreeWithParent(int size) {
        nodes.resize(size);
        for (int i = 0; i < size; ++i) {
            nodes[i].parentIndex = -1; // 初始化所有节点的父节点索引为-1
        }
    }

    // 设置节点的父节点索引，假设节点索引从0开始
    void setParent(int childIndex, int parentIndex) {
        if (childIndex >= 0 && childIndex < nodes.size() && parentIndex >= 0 && parentIndex < nodes.size()) {
            nodes[childIndex].parentIndex = parentIndex;
        }
        else {
            cout << "Error: Invalid index." << endl;
        }
    }

    // 查找给定节点的父节点索引
    int findParent(int index) {
        if (index >= 0 && index < nodes.size()) {
            return nodes[index].parentIndex;
        }
        else {
            cout << "Error: Node not found." << endl;
            return -1;
        }
    }

    // 从根节点开始的前序遍历
    void preorderTraversal(int currentNodeIndex) {
        if (currentNodeIndex == -1) return; // 如果索引无效，则返回

        cout << "Visiting node " << currentNodeIndex << " with data " << nodes[currentNodeIndex].data << endl;

        // 遍历当前节点的所有孩子（这里简化处理，假设知道孩子索引范围，实际应用中可能需要根据具体逻辑调整）
        for (int i = 1; i < nodes.size(); ++i) {
            if (findParent(i) == currentNodeIndex) {
                preorderTraversal(i);
            }
        }
    }

    // 从叶子节点向上遍历到根节点
    void traverseToRoot(int leafIndex) {
        stack<int> nodeStack;
        while (leafIndex != -1) {
            cout << "Visiting node on the way to root: " << leafIndex << " with data " << nodes[leafIndex].data << endl;
            nodeStack.push(leafIndex);
            leafIndex = findParent(leafIndex);
        }

        // 可选：打印遍历路径
        cout << "Path from leaf to root: ";
        while (!nodeStack.empty()) {
            cout << nodeStack.top() << " ";
            nodeStack.pop();
        }
        cout << endl;
    }

private:
    vector<TreeNode> nodes; // 使用vector存储所有节点
};

int main() {
    // 创建一个有5个节点的树
    TreeWithParent tree(5);

    // 假设节点0是根节点，节点1、2、3、4分别是它的孩子
    tree.setParent(1, 0);
    tree.setParent(2, 0);
    tree.setParent(3, 0);
    tree.setParent(4, 0);

    // 查找节点2的父节点索引
    int parentIndex = tree.findParent(2);
    if (parentIndex != -1) {
        cout << "Parent of node 2 is node " << parentIndex << "." << endl;
    }

    // 前序遍历
    cout << "Preorder Traversal:" << endl;
    tree.preorderTraversal(0); // 从根节点开始遍历

    // 从叶子节点向上遍历到根节点
    cout << "\nTraversing from leaf to root:" << endl;
    tree.traverseToRoot(4); // 假设4是叶子节点

    return 0;
}