## Problem: Binary Search (Easy)
**Link:** https://leetcode.com/problems/binary-search/

### Approach
Classic binary search on a sorted, distinct array. I kept a `lo`/`hi` range and repeatedly checked the middle element — narrowing the range to the left half or right half depending on whether the target was smaller or larger.

### Complexity
- Time: O(log n)
- Space: O(1)

### Notes
Used `mid = lo + (hi - lo) / 2` instead of `(lo + hi) / 2` to avoid integer overflow on very large arrays — a habit worth keeping even though it doesn't matter for LeetCode's input sizes.