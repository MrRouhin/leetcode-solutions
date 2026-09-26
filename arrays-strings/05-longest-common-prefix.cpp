#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Approach: use the first string as a candidate prefix, and shrink it
// character by character until every other string starts with it.
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    for (int i = 1; i < (int)strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

void runTest(vector<string> strs, string expected, string label) {
    string result = longestCommonPrefix(strs);
    bool pass = (result == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL")
         << " (got \"" << result << "\")" << endl;
}

int main() {
    runTest({"flower", "flow", "flight"}, "fl", "Test 1 (typical)");
    runTest({"dog", "racecar", "car"}, "", "Test 2 (no common prefix)");
    runTest({"single"}, "single", "Test 3 (single string)");
    return 0;
}