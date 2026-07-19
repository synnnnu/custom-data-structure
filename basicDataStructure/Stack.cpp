#include "Stack.h"

Stack::Stack(int cap) : count(0), capacity(cap) {}

bool Stack::push(int value) {
    if (count == capacity) return false;
    
    arr[count++] = value;
    return true;
}

bool Stack::pop() {
    if (count == 0) return false;
        
    count--;
    return true;
}

int Stack::peek() {
    if (count == 0) return -1;
    
    return arr[count-1];
}

bool Stack::isEmpty() {
    if (count == 0) return true;
    
    return false;
}

bool Stack::isFull() {
    if (count == capacity) return true;
    
    return false;
}

int Stack::size() {
    return count;
}