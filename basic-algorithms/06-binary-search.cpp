// Binary Search
// https://leetcode.com/problems/binary-search/
// Solution submitted and Accepted on LeetCode (see 06-result.png)
// Run locally:  g++ -std=c++17 06-binary-search.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Use left + (right - left) / 2 to prevent integer overflow
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1; // Target is in the right half
            } else {
                right = mid - 1; // Target is in the left half
            }
        }
        
        return -1; // Target not found
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
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    check("Typical: find 9 -> index 4", s.search(a, 9) == 4);
    check("Edge (missing): find 2 -> -1", s.search(a, 2) == -1);
    vector<int> b = {5};
    check("Edge (single element): find 5 -> 0", s.search(b, 5) == 0);
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
