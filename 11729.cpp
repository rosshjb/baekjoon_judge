#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void hanoi(int from, int via, int to, int N);

vector<pair<int, int>> vec;

int main() {
    int N;
    cin >> N;

    hanoi(1, 2, 3, N);
    
    cout << vec.size() << '\n';
    for (auto it : vec)
        cout << it.first << ' ' << it.second << '\n';

    return 0;
}

void hanoi(int from, int via, int to, int N) {
    if (N == 1) {
        vec.push_back(make_pair(from, to));
        return;
    }
    
    hanoi(from, to, via, N - 1);
    vec.push_back(make_pair(from, to));
    hanoi(via, from, to, N - 1);
}
