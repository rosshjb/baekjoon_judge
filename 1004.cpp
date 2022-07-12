#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int count = 0;

        int n;
        cin >> n;
        while (n--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool in_first = pow(x1 - cx, 2) + pow(y1 - cy, 2) < pow(r, 2);
            bool in_second = pow(x2 - cx, 2) + pow(y2 - cy, 2) < pow(r, 2);
            
            if ((in_first && !in_second) || (!in_first && in_second))
                ++count;
        }

        cout << count << '\n';
    }

    return 0;
}
