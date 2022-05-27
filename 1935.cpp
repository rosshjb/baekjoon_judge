#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string s;
    getline(cin, s);

    vector<int> operands;
    while (N-- > 0) {
        int operand;
        cin >> operand;
        operands.push_back(operand);
    }

    stack<double> st;
    for (string::size_type i = 0; i < s.size(); ++i) {
        string::value_type ch = s[i];
        if ('A' <= ch && ch <= 'Z') {
            st.push(operands[ch - 'A']);
        } else {
            double rhs = st.top();
            st.pop();
            double lhs = st.top();
            st.pop();

            double result = 0;
            switch (ch) {
                case '+':
                    result = lhs + rhs;
                    break;
                case '-':
                    result = lhs - rhs;
                    break;
                case '*':
                    result = lhs * rhs;
                    break;
                case '/':
                    result = lhs / rhs;
                    break;
            }
            st.push(result);
        }
    }

    cout << fixed << setprecision(2) << st.top();

    return 0;
}
