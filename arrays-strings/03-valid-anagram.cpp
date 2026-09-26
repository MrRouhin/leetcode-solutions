#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Approach: count letter frequency of s, subtract for t.
// If all counts return to zero and lengths matched, it's an anagram.
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> counts(26, 0);
    for (char c : s) counts[c - 'a']++;
    for (char c : t) counts[c - 'a']--;
    for (int c : counts) if (c != 0) return false;
    return true;
}

void runTest(string s, string t, bool expected, string label) {
    bool result = isAnagram(s, t);
    bool pass = (result == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL")
         << " (got " << (result ? "true" : "false") << ")" << endl;
}

int main() {
    runTest("anagram", "nagaram", true, "Test 1 (typical)");
    runTest("rat", "car", false, "Test 2 (not anagram)");
    runTest("", "", true, "Test 3 (empty strings)");
    return 0;
}