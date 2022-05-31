#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;
        
        string x;
        cin >> x;

        istringstream strm(x.substr(1, x.size() - 2));
        deque<int> dq;
        while (getline(strm, x, ','))
            dq.push_back(stoi(x));

        bool back = false, is_error = false;
        for (string::size_type i = 0; i < p.size(); ++i) {
            string::value_type c = p[i];

            if (c == 'R')
                back = !back;
            else if (c == 'D') {
                if (dq.size() <= 0) {
                    is_error = true;
                    break;
                }

                if (!back)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (is_error)
            cout << "error\n";
        else {
            cout << '[';

            for (deque<int>::size_type i = dq.size(); i > 1; --i) {
                int number = 0;

                if (!back) {
                    number = dq.front();
                    
                    dq.pop_front();
                    dq.push_back(number);
                } else {
                    number = dq.back();

                    dq.pop_back();
                    dq.push_front(number);
                }

                cout << number << ',';
            }

            if (!dq.empty()) {
                if (!back)
                    cout << dq.front();
                else
                    cout << dq.back();
            }

            cout << "]\n";
        }
    }

    return 0;
}

