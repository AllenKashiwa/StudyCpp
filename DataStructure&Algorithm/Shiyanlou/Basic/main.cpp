//��ҵ
//
//����һ������������������������к��е����ֵ��ֻҪ�����������еĺͣ�����������ֵ��Ӧ�����С�
//
//��������кͣ���������A1�� A2��... An �������и���������A1~An��һ��������Ai~Aj��ʹ��Ai��Aj�ĺ����
//���磺
//
//���У� - 2, 11, -4, 13, -5, 2, -5, -3, 12, -9������������к�Ϊ21��
//
//���У�0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5������������к�Ϊ43��
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int arrLength;
    cout << "�����������:" << endl;
    cin >> arrLength;
    cout << "��������:" << endl;
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
    cout << "��������к��ǣ� " << max << endl;
    cout << "��������:" << endl;
    for (size_t j = start; j <= end; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
    return 0;
}