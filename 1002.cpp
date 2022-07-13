#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if (distance > r1 + r2 || (distance == 0 && r1 != r2) || abs(r1 - r2) > distance)
            cout << 0;
        else if (distance == r1 + r2 || (abs(r1 - r2) == distance && distance != 0))
            cout << 1;
        else if (abs(r1 - r2) < distance && distance < r1 + r2)
            cout << 2;
        else
            cout << -1;
        cout << '\n';
    }

    return 0;
}
