#include <iostream>
#include <cstddef>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> As;
    vector<size_t> counts(1'000'000 + 1, 0);
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;

        As.push_back(number);
        ++counts[number];
    }

    vector<int> NGF(N, -1);
    stack<int> st;
    for (int i = N - 1; i >= 0; --i) {
        while (!st.empty()) {
            if (counts[As[i]] < counts[st.top()]) {
                NGF[i] = st.top();
                break;
            } else {
                st.pop();
            }
        }
        st.push(As[i]);
    }

    for (int number : NGF)
        cout << number << ' ';

    return 0;
}

