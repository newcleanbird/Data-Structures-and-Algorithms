/*
希尔排序：希尔排序是对"直接插入"排序算法的一种改进。目的是为了减少交换的次数 优化了直接插入算法。
1.思想：将待排序的表按照间隔切割成若干个子表，然后对这些子表进行插入排序。
2.实现：一般来说 第一次的间隔(divide)为整个排序表的一半(divide = ceil(size /2);),然后对按照这些间隔划分的子表进行直接插入排序，
第二次间隔又是第一次的一半(divide = ceil(divide / 2))然后对按照这些间隔划分的子表进行直接插入排序。
一直到间隔(divide)等于1为止,此时表内全部的数据都已是有序的。

时间复杂度：O(n^1.3) 最坏O(n^2)
空间复杂度O(1)
*/

#include<iostream>

using namespace std;

void ShellSort(int arr[], int n)
{
    int i, j, Increment;
    int Tmp;
    for(Increment = n / 2; Increment > 0; Increment /= 2){ // Increment:间隔，初始为数组长度的一般，每次递减一半。
        for(i = Increment; i < n; i++)  // i 从最小间隔到最大长度均遍历一遍
        {
            Tmp = arr[i];               // 变量为 arr[i]
            for(j = i; j >= Increment; j -= Increment)
            {
                //if(Tmp < arr[j - Increment]) //升序
                if(Tmp > arr[j - Increment]) // 降序

                    arr[j] = arr[j - Increment];
                else 
                    break;
            }
            arr[j] = Tmp;
        }
    }  
}

int main()
{
    int a[] = {15, 51, 27,6, 99, 36, 17, 85, 28, 35};
    int a_length = sizeof(a) / sizeof(a[0]);
    ShellSort(a, a_length);
    cout << "a_length:" << a_length << endl;
    for(int i = 0; i < a_length; i++)
    {
        cout << a[i] << endl;
    }
}