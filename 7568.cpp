#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> persons;
    for (int i = 0; i < N; ++i) {
        pair<int, int> person;
        cin >> person.first >> person.second;
        persons.push_back(person);
    }

    for (int i = 0; i < N; ++i) {
        int rank = 1;
        for (int j = 0; j < N; ++j) {
            if (persons[i].first < persons[j].first && persons[i].second < persons[j].second) {
                ++rank;
            }
        }
        cout << rank << ' ';
    }

    return 0;
}
