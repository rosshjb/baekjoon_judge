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

    for (int i = 0; i < N - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < N; ++j) {
            if (v[min_idx] > v[j])
                min_idx = j;
        }
        
        int temp = v[min_idx];
        v[min_idx] = v[i];
        v[i] = temp;
    }

    for (int i : v)
        cout << i << '\n';

    return 0;
}

