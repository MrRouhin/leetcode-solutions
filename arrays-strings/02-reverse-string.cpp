#include <iostream>
#include <vector>
using namespace std;

// Approach: two-pointer swap, in place, O(1) extra space.
void reverseString(vector<char>& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

void runTest(vector<char> s, vector<char> expected, string label) {
    reverseString(s);
    bool pass = (s == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << " (got \"";
    for (char c : s) cout << c;
    cout << "\")" << endl;
}

int main() {
    runTest({'h','e','l','l','o'}, {'o','l','l','e','h'}, "Test 1 (typical)");
    runTest({'a'}, {'a'}, "Test 2 (single char)");
    runTest({}, {}, "Test 3 (empty)");
    return 0;
}