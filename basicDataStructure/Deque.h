#ifndef DEQUE_H
#define DEQUE_H

template <typename T, int N = 100>
class Deque {
private:
    T arr[N];
    int count;
    int frontIdx;
    int rearIdx;
public:
    Deque() : count(0), frontIdx(0), rearIdx(0) {}

    bool pushFront(const T& value) {
        if (count >= N) return false;

        frontIdx = (frontIdx - 1 + N) % N;
        arr[frontIdx] = value;
        count++;

        return true;
    }

    bool pushBack(const T& value) {
        if (count >= N) return false;

        arr[rearIdx] = value;
        rearIdx = (rearIdx + 1) % N;
        count++;

        return true;
    }

    bool popFront() {
        if (count <= 0) return false;

        frontIdx = (frontIdx + 1) % N;
        count--;
        
        return true;
    }

    bool popBack() {
        if (count <= 0) return false;

        rearIdx = (rearIdx - 1 + N) % N;
        count--;

        return true;
    }

    bool peekFront(T& outValue) {
        if (count <= 0) return false;

        outValue = arr[frontIdx];
        return true;
    }

    bool peekBack(T& outValue) {
        if (count <= 0) return false;

        outValue = arr[(rearIdx - 1 + N) % N];
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