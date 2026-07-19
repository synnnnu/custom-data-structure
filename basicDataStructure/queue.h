#ifndef QUEUE_H
#define QUEUE_H

template <typename T, int N = 100>
class Queue {
private:
    T arr[N];
    int count;
public:
    Queue() : count(0) {};

    bool enqueue(const T& value) {
        if (count == N) return false;

        arr[count] = value;
        count++;
        return true;
    }

    bool dequeue() {
        if (count == 0) return false;

        for (int i = 0; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
        return true;
    }

    bool peekFront(T& outValue) {
        if (count == 0) return false;

        outValue = arr[0];
        return true;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == N;
    }

    int size() {
        return count;
    }
};

#endif