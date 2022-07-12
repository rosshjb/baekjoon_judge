#include <iostream>
#include <vector>
#include <tuple>
#include <variant>
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
        vector<tuple<int, int, int>> planets;
        while (n--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            planets.push_back({cx, cy, r});
        }

        for (auto p : planets) {
            bool in_first = pow(x1 - get<0>(p), 2) + pow(y1 - get<1>(p), 2) < pow(get<2>(p), 2);
            bool in_second = pow(x2 - get<0>(p), 2) + pow(y2 - get<1>(p), 2) < pow(get<2>(p), 2);

            if ((in_first && !in_second) || (!in_first && in_second))
                ++count;
        }

        cout << count << '\n';
    }

    return 0;
}
