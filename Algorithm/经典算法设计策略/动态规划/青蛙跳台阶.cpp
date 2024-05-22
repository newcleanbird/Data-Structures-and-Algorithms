/*
青蛙跳台阶
    问题：一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
    N   跳法                   总数
    1   1                       1
    2   11 2                    2
    3   111 12 21               3
    4   1111 112 121 211 22     4
    思考：当跳到N台阶时，总共有跳一次和跳两次两种方法；即 N-1台阶跳法 + N-2 台阶的跳法
    状态转移方程：arr[i] = arr[i - 1] + arr[i - 2];
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    vector<int> arr;
    arr.insert(arr.end(), 1); // 0
    arr.insert(arr.end(), 1); // 1
    arr.insert(arr.end(), 2); // 2
    int N; // 次数
    cin >> N;
    for(int i = 3; i <= N; i++)
    {
        arr.insert(arr.end(), arr[i-1] + arr[i-2]) ;
    }
    for(auto i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << endl;
    }

    cout << arr[N];

    system("pause");
}