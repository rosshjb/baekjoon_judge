#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> counts(10'001, 0);
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;

        ++counts[number];
    }

    for (vector<int>::size_type i = 1; i < counts.size(); ++i) {
        for (int j = 0; j < counts[i]; ++j)
            cout << i << '\n';
    }

    return 0;
}
