/*
冒泡排序
1.思想：从前往后(或从后往前)两两比较相邻元素的值,若为逆序，则交换。
2.过程：经过n-1轮冒泡，每次冒泡时，从前往后(从后往前)依次进行比较，若为逆序，则进行交换。
3.时间复杂度：O(n^2); 最好：O(n) 最差：O(n^2) 
4.空间复杂度：O(1);
*/

#include<iostream>

using namespace std;

void bubbleSort(int arr[], int count) // 升序，小->大，
{
    for(int i = 0; i < count - 1; i++) // 只需对比n-1个元素
    {
        for(int j = count - 1; j >= i; j--) // 从最后一个元素【下标是(count-1)】向左冒泡，一直冒泡到比较的位置。
        {
            if(arr[j] < arr[i]) // 如果后面的比前面小，则交换，让小的在前面。 // 升序 小于； 降序 大于
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = {21,5,15,67,75,13,42};
    bubbleSort(arr, 7);
    for(auto i : arr)
    {
        cout << i << endl;
    }
    system("pause");

}