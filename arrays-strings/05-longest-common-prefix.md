## Problem: Longest Common Prefix (Easy)
**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach
Vertical scanning: I take each character of the first string and check the same position in every other string. As soon as one string is too short or has a different character, the prefix up to that index is the answer. If nothing mismatches, the whole first string is the prefix.

### Complexity
- Time: O(S), where S is the total number of characters across all strings
- Space: O(1) extra (apart from the returned substring)

### Notes
Checking `i == strs[j].length()` before reading `strs[j][i]` prevents reading past the end of a shorter string. Edge cases tested: no common prefix (returns "") and a single string.

### Files
- Solution + local tests: [`05-longest-common-prefix.cpp`](./05-longest-common-prefix.cpp)
- Accepted on LeetCode: [`05-result.png`](./05-result.png)
