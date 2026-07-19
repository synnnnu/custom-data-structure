#include <iostream>
#include <string>
#include "basicDataStructure/Stack.h"

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

int main() {
    testStack();
}