#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers;
    while (N--) {
        int number;
        cin >> number;

        numbers.push_back(number);
    }

    unordered_set<int> set;
    for (auto number : numbers)
        set.insert(number);

    vector<int> vec;
    for (auto i : set)
        vec.push_back(i);
    sort(vec.begin(), vec.end());

    unordered_map<int, vector<int>::size_type> map;
    for (vector<int>::size_type i = 0; i < vec.size(); ++i)
        map.insert({vec[i], i});
    
    for (auto number : numbers)
        cout << map[number] << ' ';

    return 0;
}
