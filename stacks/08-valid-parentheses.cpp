#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// Approach: push opening brackets onto a stack.
// On a closing bracket, check the stack's top is the matching opener.
// String is valid only if the stack is empty at the end.
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != match[c]) return false;
            st.pop();
        }
    }
    return st.empty();

}

void runTest(string s, bool expected, string label) {
    bool result = isValid(s);
    bool pass = (result == expected);
    cout << label << ": " << (pass ? "PASS" : "FAIL")
         << " (got " << (result ? "true" : "false") << ")" << endl;
}

int main() {
    runTest("()[]{}", true, "Test 1 (typical)");
    runTest("", true, "Test 2 (empty string)");
    runTest("(]", false, "Test 3 (mismatched pair)");
    return 0;
}
