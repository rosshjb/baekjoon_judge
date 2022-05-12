#include <iostream>

using namespace std;

// V <= A + (-B) + A + (-B) + A + (-B) + … + A
//   <= (N - 1){A + (-B)} + A
//   <= N{A + (-B)} - A + B + A
//   <= N{A + (-B)} + B
// V - B <= N(A - B)
// (V - B) / (A - B) <= N
// if =, N, otherwise if <, +1 because of a day for last +A.
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int A, B, V;
    cin >> A >> B >> V;

    int days = (V - B) / (A - B);

    if ((V - B) % (A - B) != 0)
        ++days;

    cout << days;

    return 0;
}
