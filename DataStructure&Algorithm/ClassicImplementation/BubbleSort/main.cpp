#include <iostream>
#include <algorithm>

using namespace std;

// 若使用对象数组，则其class需重载<,<=,>,>=运算符
template<typename T>
void bubble_sort(T arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j+1]);
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
    bubble_sort(arr, len);
    traverse_arr(arr, len);
    return 0;
}