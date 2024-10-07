#include "Queue.h"

template <typename T>
Queue<T>::Queue() : capacity(2), frontIndex(0), backIndex(-1), count(0) {
    elements = new T[capacity];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] elements;
}

template <typename T>
void Queue<T>::enqueue(T value) {
    if (count == capacity) {
        resize();
    }
    backIndex = (backIndex + 1) % capacity;
    elements[backIndex] = value;
    count++;
}

template <typename T>
void Queue<T>::dequeue() {
    if (!isEmpty()) {
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    } else {
        cout << "Queue is empty. Can't dequeue." << endl;
    }
}

template <typename T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return elements[frontIndex];
    }
    cout << "Queue is empty. No front element." << endl;
    return -1;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return count == 0;
}

template <typename T>
int Queue<T>::size() {
    return count;
}

template <typename T>
void Queue<T>::resize() {
    int newCapacity = capacity * 2;
    T* newElements = new T[newCapacity];

    for (int i = 0; i < count; i++) {
        newElements[i] = elements[(frontIndex + i) % capacity];
    }

    delete[] elements;
    elements = newElements;
    frontIndex = 0;
    backIndex = count - 1;
    capacity = newCapacity;
}
