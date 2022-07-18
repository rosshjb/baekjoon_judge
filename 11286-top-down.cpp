#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> absolute_min_heap(100000 + 1);
    vector<int>::size_type heap_size = 0;
    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (heap_size == 0) {
                cout << 0 << '\n';
                continue;
            }
            
            cout << absolute_min_heap[1] << '\n';
            if (--heap_size == 0)
                continue;
            
            int root = absolute_min_heap[heap_size + 1];
            vector<int>::size_type parent_index = 1;
            while (parent_index <= heap_size / 2) {
                vector<int>::size_type child_index = parent_index * 2;
                
                if (child_index < heap_size) {
                    if (abs(absolute_min_heap[child_index]) > abs(absolute_min_heap[child_index + 1])
                        || (abs(absolute_min_heap[child_index]) == abs(absolute_min_heap[child_index + 1])
                            && absolute_min_heap[child_index] > absolute_min_heap[child_index + 1]))
                            ++child_index;
                }

                if (abs(root) < abs(absolute_min_heap[child_index])
                    || (abs(root) == abs(absolute_min_heap[child_index]) && root < absolute_min_heap[child_index]))
                    break;

                absolute_min_heap[parent_index] = absolute_min_heap[child_index];
                parent_index = child_index;
            }
            absolute_min_heap[parent_index] = root;
        } else {
            absolute_min_heap[++heap_size] = x;

            vector<int>::size_type child_index = heap_size;
            while (child_index / 2 >= 1) {
                if (abs(x) < abs(absolute_min_heap[child_index / 2])
                    || (abs(x) == abs(absolute_min_heap[child_index / 2]) && x < absolute_min_heap[child_index / 2])) {
                    absolute_min_heap[child_index] = absolute_min_heap[child_index / 2];

                    child_index /= 2;
                } else {
                    break;
                }
            }
            absolute_min_heap[child_index] = x;
        }
    }

    return 0;
}
