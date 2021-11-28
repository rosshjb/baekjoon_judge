#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int cnt = 0;
    int new_n = n;
    do {
        int sum = (new_n / 10) + (new_n % 10);
        new_n = (new_n % 10 * 10) + (sum % 10);
        ++cnt;
    } while(new_n != n);

    std::cout << cnt;
}
