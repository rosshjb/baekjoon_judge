#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> vec;
    while (N--) {
        string word;
        cin >> word;

        vec.push_back(word);
    }

    for (vector<string>::size_type i = 0; i < vec.size() - 1; ++i) {
        string::size_type preferred_idx = i;

        for (string::size_type j = i + 1; j < vec.size(); ++j) {
            if (vec[j].size() < vec[preferred_idx].size())
                preferred_idx = j;
            else if (vec[j].size() == vec[preferred_idx].size()) {
                if (vec[j] < vec[preferred_idx])
                    preferred_idx = j;
            }
        }

        string temp = vec[preferred_idx];
        vec[preferred_idx] = vec[i];
        vec[i] = temp;
    }

    string prev = vec[0];
    cout << prev << '\n';
    for (string word : vec) {
        if (word != prev)
            cout << word << '\n';
        prev = word;
    }

    return 0;
}
