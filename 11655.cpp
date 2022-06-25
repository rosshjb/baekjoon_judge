#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    for (auto ch : line) {
        int c = ch; // for a value greater than 127

        if ('a' <= ch && ch <= 'z') {
            c += 13;
            if (c > 'z')
                c = 'a' + (c - 'z' - 1);
        } else if ('A' <= ch && ch <= 'Z') {
            c += 13;
            if (c > 'Z')
                c = 'A' + (c - 'Z' - 1);
        }

        cout << ((char)c);
    }

    return 0;
}
