#include <iostream>
#include <algorithm>

using namespace std;

// 若使用对象数组，则其class需重载<,<=,>,>=运算符
template<typename T>
void max_heapify(T arr[], int start, int end)
{
    // 建立父节点与子节点索引
    int dad = start;
    int son = dad * 2 + 1;
    // 若子节点索引在范围内才做比较
    while (son <= end)
    {
        // 先比较两个子节点大小，选择最大的
        if (son + 1 <= end && arr[son] < arr[son + 1])
        {
            son++;
        }
        // 如果父节点大于子节点代表调整完毕，直接跳出
        if (arr[dad] > arr[son])
        {
            return;
        }
        else // 否则交换父子内容再继续子节点和孙节点的比较
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

// 若使用对象数组，则其class需重载<,<=,>,>=运算符
template<typename T>
static void heap_sort(T arr[], int len)
{
    // 初始化, i从最后一个父节点开始调整
    for (int i = len / 2; i >= 0; i--)
    {
        max_heapify(arr, i, len - 1);
    }
    // 先将第一个元素和已经排好的元素的前一位做交换，
    // 再从新调整刚调整元素之前的元素，直到排序完毕
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
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
    int arr[] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
    int len = (int)sizeof(arr) / sizeof(*arr);
    traverse_arr(arr, len);
    heap_sort(arr, len);
    traverse_arr(arr, len);
    return 0;
}