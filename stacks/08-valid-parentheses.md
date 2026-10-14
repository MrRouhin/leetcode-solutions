## Problem: Valid Parentheses (Easy)
**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach
I use a stack: push every opening bracket, and for each closing bracket check that the top of the stack is the matching opening one, then pop it. At the end the stack must be empty, or some brackets were never closed.

### Complexity
- Time: O(n)
- Space: O(n): worst case, all opening brackets are pushed

### Notes
Two edge cases are easy to miss: a closing bracket when the stack is empty (`")"` returns false) and leftover openers (`"(("` returns false). I tested both, plus a nested case `{[]}`. A `map` from closing to opening brackets would shorten the if-condition.

### Files
- Solution + local tests: [`08-valid-parentheses.cpp`](./08-valid-parentheses.cpp)
- Accepted on LeetCode: [`08-result.png`](./08-result.png)
