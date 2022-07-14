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

        if (pow(x - X, 2) + pow(y - (Y + (double)H / 2), 2) <= pow((double)H / 2, 2))
            ++count;
        else if ((X <= x && x <= X + W) && (Y <= y && y <= Y + H))
            ++count;
        else if (pow(x - (X + W), 2) + pow(y - (Y + (double)H / 2), 2) <= pow((double)H / 2, 2))
            ++count;
    }

    cout << count;

    return 0;
}
