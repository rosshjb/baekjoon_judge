#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;

        v.push_back(number);
    }

    for (int i = 1; i < N; ++i) {
        int value = v[i];

        int j = i;
        while (j > 0 && v[j - 1] > value) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = value;
    }

    for (int i : v)
        cout << i << '\n';

    return 0;
}

