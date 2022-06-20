#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    stack<char> st;

    unordered_map<char, int> prec;
    prec.insert({'(', 0});
    prec.insert({'+', 1});
    prec.insert({'-', 1});
    prec.insert({'*', 2});
    prec.insert({'/', 2});

    char ch;
    while (cin >> ch) {
        if (ch == '(')
            st.push(ch);
        else if (ch == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop(); // ignore '('
        } else if ('A' <= ch && ch <= 'Z') {
            cout << ch;
        } else {  // ch is a operator
            while (!st.empty()) {
                char op = st.top();
                if (prec[ch] <= prec[op]) {
                    cout << op;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
 
    return 0;
}
