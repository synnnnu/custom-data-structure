#include <iostream>
#include <string>
#include "basicDataStructure/Stack.h"
#include "basicDataStructure/Queue.h"
#include "basicDataStructure/CircularQueue.h"

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

    bool ok1 = q.enqueue(6);   // rearIdx가 (5) % 5 = 0 이라 arr[0] 재활용!
    bool ok2 = q.enqueue(7);
    cout << "enqueue(6): " << ok1 << ", enqueue(7): " << ok2 << endl;  // 둘 다 true

    int val;
    q.peekFront(val);
    cout << "현재 front 값: " << val << endl;  // 3 (1, 2를 이미 뺐으니까)
}

int main() {
    // testStack();
    // testQueue();
    testCircularQueue();
}