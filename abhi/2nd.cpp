#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

SinglyLinkedListNode *findLongestList(SinglyLinkedListNode *head)
{
    if (head == NULL)
        return head;
    SinglyLinkedListNode *temp = head;
    vector<int> v;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int n = v.size();
    vector<int> dp(n, 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i + 1] <= v[i])
            dp[i] += dp[i + 1];
    }
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
    int maxi = dp[0];
    int pt = 0;
    for (int i = 1; i < n; i++)
        if (dp[i] > dp[pt])
            pt = i;
    int t = -1;
    temp = head;
    while (temp)
    {
        t++;
        if (t == pt)
        {
            head = temp;
            break;
        }
        temp = temp->next;
    }
    temp = head;
    int c = 0;
    while (true && temp)
    {
        c++;
        if (c == dp[pt])
        {
            if (temp)
                temp->next = NULL;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    SinglyLinkedListNode *head = new SinglyLinkedListNode;
    SinglyLinkedListNode *one = new SinglyLinkedListNode;
    SinglyLinkedListNode *two1 = new SinglyLinkedListNode;
    SinglyLinkedListNode *two2 = new SinglyLinkedListNode;
    head->data = 1;
    head->next = one;
    one->data = 1;
    one->next = two1;
    two1->data = 2;
    two1->next = two2;
    two2->data = 2;
    two2->next = NULL;
    SinglyLinkedListNode *temp = head;
    temp = findLongestList(head);
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}