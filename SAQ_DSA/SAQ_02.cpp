#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValidParentheses(string s) {
    stack<char> stk;
    unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        if (brackets.count(c)) {
            if (stk.empty() || stk.top() != brackets[c]) {
                return false;
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    return stk.empty();
}

int main() {
    string s1 = "()";
    string s2 = "([{}])";
    string s3 = "([)]";

    cout << (isValidParentheses(s1) ? "Valid" : "Invalid") << endl;
    cout << (isValidParentheses(s2) ? "Valid" : "Invalid") << endl;
    cout << (isValidParentheses(s3) ? "Valid" : "Invalid") << endl;

    return 0;
}
