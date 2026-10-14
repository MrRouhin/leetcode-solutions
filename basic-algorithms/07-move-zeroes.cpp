// Move Zeroes
// https://leetcode.com/problems/move-zeroes/
// Solution submitted and Accepted on LeetCode (see 07-result.png)
// Run locally:  g++ -std=c++17 07-move-zeroes.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
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
    vector<int> a = {0, 1, 0, 3, 12};
    s.moveZeroes(a);
    check("Typical: [0,1,0,3,12] -> [1,3,12,0,0]", a == vector<int>({1, 3, 12, 0, 0}));
    vector<int> b = {0};
    s.moveZeroes(b);
    check("Edge (single zero): [0] -> [0]", b == vector<int>({0}));
    vector<int> c = {1, 2, 3};
    s.moveZeroes(c);
    check("Edge (no zeroes): [1,2,3] unchanged", c == vector<int>({1, 2, 3}));
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
