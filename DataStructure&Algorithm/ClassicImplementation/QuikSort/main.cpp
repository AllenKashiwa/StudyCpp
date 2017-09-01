#include <iostream>
#include <algorithm>

using namespace std;

// ************ 迭代版 *******************
struct Range {
    int start, end;
    Range(int s = 0, int e = 0) { start = s, end = e; }
};
// 若使用对象数组，则其class需重载<,<=,>,>=运算符
template<typename T>
void quik_sort(T arr[], const int len)
{
    if (len <= 0)
        return;
    // r[]模拟堆栈，r[p++]为push，r[--p]为pop
    Range *r = new Range[len];
    int p = 0;
    r[p++] = Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        T pivot = arr[range.end];
        int left = range.start, right = range.end - 1;
        while(left < right){
            while (arr[left] < pivot && left < right) left++;
            while (arr[right] >= pivot && left < right) right--;
            swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[range.end])
            swap(arr[left], arr[range.end]);
        else
            left++;
        r[p++] = Range(range.start, left - 1);
        r[p++] = Range(left + 1, range.end);
    }
}

// ************ 迭代版 *******************
// 若使用对象数组，则其class需重载<,<=,>,>=运算符
template<typename T>
static void quik_sort_recursive(T arr[], int start, int end)
{
    if (start >= end)
        return;
    T pivot = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < pivot && left < right) left++;
        while (arr[right] >= pivot && left < right) right--;
        swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(arr[left], arr[end]);
    else
        left++;
    quik_sort_recursive(arr, start, left - 1);
    quik_sort_recursive(arr, left + 1, end);
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
    quik_sort(arr, len);
    traverse_arr(arr, len);

    // 递归版
    int arr2[] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
    len = (int)sizeof(arr2) / sizeof(*arr2);
    traverse_arr(arr2, len);
    quik_sort_recursive<int>(arr2, 0, len - 1);
    traverse_arr(arr2, len);
    return 0;
}