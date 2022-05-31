#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> As, result(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        As.push_back(A);
    }

    stack<int> st;
    for (int i = N - 1; i >= 0; --i) {
        result[i] = -1;

        while (!st.empty() && As[i] >= st.top())
            st.pop();

        if (!st.empty())
            result[i] = st.top();

        st.push(As[i]);
    }

    for (int i : result)
        cout << i << ' ';

    return 0;
}

