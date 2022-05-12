#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; ++i) {
        int k, n;

        cin >> k >> n;

        int room[14];
        for (int i = 0; i < 14; ++i)
            room[i] = i + 1;
        
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += room[j];
                room[j] = sum;
            }
        }
        
        cout << sum << '\n';
    }

    return 0;
}
