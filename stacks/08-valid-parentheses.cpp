// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// Solution submitted and Accepted on LeetCode (see 08-result.png)
// Run locally:  g++ -std=c++17 08-valid-parentheses.cpp -o test && ./test

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If the stack is empty, there's no matching opening bracket
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if the top of the stack matches the current closing bracket
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // It's a match, so pop the opening bracket
                } else {
                    return false; // Mismatched brackets
                }
            }
        }
        
        // If the stack is empty at the end, all brackets were matched properly
        return st.empty();
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
    check("Typical: ()[]{} -> true", s.isValid("()[]{}") == true);
    check("Typical: {[]} (nested) -> true", s.isValid("{[]}") == true);
    check("Edge (wrong order): (] -> false", s.isValid("(]") == false);
    check("Edge (only closing): ) -> false", s.isValid(")") == false);
    check("Edge (unclosed): (( -> false", s.isValid("((") == false);
    cout << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
