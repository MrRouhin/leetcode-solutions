// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// Solution submitted and Accepted on LeetCode (see 05-result.png)
// Run locally:  g++ -std=c++17 05-longest-common-prefix.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Iterate through the characters of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            
            // Check this character against all other strings
            for (int j = 1; j < strs.size(); j++) {
                // If we reach the end of a string or find a mismatch, 
                // return the prefix found so far.
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // If we make it through the loop, the entire first string is the common prefix
        return strs[0];
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
    vector<string> a = {"flower", "flow", "flight"};
    check("Typical: [flower,flow,flight] -> fl", s.longestCommonPrefix(a) == "fl");
    vector<string> b = {"dog", "racecar", "car"};
    check("Edge (no common prefix): -> \"\"", s.longestCommonPrefix(b) == "");
    vector<string> c = {"alone"};
    check("Edge (single string): [alone] -> alone", s.longestCommonPrefix(c) == "alone");
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
