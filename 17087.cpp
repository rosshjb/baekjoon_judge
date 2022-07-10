#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> A;
    while (N--) {
        int position;
        cin >> position;

        A.push_back(position);
    }

    if (A.size() == 1) {
        cout << abs(S - A[0]);
    } else {
        int g = gcd(abs(S - A[0]), abs(S - A[1]));
        
        for (vector<int>::size_type i = 2; i < A.size(); ++i)
            g = gcd(g, abs(S - A[i]));

        cout << g;
    }

    return 0;
}
