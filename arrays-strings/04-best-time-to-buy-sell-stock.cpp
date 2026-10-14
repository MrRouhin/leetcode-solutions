// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Solution submitted and Accepted on LeetCode (see 04-result.png)
// Run locally:  g++ -std=c++17 04-best-time-to-buy-sell-stock.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        
        for (int price : prices) {
            // Update the minimum price if a lower price is found
            if (price < min_price) {
                min_price = price;
            } 
            // Calculate profit if we sell today and update max_profit if it's higher
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }
        
        return max_profit;
    }
};

// ---------------- Local tests (run before submitting on LeetCode) ----------------
static int passed = 0, failed = 0;
void check(const string& name, bool ok) {
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << endl;
    ok ? passed++ : failed++;
}

int main() {
    Solution s;
    vector<int> a = {7, 1, 5, 3, 6, 4};
    check("Typical: [7,1,5,3,6,4] -> 5", s.maxProfit(a) == 5);
    vector<int> b = {7, 6, 4, 3, 1};
    check("Edge (falling prices): [7,6,4,3,1] -> 0", s.maxProfit(b) == 0);
    vector<int> c = {5};
    check("Edge (single day): [5] -> 0", s.maxProfit(c) == 0);
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
