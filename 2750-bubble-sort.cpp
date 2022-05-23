#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; ++i)
        cout << numbers[i] << '\n';

    return 0;
}
