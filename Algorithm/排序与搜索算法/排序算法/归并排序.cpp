/*
分治法理解归并法：
归并排序：
    分解：分解待排序的n个元素的序列成各n/2个元素的两个子序列。
    解决：使用归并排序递归的排序两个子序列。
    合并：合并两个已排序的子序列以产生已排序的答案。
    
    注意：当排序的序列长度为1时，递归开始回升，这种情况下不要有任何操作，因为长度为1的序列已排好序。
    关键：合并步骤中两个已排序序列的合并
        假设合并的序列为A、B，每次对比AB的堆顶(实际上两个排序好的序列是一个堆)，选择较小的加入已排序序列。本部需要对比n次，O(n)
*/

/*
归并排序（Merge sort）
1.排序思想：
    将初始序列的n个元素看成n个有序的子序列，每个子序列中只有一个元素，将其两两归并，
    得到n/2个长度为2(或1、子序列不为偶数则有落单)的有序子序列，再两两归并…以此类推直到得到n长的有序序列。
2.归并思想：
    两个子序列，分别有一个指针指向其首部，指针指向的元素进行对比，小的放入辅助数组里，指针后移，大的不动，
    直到两两对比完成，此时如果有某一子序列中的元素并没有对比完，则直接放入辅助数组。
3.优缺点：效率高且稳定，但是消耗的辅助空间与原数据空间成正比。
4.时间复杂度O(nlogn)
5.空间复杂度O(n)
6.稳定性：稳定

*/

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;     // 设置数组上限
int a[N], tmp[N];           // a[N]为待排序数组，tmp[N]为辅助数组

void merge_sort(int q[], int l, int r)  // 待排序区间，左端点，右端点
{
    if (l >= r) return;

    int mid = l + r >> 1;   // mid
    merge_sort(q, l, mid);  // 左区间归并
    merge_sort(q, mid + 1, r);  // 右区间归并
                                // 归并完，左区间和右区间都为有序数组
    int k = 0, i = l, j = mid + 1;  // i为左端点 j为中点+1
    while (i <= mid && j <= r)      // 保证i不超过中点，j不超过右端点
    {                                               // 将较小者依次放入辅助数组
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];    // 如果i小(<=)，将小的（i）放入辅助数组,j++
        else tmp[k ++ ] = q[j ++ ];                 // elsej小，将较小者(j)放入辅助数组, j++
    }
    // 放完以后，要么i超了(左边放完了)，要么j超了(右边放完了)，相应的另一个没放完
    while (i <= mid) // i没放完，直接放完
        tmp[k ++ ] = q[i ++ ];
    while (j <= r)  // j没放完，直接放完
        tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) // 从左端点到右端点，依次将辅助数组中的结果放回到原排序数组。
        q[i] = tmp[j];
}



int main()
{
    int a[] = {101, 15, 71, 37, 33, 66, 89, 7, 63, 17, 45, 78};
    merge_sort(a, 0, 11);
    for(auto i : a)
    {
        cout << i << endl;
    }
    system("pause");
}












/*
    #include<iostream>
    #include<exception>

    using namespace std;

    // void Merge(int[], int, int[], int, int, int)  //归并函数的声明【把归并函数提到该函数前面，则不用声明】
    //归并排序
    //参数：
    //		numbers[]：原数组
    //		length：数组元素的个数（数组长度）
    //		temp[]：辅助数组
    //		begin：数组开头的下标
    //		end：数组结尾的下标
    //归并函数
    //参数：
    //		numbers[]：原数组
    //		length：数组元素的个数（数组长度）
    //		temp[]：辅助数组
    //		begin：数组开头的下标
    //		end：数组结尾的下标
    //		middle：数组中间的下标
    void Merge(int numbers[], int length, int temp[], int begin, int end, int middle)
    {
        //1. 判断是否有不符合要求的参数传入，有则抛出错误
        if (numbers == nullptr || length <= 0 || begin < 0 || end >= length)
            return;

        //2. 将原序列从中分开
        int leftIndex = begin;		//左边序列的开始（左边序列的结尾是middle）
        int rightIndex = middle + 1;//右边序列的开始（右边序列的结尾是end）
        int tempIndex = begin;		//辅助数组的下标
        //3. 当左右子序列尚未到头时，循环
        while (leftIndex <= middle && rightIndex <= end)
        {
            //4. 两两对比判断，谁大谁就放入辅助数组，同时指针后移
            if (numbers[leftIndex] < numbers[rightIndex])
                temp[tempIndex] = numbers[leftIndex++];
            else
                temp[tempIndex] = numbers[rightIndex++];
            //5. 辅助数组下标++
            ++tempIndex;
        }

        //6. 当左边或右边子序列尚未到头时，直接放入辅助数组
        while (leftIndex <= middle)
            temp[tempIndex++] = numbers[leftIndex++];

        while (rightIndex <= end)
            temp[tempIndex++] = numbers[rightIndex++];

        //7. 再将辅助数组中已经有序的元素覆盖掉原数组中无序的元素，使原数组变成部分有序
        for (int i = begin; i <= end; ++i)
            numbers[i] = temp[i];
    }

    void MergeSort(int numbers[], int length, int temp[], int begin, int end)
    {
        //1. 同样判断传入的参数是否有效
        if (numbers == nullptr || length <= 0 || begin < 0 || end >= length)
            return;
        
        //2. 作为递归的结束条件，开始下标和结束下标相等时，说明子序列中只有一个元素，看作有序的
        if (end - begin == 0)
            return;

        //3. 定义中间变量，将数组分半【如果有7个元素，下标0-6，则middle=3，数组分为长度为4和3的两段】
        int middle = ((end - begin) / 2 ) + begin;
        //4. 递归，先递归左半边，再递归右半边，将左右子序列不断分为长度为1的子序列才停止递归
        MergeSort(numbers, length, temp, begin, middle);
        MergeSort(numbers, length, temp, middle + 1, end);
        //5. 再慢慢归并
        Merge(numbers, length, temp, begin, end, middle);
    }


    //简单测试
    int main(int arvc, char* argv[])
    {
        const int length = 9;
        int nums[length] = { 18, 7, 23, 3, 9, 32, 10 , 99, 0};
        int *temp = new int[length];

        MergeSort(nums, length, temp, 0, 8);

        for (int i = 0; i < length; i++)
            cout << nums[i] << "  ";

        delete[] temp;
        temp = nullptr;
        cout << endl;
        system("pause");
        return 0;
    }
*/