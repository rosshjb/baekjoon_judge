#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        q.push(i);

    cout << '<';    
    for (int i = 0; i < N - 1; ++i) {
        for (int i = 1; i <= M - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        
        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << '>';

    return 0;
}
