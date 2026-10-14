// Valid Anagram
// https://leetcode.com/problems/valid-anagram/
// Solution submitted and Accepted on LeetCode (see 03-result.png)
// Run locally:  g++ -std=c++17 03-valid-anagram.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int freq[26] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }
        
        return true;
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
    check("Typical: anagram / nagaram -> true", s.isAnagram("anagram", "nagaram") == true);
    check("Typical: rat / car -> false", s.isAnagram("rat", "car") == false);
    check("Edge (different lengths): a / ab -> false", s.isAnagram("a", "ab") == false);
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
