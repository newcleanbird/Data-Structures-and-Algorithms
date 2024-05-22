/*
二分查找：也称折半查找
    要求：有序的数组、数组中无重复对象
    思想：首先将key与表中中间位置进行比较，若相等，则查找成功，返回该元素的位置；
        若不等，则在区间前半部分查找(key比中间位置小)，或者在后半部分查找(key比中间位置大)
        缩小范围后，继续进行相同的查找。
*/

#include<bits/stdc++.h>

using namespace std;


int binarysearch(int target, int a[], int left, int right)
{
    int middle;
    while(left <= right)
    {
        middle = left + right >> 1; // 区间中点
        if(a[middle] > target)
        {
            right = middle - 1; // 在左边查找，右端点在middle左边(-1)
            binarysearch(target, a, left, right);
        }
        else if(a[middle] < target)
        {
            left = middle + 1;  // 在右边边查找，左端点在middle右边(+1)
            binarysearch(target, a, left, right);
        }
        else
            return middle;
    }
}

int main()
{
    int arr[] = {1,4,5,8,11,14,21,33,45,66,89}; // 11 个元素
    int target_index = binarysearch(4, arr, 0, 10);
    cout << target_index;
}