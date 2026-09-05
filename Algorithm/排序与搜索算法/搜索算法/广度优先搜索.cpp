/*
广度优先算法
    核心思想：使用队列按层搜索每一层元素，使用哈希表记录元素已被记录，一层一层的入队出队进行遍历。
*/


/*
BFS:
    1.初始化 队列q，路径v
    2.选择一个起点s，加入到q和v（从s开始搜索，s标记已加入队列）
    3.while 循环，当队列q为空时，广度空间搜索过程结束；
        for all 元素 : (处理当前队列所有元素)
            每次拿出队列首元素，队列pop（意思是处理当前搜索的节点）
            处理当前节点（结果满足，保存结果）
            把当前节点邻居可搜索的元素全部加入q，并且标记该元素已被加入队列



    2.设计递归函数  // (1)返回值，参数类型(需要用到的)
        函数执行过程：
            若到达结尾，则返回                         // 终止条件返回判断
            更新当前结果 (上一步已经判断，未到达结尾)    // 确定单层递归逻辑(更新)
            若到达末尾叶子节点，进行最优结果更新         // 判断要不要收集结果：更新最优结果
            分别对当前左右子树调用递归函数               // 只要往下一层有道路，不管有没有元素，依然进行搜索，递归终止判断部分会判断是否返回
    3.开始调用
*/


#include <queue>
#include <unordered_set>
using namespace std;

struct Node {

} Node;

int BFS(Node* start, Node* target) {
    queue<Node*> q;
    unordered_set<Node*> visited;
    
    q.push(start);
    visited.insert(start);
    int step = 0; // 记录步数（路径长度）
    
    while (!q.empty()) {
        // 🔥 核心：固定当前层的大小（这代表"一步"能走到的范围）
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            Node* cur = q.front(); q.pop();
            
            // 找到目标，直接返回步数（第一次找到一定是最短的）
            if (cur == target) return step;
            
            // 把下一层的邻居加进来
            for (Node* neighbor : cur->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        step++; // 这一层遍历完，步数+1
    }
    return -1; // 走不通
}

int main() {
    Node* start;
    Node* target;
    BFS (start, target);
}
