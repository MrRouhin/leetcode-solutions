## Problem: Two Sum (Easy)
**Link:** https://leetcode.com/problems/two-sum/

### Approach
I walk through the array once and keep an `unordered_map` from each value to its index. For every number I check whether `target - nums[i]` is already in the map; if it is, I return both indices. A hash map gives O(1) lookups, so I don't need the O(n²) check of every pair.

### Complexity
- Time: O(n)
- Space: O(n): the map can hold up to n entries

### Notes
The order matters: I check for the complement *before* inserting the current number, so `[3,3]` with target 6 works and a number never pairs with itself. My local tests cover that duplicate case and a negative-number case.

### Files
- Solution + local tests: [`01-two-sum.cpp`](./01-two-sum.cpp)
- Accepted on LeetCode: [`01-result.png`](./01-result.png)
