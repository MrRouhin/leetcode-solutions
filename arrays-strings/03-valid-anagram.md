## Problem: Valid Anagram (Easy)
**Link:** https://leetcode.com/problems/valid-anagram/

### Approach
If the lengths differ, it can't be an anagram. Otherwise I use a 26-slot frequency array: for each position I add 1 for the letter in `s` and subtract 1 for the letter in `t`. If every count ends at zero, both strings use exactly the same letters.

### Complexity
- Time: O(n)
- Space: O(1): fixed array of 26 counts

### Notes
Using one array and doing `++`/`--` in the same loop is cleaner than sorting both strings (O(n log n)). This only works for lowercase a–z; for Unicode input I'd switch to an `unordered_map<char,int>`.

### Files
- Solution + local tests: [`03-valid-anagram.cpp`](./03-valid-anagram.cpp)
- Accepted on LeetCode: [`03-result.png`](./03-result.png)
