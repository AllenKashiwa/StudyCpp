#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// 若使用对象数组，则其class需重载>运算符
template<typename T>
void selection_sort(std::vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[min])
                min = j;
        std::swap(arr[i], arr[min]);
    }
}

template<typename T>
void traverse_vector(const std::vector<T> &arr)
{
    cout << "traverse vector:" << endl;
    for (auto val : arr)
    {
        cout << val << ",";
    }
    cout << endl;
}

int main()
{
    std::vector<int> arr = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
    traverse_vector<int>(arr);
    selection_sort<int>(arr);
    traverse_vector<int>(arr);
    return 0;
}