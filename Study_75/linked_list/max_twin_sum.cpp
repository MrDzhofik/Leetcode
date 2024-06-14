// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

//     For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.

// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void getArrayFromList(ListNode *head, std::vector<int> &nums)
    {
        ListNode *p = head;
        while (p != nullptr)
        {
            nums.push_back(p->val);
            p = p->next;
        }
    }

    int pairSum(ListNode *head)
    {
        std::vector<int> nums = {};
        getArrayFromList(head, nums);
        int max_sum = 0;
        int size = nums.size();
        for (int i = 0; i < size / 2; ++i)
        {
            int sum = nums[i] + nums[size - i - 1];
            max_sum = max_sum > sum ? max_sum : sum;
        }
        return max_sum;
    }
};
