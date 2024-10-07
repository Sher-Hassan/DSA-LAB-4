#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class Queue {
private:
    T* elements;
    int capacity;
    int frontIndex;
    int backIndex;
    int count;

    void resize();

public:
    Queue();
    ~Queue();
    void enqueue(T value);
    void dequeue();
    T front();
    bool isEmpty();
    int size();
};

#endif
