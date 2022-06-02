#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    set<int> st;
    while (N--) {
        int number;
        cin >> number;

        st.insert(number);
    }

    int M;
    cin >> M;

    while (M--) {
        int number;
        cin >> number;

        cout << st.contains(number) << ' ';
    }

    return 0;
}
