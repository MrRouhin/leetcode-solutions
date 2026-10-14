// Two Sum
// https://leetcode.com/problems/two-sum/
// Solution submitted and Accepted on LeetCode (see 01-result.png)
// Run locally:  g++ -std=c++17 01-two-sum.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store the number and its corresponding index
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If the complement is already in the map, we found our pair
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found
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
    vector<int> a = {2, 7, 11, 15};
    check("Typical: [2,7,11,15], target 9 -> [0,1]", s.twoSum(a, 9) == vector<int>({0, 1}));
    vector<int> b = {3, 3};
    check("Edge (duplicates): [3,3], target 6 -> [0,1]", s.twoSum(b, 6) == vector<int>({0, 1}));
    vector<int> c = {-3, 4, 3, 90};
    check("Edge (negatives): [-3,4,3,90], target 0 -> [0,2]", s.twoSum(c, 0) == vector<int>({0, 2}));
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
