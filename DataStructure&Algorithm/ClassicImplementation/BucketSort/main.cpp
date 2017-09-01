// 假设数据分布在[0, 100)之间，每个桶内部用链表表示
// 在数据入桶的同时插入排序。然后把各个桶中的数据合并
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
const int BUCKET_NUM = 10;

struct ListNode {
    explicit ListNode(int i = 0):mData(i),mNext(NULL){}
    ListNode* mNext;
    int mData;
};

ListNode* insert(ListNode* head, int val) {
    ListNode dummyNode;
    ListNode *newNode = new ListNode(val);
    ListNode *pre, *curr;
    dummyNode.mNext = head;
    pre = &dummyNode;
    curr = head;
    while (NULL != curr && curr->mData <= val) {
        pre = curr;
        curr = curr->mNext;
    }
    newNode->mNext = curr;
    pre->mNext = newNode;
    return dummyNode.mNext;
}

ListNode* merge(ListNode *head1, ListNode *head2)
{
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;
    while (NULL != head1 && NULL != head2) {
        if (head1->mData <= head2->mData) {
            dummy->mNext = head1;
            head1 = head1->mNext;
        }
        else {
            dummy->mNext = head2;
            head2 = head2->mNext;
        }
        dummy = dummy->mNext;
    }
    if (NULL != head1) dummy->mNext = head1;
    if (NULL != head2) dummy->mNext = head2;
    
    return dummyNode.mNext;
}

void bucket_sort(int arr[], int len) {
    vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
    for (int i = 0; i < len; ++i) {
        int index = arr[i] / BUCKET_NUM;
        ListNode *head = buckets.at(index);
        buckets.at(index) = insert(head, arr[i]);
    }
    ListNode *head = buckets.at(0);
    for (int i = 1; i < BUCKET_NUM; ++i) {
        head = merge(head, buckets.at(i));
    }
    for (int i = 0; i < len; ++i) {
        arr[i] = head->mData;
        head = head->mNext;
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
    bucket_sort(arr, 13);
    traverse_arr(arr, 13);
    return 0;
}