#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int N;
    cin >> N;
    vector<int> freqs;
    while (N--) {
        int f;
        cin >> f;
        freqs.push_back(f);
    }

    bool with_favorite = false;
    int min_diff = abs(A - B);
    for (auto f : freqs) {
        int diff = abs(B - f);
        if (min_diff > diff) {
            min_diff = diff;
            with_favorite = true;
        }
    }

    if (with_favorite)
        cout << min_diff + 1;
    else
        cout << abs(A - B);

    return 0;
}
