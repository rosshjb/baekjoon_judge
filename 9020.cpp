#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<bool> primes(10000 + 1, true);
    for (int i = 2; i <= 5000; ++i) {
        for (int j = 2; i * j <= 10000; ++j) {
            primes[i * j] = false;
        }
    }

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        int left = N / 2, right = left;
        while (true) {
            while (!primes[left])
                --left;
            while (!primes[right])
                ++right;
            
            if (left + right < N)
                ++right;
            else if (left + right > N)
                --left;
            else
                break;
        }

        cout << left << " " << right << endl;
    }    

    return 0;
}
