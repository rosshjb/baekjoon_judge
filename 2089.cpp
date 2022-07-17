#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> st;
    while (N) {
        if (N < 0 && N % -2 != 0) {
            st.push(-N % -2);
            N = (N - 1) / -2;
        } else {
            st.push(N % -2);
            N /= -2;
        }
    }

    if (st.empty()) {
        cout << 0 << '\n';
    } else {
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
    }

    return 0;
}
