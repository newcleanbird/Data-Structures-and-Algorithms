/*
选择排序：
1.思想：从未排序的序列中找到最大（最小值），放在已排序列的末尾。
2.实现过程：
    从左向右依次进行选择排序。每次排序时，先设置当前值为比较值(最大/最小)，然后向右进行比较，每次找到更大的(或更小的)，就将索引赋值给当前索引。
    最后根据索引，将当前比较值和找到值进行交换。(若没有找到，则自己交换自己)
3.时间复杂夫 O(n^2); 
4.空间复杂度：O(1);

*/


#include<iostream>

using namespace std;

void selection_sort(int a[], int n)
{
    int index = 0; // 比较值
    int i,j;
    for(i = 0; i < n; i++)
    {
        index = i;
        for(j = i + 1; j < n; j++)
        {
            if( a[j] < a[index]) // 升序 (小 -> 大)
            // if( a[j] < a[index]) // 降序 (大 -> 小)
            {
                index = j;
            }
        }
        swap(a[i], a[index]);
    }
}

int main()
{
    int arr[] = {21,5,15,67,75,13,42};
    selection_sort(arr, 7);
    for(auto i : arr)
    {
        cout << i << endl;
    }
    system("pause");
}