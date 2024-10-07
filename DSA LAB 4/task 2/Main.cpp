#include "Queue.cpp"

void reverseFirstKElements(Queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        cout << "Invalid value of K." << endl;
        return;
    }

    int* tempArray = new int[k];

    for (int i = 0; i < k; i++) {
        tempArray[i] = q.front();
        q.dequeue();
    }

    for (int i = k - 1; i >= 0; i--) {
        q.enqueue(tempArray[i]);
    }

    int remainingElements = q.size() - k;
    for (int i = 0; i < remainingElements; i++) {
        q.enqueue(q.front());
        q.dequeue();
    }

    delete[] tempArray;
}

void printQueue(Queue<int>& q) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        cout << q.front() << " ";
        q.enqueue(q.front());
        q.dequeue();
    }
    cout << endl;
}

int main() {
    Queue<int> q;

    for (int i = 1; i <= 8; i++) {
        q.enqueue(i);
    }

    cout << "Original queue: ";
    printQueue(q);

    int k = 4;
    reverseFirstKElements(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    printQueue(q);

    return 0;
}
