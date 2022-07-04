#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K;
    cin >> K;

    vector<int> direction, length;
    vector<int> direction_count(4 + 1, 0);
    for (int i = 0; i < 6; ++i) {
        int dir;
        cin >> dir;
        direction.push_back(dir);

        ++direction_count[dir];

        int len;
        cin >> len;
        length.push_back(len);
    }

    // find max width and height
    int max_width = 0, max_height = 0;
    int max_width_idx = 0, max_height_idx = 0;
    for (int i = 0; i < 6; ++i) {
        if (direction[i] <= 2) {
            if (length[i] > max_width) {
                max_width = length[i];
                max_width_idx = i;
            }
        } else {
            if (length[i] > max_height) {
                max_height = length[i];
                max_height_idx = i;
            }
        }
    }

    int horizontal_count, vertical_count;
    // figure is stood
    if (direction_count[1] == direction_count[4] && direction_count[2] == direction_count[3]) {
        horizontal_count = 2;
        vertical_count = 1;
    } else /* figure is laid */ {
        horizontal_count = 1;
        vertical_count = 2;
    }

    int width_idx = (max_width_idx + 1) % direction.size();
    int exclude_width = 0;
    for (int i = 0; i < horizontal_count; ++i) {
        while (direction[width_idx] != 1 && direction[width_idx] != 2)
            width_idx = (width_idx + 1) % direction.size();
        width_idx = (width_idx + 1) % direction.size();
    }
    width_idx = (width_idx - 1 + direction.size()) % direction.size();
    exclude_width = length[width_idx];

    int height_idx = (max_height_idx + 1) % direction.size();
    int exclude_height = 0;
    for (int i = 0; i < vertical_count; ++i) {
        while (direction[height_idx] != 3 && direction[height_idx] != 4)
            height_idx = (height_idx + 1) % direction.size();
        height_idx = (height_idx + 1) % direction.size();
    }
    height_idx = (height_idx - 1 + direction.size()) % direction.size();
    exclude_height = length[height_idx];

    cout << (((length[max_width_idx] * length[max_height_idx]) - (exclude_width * exclude_height)) * K);

    return 0;
}
