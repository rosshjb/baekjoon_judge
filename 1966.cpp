#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<int> q;
        for (int i = 0; i < N; ++i) {
            int priority;
            cin >> priority;

            q.push(priority);
        }

        int count = 0;
        while (true) {
            int max_idx = 0;

            // find maximum priority
            int max_priority = q.front();
            q.pop();
            q.push(max_priority);
            
            for (queue<int>::size_type i = 1; i < q.size(); ++i) {
                int priority = q.front();
                if (priority > max_priority) {
                    max_priority = priority;
                    max_idx = i;
                }
                q.pop();
                q.push(priority);
            }

            if (max_idx == M) {
                ++count;
                break;
            }

            // jump to maximum priority
            for (int i = 0; i < max_idx; ++i) {
                int priority = q.front();
                q.pop();
                q.push(priority);
            }
            // pop maximum priority
            q.pop();

            // print doc
            ++count;

            M = (M - (max_idx + 1) + (q.size() + 1)) % (q.size() + 1);
        }

        cout << count << '\n';
    }

    return 0;
}

