#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    size_t piece_count = 0, stick_count = 0;
    string::size_type latest_open = 0;
    for (string::size_type i = 0; i < s.size(); ++i) {
        string::value_type ch = s[i];

        if (ch == '(') {                /* stick or laser start */
            ++stick_count;
            latest_open = i;
        } else /* ')' */ {
            if (i - latest_open == 1) { /* laser */
                --stick_count;
                piece_count += stick_count;
            } else {                    /* stick end */
                --stick_count;
                ++piece_count;
            }
        }
    }

    cout << piece_count;

    return 0;
}
