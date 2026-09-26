## Problem: Valid Parentheses (Easy)
**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach
Used a stack to track open brackets. Every opening bracket gets pushed; every closing bracket must match whatever is currently on top of the stack, or the string is invalid. At the end, the stack must be empty — otherwise there were unmatched openers left over.

### Complexity
- Time: O(n)
- Space: O(n) — worst case (all openers) the stack holds every character

### Notes
The trickiest edge case is a closing bracket with an empty stack (e.g. just ")" ) — checking `st.empty()` before `st.top()` avoids undefined behavior there. A stack is the natural fit here because bracket matching is inherently "last opened, first closed."