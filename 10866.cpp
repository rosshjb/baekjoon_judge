#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int deque[10000 + 1];
    const int capacity = sizeof deque / sizeof deque[0];
    int front = 0, rear = 0;
    while (N-- > 0) {
        string command;
        cin >> command;

        if (command == "push_front") {
            string s;
            cin >> s;

            deque[front] = stoi(s);
            front = (front - 1 + capacity) % capacity;
        } else if (command == "push_back") {
            string s;
            cin >> s;

            rear = (rear + 1) % capacity;
            deque[rear] = stoi(s);
        } else if (command == "pop_front") {
            if (front == rear)
                cout << -1 << '\n';
            else {
                front = (front + 1) % capacity;
                cout << deque[front] << '\n';
            }
        } else if (command == "pop_back") {
            if (rear == front)
                cout << -1 << '\n';
            else {
                cout << deque[rear] << '\n';
                rear = (rear - 1 + capacity) % capacity;
            }
        } else if (command == "size") {
            int count = 0;

            int it = front;
            while (it != rear) {
                ++count;
                it = (it + 1) % capacity;
            }

            cout << count << '\n';
        } else if (command == "empty") {
            cout << (front == rear) << '\n';
        } else if (command == "front") {
            if (front == rear)
                cout << -1 << '\n';
            else
                cout << deque[(front + 1) % capacity] << '\n';
        } else if (command == "back") {
            if (front == rear)
                cout << -1 << '\n';
            else
                cout << deque[rear] << '\n';
        }
    }

    return 0;
}
