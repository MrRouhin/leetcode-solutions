#include <iostream>
#include <vector>
using namespace std;

// Approach: two-pointer in-place swap.
// "insertPos" tracks where the next non-zero element should go.
// Every time we find a non-zero, swap it into place and advance insertPos.
// This preserves the relative order of non-zero elements.
void moveZeroes(vector<int>& nums) {
    int insertPos = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[insertPos], nums[i]);
            insertPos++;
        }
    }
}

void runTest(vector<int> nums, vector<int> expected, string label) {
    moveZeroes(nums);
    bool pass = (nums == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << " (got [";
    for (size_t i = 0; i < nums.size(); i++) cout << nums[i] << (i + 1 < nums.size() ? "," : "");
    cout << "])" << endl;
}

int main() {
    runTest({0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}, "Test 1 (typical)");
    runTest({0, 0, 0}, {0, 0, 0}, "Test 2 (all zeroes)");
    runTest({1, 2, 3}, {1, 2, 3}, "Test 3 (no zeroes)");
    return 0;
}