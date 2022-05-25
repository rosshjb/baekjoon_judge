#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> persons;
    for (int i = 1; i <= N; ++i)
        persons.push_back(i);

    vector<bool> erased(N, false);
    int position = N;
    cout << '<';
    for (int i = 1; i <= N; ++i) {
        int k_counter = 0;
        while (k_counter < K) {
            position = (position + 1 >= N) ? 0 : position + 1;
            
            if (erased[position] == false)
                ++k_counter;
        }
        cout << persons[position];
        erased[position] = true;

        if (i < N)
            cout << ", ";
    }
    cout << '>';

    return 0;
}
