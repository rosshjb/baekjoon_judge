#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    string bit_string;
    cin >> bit_string;

    int power = 0, sum = 0;
    string::size_type idx = bit_string.size();
    stack<int> st;
    while (idx > 0) {
        int bit = bit_string[idx - 1] - '0';
        sum += (bit * pow(2, power));

        --idx;

        if (++power > 2 || idx == 0) {
            st.push(sum);
            
            power = sum = 0;
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}
