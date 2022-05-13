#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B;
    
    cin >> A >> B;

    int length_diff = A.size() - B.size();
    if (A.size() < B.size()) {
        length_diff = B.size() - A.size();

        string temp = A;
        A = B;
        B = temp;
    }

    string result;
    int carry = 0;
    for (int i = A.size() - 1; i >= length_diff; --i) {
        int a = A[i] - '0';
        int b = B[i - length_diff] - '0';

        int sum = a + b + carry;
        if (sum >= 10)
            carry = 1;
        else
            carry = 0;
        
        result.insert(0, 1, (sum % 10) + '0');
    }

    for (int i = length_diff - 1; i >= 0; --i) {
        int a = A[i] - '0';
        a = a + carry;

        if (a >= 10)
            carry = 1;
        else
            carry = 0;

        result.insert(0, 1, (a % 10) + '0');
    }

    if (carry)
        result.insert(0, 1, '1');
    
    cout << result;

    return 0;
}
