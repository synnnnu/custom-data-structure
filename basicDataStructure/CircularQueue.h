#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

template <typename T, int N = 100>
class CircularQueue {
private:
    T arr[N];
    int count;
    int frontIdx;
    int rearIdx;
public:
    CircularQueue() : count(0), frontIdx(0), rearIdx(0) {}

    bool enqueue(const T& value) {
        if (count == N) return false;

        arr[rearIdx] = value;
        rearIdx = (rearIdx + 1) % N;
        count++;

        return true;
    }

    bool dequeue() {
        if (count == 0) return false;

        frontIdx = (frontIdx + 1) % N;
        count--;

        return true;
    }

    bool peekFront(T& outValue) {
        if (count == 0) return false;

        outValue = arr[frontIdx];
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