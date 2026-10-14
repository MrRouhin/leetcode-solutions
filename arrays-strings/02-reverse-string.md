## Problem: Reverse String (Easy)
**Link:** https://leetcode.com/problems/reverse-string/

### Approach
Two pointers: `left` starts at the beginning and `right` at the end. I swap the two characters and move both pointers inward until they meet. The problem requires reversing in place, so no second array.

### Complexity
- Time: O(n)
- Space: O(1): in place

### Notes
For a single character the loop never runs, which is correct. Even and odd lengths both work because the loop stops when `left >= right`.

### Files
- Solution + local tests: [`02-reverse-string.cpp`](./02-reverse-string.cpp)
- Accepted on LeetCode: [`02-result.png`](./02-result.png)
