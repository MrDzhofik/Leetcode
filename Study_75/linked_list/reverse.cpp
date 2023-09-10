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

// Given the head of a singly linked list, reverse the list, and return the
// reversed list.

// Input: head = [1,2]
// Output: [2,1]

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

typedef struct {
  int val;
  ListNode* next;
} ListNode;

#include <vector>

using namespace std;

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* q = head;
    vector<int> nums;
    while (q != nullptr) {
      nums.push_back(q->val);
      q = q->next;
    }
    int size = nums.size();
    q = head;
    for (int i = size - 1; i >= 0; i--) {
      q->val = nums[i];
      q = q->next;
    }
    return head;
  }
  ListNode* reverseList_(ListNode* head) {
    ListNode* q = head;
    if (q->next != nullptr) {
      q = q->next;
      return reverseList(q);
    }
    return q;
  }
};