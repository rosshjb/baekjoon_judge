#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == ".")
            break;

        stack<char> st;
        int n = line.size();
        while (n > 0) {
            string::value_type ch = line[line.size() - n];
            if (ch == '(' || ch == '[') {
                st.push(ch);
            } else if (ch == ')') {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    break;
            } else if (ch == ']') {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    break;
            }

            --n;
        }

        if (n <= 0 && st.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
