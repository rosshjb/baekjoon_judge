#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> count(4000 * 2 + 1, 0);
    vector<int> vec;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;

        sum += number;
        ++count[number + 4000];
        vec.push_back(number);
    }

    sort(vec.begin(), vec.end());

    // average
    double avg = (double)sum / N;
    cout << fixed << setprecision(0) << (abs(avg) < 0.5 ? 0 : avg) << '\n';
    
    // central number
    cout << vec[vec.size() / 2] << '\n';

    // frequent number
    vector<int> freqs;
    int max_count = *max_element(count.begin(), count.end());
    for (vector<int>::size_type i = 0; i < count.size(); ++i) {
        if (count[i] == max_count)
            freqs.push_back(i - 4000);
    }
    sort(freqs.begin(), freqs.end());
    if (freqs.size() > 1)
        cout << freqs[1] << '\n';
    else
        cout << freqs[0] << '\n';

    // range
    cout << vec[vec.size() - 1] - vec[0];

    return 0;
}
