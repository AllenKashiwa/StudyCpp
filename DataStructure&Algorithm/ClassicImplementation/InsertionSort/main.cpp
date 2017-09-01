#include <iostream>

using namespace std;

// 若使用对象数组，则其class需重载>运算符
template<typename T>
static void insertion_sort(T arr[], int len)
{
    int i, j;
    T temp;
    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        j = i - 1;// 将赋值放到for循环中会导致第18行出现j未声明
        for (;j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void traverse_arr(int arr[], int len)
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
    int arr[6] = { 34,8,64,51,32,21 };
    traverse_arr(arr, 6);
    insertion_sort<int>(arr, 6);
    traverse_arr(arr, 6);
    return 0;
}