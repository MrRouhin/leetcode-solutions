## Problem: Reverse String (Easy)
**Link:** https://leetcode.com/problems/reverse-string/

### Approach
Two-pointer swap: one pointer starts at the front, one at the back, and they swap characters while moving toward each other. This reverses the array in place without needing a second array.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
Because the array is modified in place, there's nothing to return — the function signature takes the vector by reference. Empty and single-character inputs both terminate immediately since `left < right` is never true.