#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.get();

    for (int i = 0; i < N; ++i) {
        string s;
        getline(cin, s);
        
        istringstream sstream(s);
        getline(sstream, s, ',');
        int a = stoi(s);
        getline(sstream, s, ',');
        int b = stoi(s);
        
        cout << a + b << '\n';
    }

    return 0;
}
