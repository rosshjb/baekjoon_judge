#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int W, H, X, Y, P;
    cin >> W >> H >> X >> Y >> P;

    int count = 0;
    while (P--) {
        int x, y;
        cin >> x >> y;

        bool in_left_semicircle = x >= -sqrt(pow((double)H / 2, 2) - pow(y - (Y + (double)H / 2), 2)) + X && x <= X;
        bool in_rectangle = (X < x && x < X + W) && (Y <= y && y <= Y + H);
        bool in_right_semicircle = x <= sqrt(pow((double)H / 2, 2) - pow(y - (Y + (double)H / 2), 2)) + (X + W) && x >= X + W;

        if (in_left_semicircle || in_rectangle || in_right_semicircle)
            ++count;
    }

    cout << count;

    return 0;
}
