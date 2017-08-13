//作业
//
//输入一组整数，求出这组数字子序列和中的最大值，只要求出最大子序列的和，不必求出最大值对应的序列。
//
//最大子序列和：整数序列A1， A2，... An （可能有负数），求A1~An的一个子序列Ai~Aj，使得Ai到Aj的和最大。
//例如：
//
//序列： - 2, 11, -4, 13, -5, 2, -5, -3, 12, -9，则最大子序列和为21。
//
//序列：0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5，则最大子序列和为43。
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int arrLength;
    cout << "输入数组个数:" << endl;
    cin >> arrLength;
    cout << "输入数组:" << endl;
    int *arr = new int[arrLength];
    for (size_t i = 0; i < arrLength; i++)
    {
        cin >> arr[i];
    }
    int sum, max = 0, start, end;
    for (size_t x = 0; x < arrLength - 1; x++)
    {
        sum = arr[x];
        for (size_t y = x + 1; y < arrLength; y++)
        {
            sum += arr[y];
            if (sum > max)
            {
                max = sum;
                start = x;
                end = y;
            }
        }
    }
    cout << "最大子序列和是： " << max << endl;
    cout << "该序列是:" << endl;
    for (size_t j = start; j <= end; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
    return 0;
}