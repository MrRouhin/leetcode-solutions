#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: single-pass hash map.
// For each number, check if (target - number) was already seen.
// If yes, we found our pair. If no, remember this number's index.
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // value -> index
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    return {}; // no solution found
}

void runTest(vector<int> nums, int target, vector<int> expected, string label) {
    vector<int> result = twoSum(nums, target);
    bool pass = (result == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL");
    cout << " (got [" << (result.empty() ? "" : to_string(result[0]) + "," + to_string(result[1])) << "])" << endl;
}

int main() {
    runTest({2, 7, 11, 15}, 9, {0, 1}, "Test 1 (typical)");
    runTest({3, 3}, 6, {0, 1}, "Test 2 (duplicates)");
    runTest({-1, -2, -3, -4, -5}, -8, {2, 4}, "Test 3 (negatives)");
    return 0;
}