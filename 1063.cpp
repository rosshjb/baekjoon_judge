#include <iostream>
#include <string>

using namespace std;

int main() {
    string s_king, s_stone;
    cin >> s_king >> s_stone;

    int col_king    = s_king[0] - 'A',
        row_king    = s_king[1] - '0' - 1,
        col_stone   = s_stone[0] - 'A',
        row_stone   = s_stone[1] - '0' - 1;

    int N;
    cin >> N;

    while (N--) {
        string position;
        cin >> position;

        int next_col_king = col_king, next_row_king = row_king;
        int next_col_stone = col_stone, next_row_stone = row_stone;
        if (position == "R") {
            next_col_king = col_king + 1;
            next_col_stone = col_stone + 1;
        } else if (position == "L") {
            next_col_king = col_king - 1;
            next_col_stone = col_stone - 1;
        } else if (position == "B") {
            next_row_king = row_king - 1;
            next_row_stone = row_stone - 1;
        } else if (position == "T") {
            next_row_king = row_king + 1;
            next_row_stone = row_stone + 1;
        } else if (position == "RT") {
            next_col_king = col_king + 1;
            next_row_king = row_king + 1;

            next_col_stone = col_stone + 1;
            next_row_stone = row_stone + 1;
        } else if (position == "LT") {
            next_col_king = col_king - 1;
            next_row_king = row_king + 1;

            next_col_stone = col_stone - 1;
            next_row_stone = row_stone + 1;
        } else if (position == "RB") {
            next_col_king = col_king + 1;
            next_row_king = row_king - 1;

            next_col_stone = col_stone + 1;
            next_row_stone = row_stone - 1;
        } else if (position == "LB") {
            next_col_king = col_king - 1;
            next_row_king = row_king - 1;

            next_col_stone = col_stone - 1;
            next_row_stone = row_stone - 1;
        }
        
        int prev_col_king = col_king, prev_row_king = row_king;
        int prev_col_stone = col_stone, prev_row_stone = row_stone;
        (void)prev_col_stone, (void)prev_row_stone;

        if (next_col_king >= 0 && next_col_king <= 7 && next_row_king >= 0 && next_row_king <= 7) {
            col_king = next_col_king;
            row_king = next_row_king;
        }
        
        if (next_col_stone >= 0 && next_col_stone <= 7 && next_row_stone >= 0 && next_row_stone <= 7) {
            if (col_stone == col_king && row_stone == row_king) {
                col_stone = next_col_stone;
                row_stone = next_row_stone;
            }
        }

        if (col_king == col_stone && row_king == row_stone) {
            col_king = prev_col_king;
            row_king = prev_row_king;
        }
    }

    cout << ((char)(col_king + 'A')) << ((char)(row_king + '0' + 1));
    cout << '\n';
    cout << ((char)(col_stone + 'A')) << ((char)(row_stone + '0' + 1));

    return 0;
}
