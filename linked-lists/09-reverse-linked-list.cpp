// 09-reverse-linked-list.cpp
// LeetCode: Reverse Linked List (Easy) — bonus problem
// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // Store the next node
            curr->next = prev;               // Reverse the current node's pointer
            prev = curr;                     // Move prev forward
            curr = nextNode;                 // Move curr forward
        }
        
        return prev; // prev is the new head of the reversed list
    }
};