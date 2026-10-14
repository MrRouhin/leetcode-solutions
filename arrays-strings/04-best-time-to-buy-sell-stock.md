## Problem: Best Time to Buy and Sell Stock (Easy)
**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach
One pass, tracking the lowest price seen so far (`min_price`) and the best profit if I sold today (`price - min_price`). Because the buy day must come before the sell day, tracking the running minimum is enough. There's no need to compare every pair of days.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
When prices only fall, profit stays 0, which is the correct answer (don't trade). A single-day input also returns 0. Both cases are in my local tests.

### Files
- Solution + local tests: [`04-best-time-to-buy-sell-stock.cpp`](./04-best-time-to-buy-sell-stock.cpp)
- Accepted on LeetCode: [`04-result.png`](./04-result.png)
