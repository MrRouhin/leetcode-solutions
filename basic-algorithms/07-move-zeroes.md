## Problem: Move Zeroes (Easy)
**Link:** https://leetcode.com/problems/move-zeroes/

### Approach
Used a two-pointer technique: `insertPos` tracks the next slot where a non-zero value belongs. As I scan through the array, every non-zero element gets swapped into `insertPos` and the pointer advances. Zeroes naturally get pushed toward the end as a side effect of the swaps.

### Complexity
- Time: O(n)
- Space: O(1) — done in place

### Notes
Swapping (rather than just overwriting) is what keeps this in-place with O(1) space, and it also happens to preserve relative order of the non-zero elements, which the problem requires. An all-zero array is a good edge case since `insertPos` never advances and nothing changes.