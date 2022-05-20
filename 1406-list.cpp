#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    list<char> char_list;
    for (char c : s)
        char_list.push_back(c);

    int M;
    cin >> M;
    cin.ignore();

    auto cursor = char_list.cend();
    for (int i = 0; i < M; ++i) {
        string command;
        getline(cin, command);

        switch (command[0]) {
        case 'L':
            if (cursor != char_list.cbegin())
                --cursor;
            break;
        case 'D':
            if (cursor != char_list.cend())
                ++cursor;
            break;
        case 'B':
            if (cursor != char_list.cbegin())
                cursor = char_list.erase(--cursor);
            break;
        case 'P':
            char_list.insert(cursor, command[2]);
            break;
        }
    }

    for (char c : char_list)
        cout << c;

    return 0;
}

