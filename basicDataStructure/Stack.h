#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int arr[100];
    int count;
    int capacity;
public:
    Stack(int cap = 100); // 생성자
    bool push(int value);        // 성공 true / 가득 참 false
    bool pop();                  // 제거만 함, 값은 리턴 안 함
    int peek();    // 
    bool isEmpty();
    bool isFull();
    int size();
};

#endif