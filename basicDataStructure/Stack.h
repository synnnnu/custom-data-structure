#ifndef STACK_H
#define STACK_H

template <typename T, int N = 100>
class Stack {
private:
    T arr[N];
    int count;
public:
    Stack() : count(0) {} // 생성자

    bool push(const T& value) {
        if (count == N) return false;

        arr[count++] = value;
        return true;
    }

    bool pop() {
        if (count == 0) return false;
        
        count--;
        return true;
    }

    bool peek(T& outValue) {
        if (count == 0) return false;

        outValue = arr[count-1];
        return true;
    }

    bool isEmpty() {
        if (count == 0) return true;
    
        return false;
    }

    bool isFull() {
        if (count == N) return true;
    
        return false;
    }

    int size() {
        return count;
    }
};

#endif