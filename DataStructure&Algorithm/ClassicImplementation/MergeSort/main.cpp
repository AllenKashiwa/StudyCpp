#include <iostream>
#include <algorithm>

using namespace std;

// ************ 迭代版 *******************
// 若使用对象数组，则其class需重载<,<=,>,>=运算符
template<typename T>
void merge_sort(T arr[], int len)
{
    T *a = arr;
    T *b = new T[len];
    for (int seg = 1; seg < len; seg += seg)
    {
        // for循环每次步长是两个段，每次循环合并两个段
        for (int start = 0; start < len; start += seg + seg)
        {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr)
    {
        for (int i = 0; i < len; i++)
        {
            b[i] = a[i];
        }
        b = a;
    }
    delete[] b;
}

// ************ 迭代版 *******************
// 若使用对象数组，则其class需重载<,<=,>,>=运算符
template<typename T>
static void merge_sort_recursive(T arr[], T reg[], int start, int end)
{
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

// 若使用对象数组，则其class需重载<<运算符
template<typename T>
void traverse_arr(T arr[], int len)
{
    cout << "traverse arr:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}

int main()
{
    // 迭代版
    int arr[] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
    int len = (int)sizeof(arr) / sizeof(*arr);
    traverse_arr(arr, len);
    merge_sort(arr, len);
    traverse_arr(arr, len);

    // 递归版
    int arr2[] = { 81,94,11,96,12,35,17,95,28,58,41,75 };
    len = (int)sizeof(arr2) / sizeof(*arr2);
    traverse_arr(arr2, len);
    int *reg = new int[len];
    merge_sort_recursive<int>(arr2, reg, 0, len - 1);
    traverse_arr(arr2, len);
    return 0;
}