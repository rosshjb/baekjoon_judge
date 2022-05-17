#include <iostream>

using namespace std;

void star(int row, int column, int N);

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            star(i, j, N);
        cout << '\n';
    }

    return 0;
}

void star(int row, int column, int N) {
    if (((row - 1) / N + 1) % 3 == 2 && ((column - 1) / N + 1) % 3 == 2)
        cout << ' ';
    else if (N == 1)
        cout << '*';
    else
        star(row, column, N / 3);
}
