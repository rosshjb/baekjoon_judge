#include <iostream>

using namespace std;

int main() {
    int X;
    cin >> X;

    // how many rooms are in diagonal
    int i = 0;
    while (X > 0) {
        ++i;
        X -= i;
    }

    // how many steps are needed further -> (X + i - 1)
    int numerator = 0, denominator = 0;
    if (i % 2 == 0) {
        numerator = 1 + (X + i - 1);
        denominator = i - (X + i - 1); 
    } else {
        numerator = i - (X + i - 1);
        denominator = 1 + (X + i - 1);
    }

    cout << numerator << '/' << denominator;

    return 0;
}
