#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int zero_count = 0;
    for (int i = 1; i * 5 <= N; ++i) {
        int dividend = i * 5;
        while (dividend % 5 == 0) {
            dividend /= 5;
            ++zero_count;
        }
    }

    cout << zero_count;

    return 0;
}
