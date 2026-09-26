#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach: track the lowest price seen so far while scanning left to right.
// At each day, check profit if we sold today (price - minSoFar) and keep the best.
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int minPrice = prices[0];
    int best = 0;
    for (int i = 1; i < (int)prices.size(); i++) {
        best = max(best, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return best;
}

void runTest(vector<int> prices, int expected, string label) {
    int result = maxProfit(prices);
    bool pass = (result == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL")
         << " (got " << result << ")" << endl;
}

int main() {
    runTest({7, 1, 5, 3, 6, 4}, 5, "Test 1 (typical)");
    runTest({7, 6, 4, 3, 1}, 0, "Test 2 (always falling)");
    runTest({5}, 0, "Test 3 (single element)");
    return 0;
}