// Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
// Solution submitted and Accepted on LeetCode (see 09-result.png)
// Run locally:  g++ -std=c++17 09-reverse-linked-list.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

// LeetCode provides this definition; included here so the file compiles locally.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

// ---------------- Local tests (run before submitting on LeetCode) ----------------
static int passed = 0, failed = 0;
void check(const string& name, bool ok) {
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << endl;
    ok ? passed++ : failed++;
}

ListNode* build(const vector<int>& v) {
    ListNode dummy; ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}
vector<int> toVec(ListNode* h) {
    vector<int> v;
    while (h) { v.push_back(h->val); h = h->next; }
    return v;
}

int main() {
    Solution s;
    check("Typical: 1->2->3->4->5 -> 5->4->3->2->1", toVec(s.reverseList(build({1,2,3,4,5}))) == vector<int>({5,4,3,2,1}));
    check("Edge (empty list): [] -> []", toVec(s.reverseList(build({}))).empty());
    check("Edge (single node): [1] -> [1]", toVec(s.reverseList(build({1}))) == vector<int>({1}));
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
