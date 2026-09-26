## Problem: Valid Anagram (Easy)
**Link:** https://leetcode.com/problems/valid-anagram/

### Approach
Counted the frequency of each letter in the first string, then subtracted the frequency of each letter in the second string. If every count lands back at zero (and the lengths matched to begin with), the strings are anagrams.

### Complexity
- Time: O(n)
- Space: O(1) — the count array is fixed at 26 letters regardless of input size

### Notes
Checking `s.size() != t.size()` first is a quick short-circuit — two strings of different lengths can never be anagrams, so there's no point counting. This solution assumes lowercase English letters only; a Unicode-safe version would need a hash map instead of a fixed-size array.