## Problem: Best Time to Buy and Sell Stock (Easy)
**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach
Scanned the prices once while tracking the lowest price seen so far. At each day, I compared "profit if I sold today" against the best profit found so far, then updated the running minimum. This avoids checking every buy/sell pair explicitly.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
The key insight is that we only ever need to buy at the lowest point *before* the current day — we never need to remember which day, just the value. If prices strictly decrease the whole time, profit correctly stays 0 since we never find a later, higher price.