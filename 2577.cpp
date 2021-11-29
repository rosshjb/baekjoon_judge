#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;

    int counter[10]{};
    int result = a * b * c;
    while (result / 10) {
        ++counter[result % 10];
        result /= 10;
    }
    ++counter[result];

    for (int count : counter)
        std::cout << count << '\n';
}
