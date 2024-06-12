// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Given the head of a singly linked list, group all the nodes with odd indices
// together followed by the nodes with even indices, and return the reordered
// list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should
// remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time
// complexity.

// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]
// Definition for singly-linked list.

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // find odd end of given linked list
    ListNode *first = head->next;
    ListNode *second = head;
    int check = 0;

    while (first->next != nullptr)
    {
        second = first;
        first = first->next;
        ++check;
    }

    ListNode *true_end = nullptr;

    if (check % 2)
    {
        true_end = first;
    }
    else
    {
        true_end = second;
    }

    ListNode *end = true_end;
    ListNode *i = head;
    ListNode *j = i->next;

    while (i != true_end && j != true_end)
    {
        i->next = j->next;
        j->next = end->next;
        end->next = j;
        i = i->next;
        j = i->next;
        end = end->next;
    }

    return head;
}

int main()
{
    ListNode *head;
    head = new ListNode(1);
    ListNode *p = head;
    ListNode *q = nullptr;
    for (int i = 2; i < 9; ++i)
    {
        q = new ListNode(i);
        p->next = q;
        p = p->next;
    }

    p = head;
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    head = oddEvenList(p);

    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    return 0;
}
