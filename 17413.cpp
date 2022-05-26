#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string stmt;
    getline(cin, stmt);
    
    stack<string::value_type> st;
    string::size_type idx = 0;
    bool reverse = true;
    while (idx < stmt.size()) {
        string::value_type ch = stmt[idx++];

        if (ch == '<') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << ch;
            reverse = false;
        } else if (ch == ' ' && reverse) {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << ch;
        } else if (ch == '>') {
            cout << ch;
            reverse = true;
        } else if (reverse) {
            st.push(ch);
        } else {
            cout << ch;
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    
    return 0;
}
