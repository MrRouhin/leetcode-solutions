## Problem: Move Zeroes (Easy)
**Link:** https://leetcode.com/problems/move-zeroes/

### Approach
Two pointers: `right` scans every element, and `left` marks where the next non-zero should go. Each time I find a non-zero, I swap it into position `left` and move `left` forward. Non-zeros keep their relative order, and the zeroes end up at the back.

### Complexity
- Time: O(n)
- Space: O(1): in place

### Notes
This is like the partition step of a sort. When there are no zeroes, every swap is with itself, so the array stays unchanged (tested). A cleaner version could skip the swap when `left == right`.

### Files
- Solution + local tests: [`07-move-zeroes.cpp`](./07-move-zeroes.cpp)
- Accepted on LeetCode: [`07-result.png`](./07-result.png)
