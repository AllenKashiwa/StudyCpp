#include <iostream>

using namespace std;

// 若使用对象数组，则其class需重载>运算符
template<typename T>
static void shell_sort(T arr[], int len)
{
    int gap, i, j;
    T temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
    {
        for (i = gap; i < len; i++)
        {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j-=gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
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
    int arr[13] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
    traverse_arr(arr, 13);
    shell_sort<int>(arr, 13);
    traverse_arr(arr, 13);
    return 0;
}