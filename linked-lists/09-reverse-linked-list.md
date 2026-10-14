## Problem: Reverse Linked List (Easy)
**Link:** https://leetcode.com/problems/reverse-linked-list/

### Approach
Iterative reversal with three pointers: `prev`, `curr` and `nextNode`. For each node I save its next node, point it back to `prev`, and step both pointers forward. When `curr` becomes null, `prev` is the new head.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
Saving `curr->next` *before* changing it is the key step, or the rest of the list is lost. An empty list returns `nullptr` and a single node returns itself (both tested). Next time I'd like to try the recursive version.

### Files
- Solution + local tests: [`09-reverse-linked-list.cpp`](./09-reverse-linked-list.cpp)
- Accepted on LeetCode: [`09-result.png`](./09-result.png)
