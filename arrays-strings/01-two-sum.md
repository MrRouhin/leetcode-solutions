## Problem: Two Sum (Easy)
**Link:** https://leetcode.com/problems/two-sum/

### Approach
Used a hash map to store each number's index as I scan the array once. For every element, I check whether its complement (target - current number) has already been seen — if so, that's the pair. This avoids the O(n²) brute-force check of every pair.

### Complexity
- Time: O(n)
- Space: O(n)

### Notes
The brute-force nested-loop version is O(n²) and was my first instinct, but the hash map trades a bit of space for a single pass. Watch out for the case where the same value appears twice (e.g. [3,3]) — the map must be updated *after* checking for the complement, not before, or you'd match an element with itself.