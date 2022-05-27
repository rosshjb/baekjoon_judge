#include <iostream>
#include <string>
#include <stack>
#include <cstddef>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<string::size_type> st;
    size_t pieces = 0;
    for (string::size_type i = 0; i < s.size(); ++i) {
        string::value_type ch = s[i];

        if (ch == '(') {                // open stick or laser
            st.push(i);
        } else /* ')' */ {
            if (st.top() == (i - 1)) {  // close laser
                st.pop();
                pieces += st.size();
            } else {                    // close stick
                st.pop();
                ++pieces;
            }
        }
    }
    cout << pieces;


    return 0;
}
