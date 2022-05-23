#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board;
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        board.push_back(row);
    }

    char color[2] = {'W', 'B'};
    int minimumFix = 8 * 8;
    for (int i = 0; i < N - 8 + 1; ++i) {
        for (int j = 0; j < M - 8 + 1; ++j) {
            for (int c = 0; c < 2; ++c) {
                int fix = 0;

                for (int n = 0; n < 8; ++n) {
                    for (int m = 0; m < 8; ++m) {
                        if (board[n + i][m + j] != color[(n + m + c) % 2])
                            ++fix;
                    }
                }

                if (minimumFix > fix)
                    minimumFix = fix;
            }
        }
    }

    cout << minimumFix;
}
