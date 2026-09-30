// 09-reverse-linked-list.cpp
// LeetCode: Reverse Linked List (Easy) — bonus problem
// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Approach: iterative pointer-flipping.
// Walk the list once, and at each node, point it backward at "prev"
// instead of forward — then advance both prev and curr by one step.
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next; // save the rest of the list before we overwrite next
        curr->next = prev;               // reverse this node's pointer
        prev = curr;                     // move prev forward
        curr = nextTemp;                 // move curr forward
    }
    return prev; // prev is the new head
}

// ---------- helpers for local testing ----------
ListNode* buildList(vector<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

vector<int> toVector(ListNode* head) {
    vector<int> out;
    while (head) { out.push_back(head->val); head = head->next; }
    return out;
}

void runTest(vector<int> input, vector<int> expected, string label) {
    ListNode* head = buildList(input);
    ListNode* reversed = reverseList(head);
    vector<int> result = toVector(reversed);
    bool pass = (result == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << " (got [";
    for (size_t i = 0; i < result.size(); i++) cout << result[i] << (i + 1 < result.size() ? "," : "");
    cout << "])" << endl;
}

int main() {
    // Typical case
    runTest({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, "Test 1 (typical)");

    // Edge case: single node, reversal is a no-op
    runTest({1}, {1}, "Test 2 (single node)");

    // Edge case: empty list
    runTest({}, {}, "Test 3 (empty list)");

    return 0;
}