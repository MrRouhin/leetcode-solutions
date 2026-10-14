## Problem: Binary Search (Easy)
**Link:** https://leetcode.com/problems/binary-search/

### Approach
Classic binary search on a sorted array with `left` and `right` bounds. I compare the middle element to the target and throw away the half that can't contain it, until the range is empty.

### Complexity
- Time: O(log n)
- Space: O(1)

### Notes
I calculate `mid = left + (right - left) / 2` instead of `(left + right) / 2` to avoid integer overflow on large indices. The loop condition `left <= right` matters: with `<`, a single-element array would never be checked.

### Files
- Solution + local tests: [`06-binary-search.cpp`](./06-binary-search.cpp)
- Accepted on LeetCode: [`06-result.png`](./06-result.png)
