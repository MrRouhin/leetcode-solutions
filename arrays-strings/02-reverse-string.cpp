// Reverse String
// https://leetcode.com/problems/reverse-string/
// Solution submitted and Accepted on LeetCode (see 02-result.png)
// Run locally:  g++ -std=c++17 02-reverse-string.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
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
    vector<char> a = {'h','e','l','l','o'};
    s.reverseString(a);
    check("Typical: hello -> olleh", a == vector<char>({'o','l','l','e','h'}));
    vector<char> b = {'x'};
    s.reverseString(b);
    check("Edge (single char): x -> x", b == vector<char>({'x'}));
    vector<char> c = {'a','b'};
    s.reverseString(c);
    check("Edge (even length): ab -> ba", c == vector<char>({'b','a'}));
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
