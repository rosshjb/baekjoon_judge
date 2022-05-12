#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = -1;
    for (int i = N / 5; i >= 0; --i) {
        for (int j = 0; j <= (N - (5 * i)) / 3; ++j) {
            if (5 * i + 3 * j == N) {
                sum = i + j;
                break;
            }
        }
        if (sum != -1)
            break;
    }
    
    cout << sum;

    return 0;
}
