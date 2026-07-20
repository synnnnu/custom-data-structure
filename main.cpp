#include <iostream>
#include <string>
#include "basicDataStructure/Stack.h"
#include "basicDataStructure/Queue.h"
#include "basicDataStructure/CircularQueue.h"
#include "basicDataStructure/Deque.h"

using namespace std;

void testStack() {
    Stack<int, 5> intStack;
    intStack.push(10);
    intStack.push(20);

    int val;
    if (intStack.peek(val)) cout << "int top: " << val << endl;

    Stack<string, 3> strStack;
    strStack.push("hello");
    strStack.push("world");

    string sval;
    if (strStack.peek(sval)) cout << "string top: " << sval << endl;

    cout << "int stack size: " << intStack.size() << endl;
    cout << "string stack isFull: " << strStack.isFull() << endl;
}

void testQueue() {
    Queue<int, 5> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "5개 채움, isFull: " << q.isFull() << endl;

    q.dequeue();
    q.dequeue();
    cout << "2개 뺐음, count: " << q.size() << endl;
    cout << "isFull: " << q.isFull() << endl;

    bool ok = q.enqueue(6);
    cout << "enqueue(6) 결과: " << ok << endl;
}

void testCircularQueue() {
    CircularQueue<int, 5> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "5개 채움, isFull: " << q.isFull() << endl;  // true

    q.dequeue();
    q.dequeue();
    cout << "2개 뺐음, count: " << q.size() << endl;      // 3

    bool ok1 = q.enqueue(6);
    bool ok2 = q.enqueue(7);
    cout << "enqueue(6): " << ok1 << ", enqueue(7): " << ok2 << endl;  // 둘 다 true

    int val;
    q.peekFront(val);
    cout << "현재 front 값: " << val << endl;  // 3
}

void testDeque() {
    Deque<int, 5> dq;

    dq.pushBack(1);    // [1]
    dq.pushBack(2);    // [1, 2]
    dq.pushFront(0);   // [0, 1, 2]

    int val;
    dq.peekFront(val); cout << "front: " << val << endl;  // 0
    dq.peekBack(val);  cout << "back: " << val << endl;   // 2

    dq.popFront();      // [1, 2]
    dq.popBack();       // [1]
    dq.peekFront(val); cout << "front: " << val << endl;  // 1
    cout << "size: " << dq.size() << endl;                // 1
}

int main() {
    // testStack();
    // testQueue();
    // testCircularQueue();
    testDeque();
}