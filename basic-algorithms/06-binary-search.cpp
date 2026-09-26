#include <iostream>
#include <vector>
using namespace std;

// Approach: classic binary search on a sorted array.
// Repeatedly halve the search range based on comparing the middle element.
int search(vector<int>& nums, int target) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

void runTest(vector<int> nums, int target, int expected, string label) {
    int result = search(nums, target);
    bool pass = (result == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL")
         << " (got " << result << ")" << endl;
}

int main() {
    runTest({-1, 0, 3, 5, 9, 12}, 9, 4, "Test 1 (typical)");
    runTest({-1, 0, 3, 5, 9, 12}, 2, -1, "Test 2 (not found)");
    runTest({5}, 5, 0, "Test 3 (single element)");
    return 0;
}