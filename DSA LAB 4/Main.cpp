#include "Queue.cpp"

int main() {
    Queue<int> q;

    cout << "Inserting numbers into the queue:" << endl;
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
        cout << "Front: " << q.front() << ", Back: " << q.back() <<", Number Inserted: "<<i<< endl;
    }

    cout << "\nRemoving numbers from the queue:" << endl;
    while (!q.isEmpty()) {
        cout << "Front: " << q.front() << ", Back: " << q.back() <<", Number Remove: "<<q.front()<< endl;
        q.pop();
    }

    return 0;
}
