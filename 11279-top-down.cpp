#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> max_heap(100000 + 1);
    vector<int>::size_type heap_size = 0;
    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (heap_size == 0) {
                cout << 0 << '\n';
                continue;
            }
            
            cout << max_heap[1] << '\n';
            if (--heap_size == 0)
                continue;

            int root = max_heap[heap_size + 1];
            vector<int>::size_type parent_idx = 1;
            while (parent_idx <= heap_size / 2) {
                vector<int>::size_type child_idx = parent_idx * 2;
                if (child_idx < heap_size && max_heap[child_idx] < max_heap[child_idx + 1])
                    ++child_idx;
                
                if (root >= max_heap[child_idx])
                    break;
                max_heap[parent_idx] = max_heap[child_idx];
                parent_idx = child_idx;
            }
            max_heap[parent_idx] = root;
        } else {
            max_heap[++heap_size] = x;

            vector<int>::size_type child_idx = heap_size;
            vector<int>::size_type parent_idx = child_idx / 2;
            while (parent_idx > 0 && x > max_heap[parent_idx]) {
                max_heap[child_idx] = max_heap[parent_idx];

                child_idx = parent_idx;
                parent_idx /= 2;
            }
            max_heap[child_idx] = x;
        }
    }

    return 0;
}
