#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // 기본 생성자 추가
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return dummy->next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode *createList(vector<int> nums)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    for (int num : nums)
    {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

int main()
{
    FIO;

    vector<int> v1 = {2, 4, 3};
    vector<int> v2 = {5, 6, 4};

    ListNode *l1 = createList(v1);
    ListNode *l2 = createList(v2);

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}
