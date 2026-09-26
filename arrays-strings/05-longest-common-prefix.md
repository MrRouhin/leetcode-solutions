## Problem: Longest Common Prefix (Easy)
**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach
Started with the first string as a "candidate" prefix, then compared it against every other string in the list, shrinking it from the end one character at a time whenever a string didn't start with the current candidate.

### Complexity
- Time: O(S) where S is the sum of all characters across all strings (worst case)
- Space: O(1) extra (not counting the output string)

### Notes
If the candidate prefix ever shrinks to empty, we can return immediately — no string can share a shorter common prefix than "". A vertical-scanning approach (compare column by column across all strings) would be a cleaner alternative to try next time.