#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int a_copy = a, b_copy = b;
    while (b_copy != 0) {
        int r = a_copy % b_copy;
        a_copy = b_copy;
        b_copy = r;
    }
    cout << a_copy << '\n';

    cout << a * b / a_copy;

    return 0;
}
