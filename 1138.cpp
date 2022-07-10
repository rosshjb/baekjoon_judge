#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> line(N, -1);
    
    for (int i = 0; i < N; ++i) {
        int higher;
        cin >> higher;

        int count = 0, idx = 0;
        while (count < higher || line[idx] != -1) {
            if (line[idx] == -1)
                ++count;
            ++idx;
        }

        line[idx] = i + 1;
    }

    for (auto i : line)
        cout << i << ' ';

    return 0;
}
