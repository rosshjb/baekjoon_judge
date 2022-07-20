#include <iostream>

using namespace std;

int main() {
    int not_primes[1000000 + 1] = { true, true, };
    for (int i = 2; i * 2 <= 1000000; ++i) {
        for (int j = 2; i * j <= 1000000; ++j) {
            not_primes[i * j] = true;
        }
    }
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int count = 0;
        int left = N / 2, right = left;
        
        while (2 <= left && right <= 1000000) {
            if ((!not_primes[left] && !not_primes[right]) && (left + right == N))
                ++count;
            
            --left, ++right;
        }

        cout << count << '\n';
    }

    return 0;
}
