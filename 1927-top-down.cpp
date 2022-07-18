#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> min_heap(100000 + 1);
    vector<int>::size_type heap_size = 0;
    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (heap_size == 0) {
                cout << 0 << '\n';
                continue;
            }
            
            cout << min_heap[1] << '\n';
            if (--heap_size == 0)
                continue;
            
            int root = min_heap[heap_size + 1];
            vector<int>::size_type parent_index = 1;
            while (parent_index <= heap_size / 2) {
                vector<int>::size_type child_index = parent_index * 2;
                if (child_index < heap_size && min_heap[child_index] > min_heap[child_index + 1])
                    ++child_index;

                if (root <= min_heap[child_index])
                    break;
                
                min_heap[parent_index] = min_heap[child_index];
                parent_index = child_index;
            }
            min_heap[parent_index] = root;

        } else {
            min_heap[++heap_size] = x;

            vector<int>::size_type child_index = heap_size;
            while (child_index / 2 > 0 && x < min_heap[child_index / 2]) {
                min_heap[child_index] = min_heap[child_index / 2];

                child_index /= 2;
            }
            min_heap[child_index] = x;
        }
    }
    
    return 0;
}
