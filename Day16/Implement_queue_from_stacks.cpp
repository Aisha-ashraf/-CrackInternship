#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;  // Stack to handle the input
    stack<int> output; // Stack to handle the output

public:
    MyQueue() {}
    
    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }
    
    // Removes the element from in front of queue and returns that element
    int pop() {
        peek(); // Ensure the output stack has the current front of the queue
        int c = output.top(); // Get the top element
        output.pop(); // Remove the top element
        return c;
    }
    
    // Get the front element
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top()); // Move elements from input stack to output stack
                input.pop();
            }
        }
        return output.top(); // Return the front element
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return input.empty() && output.empty(); // Check if both stacks are empty
    }
};

int main() {
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    cout << "Front element is: " << queue.peek() << endl; // Should print 1
    
    cout << "Element removed: " << queue.pop() << endl; // Should remove and print 1
    cout << "Front element is now: " << queue.peek() << endl; // Should print 2
    
    queue.push(4);
    cout << "Element removed: " << queue.pop() << endl; // Should remove and print 2
    cout << "Front element is now: " << queue.peek() << endl; // Should print 3
    
    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Should print No
    
    queue.pop(); // Removes 3
    queue.pop(); // Removes 4
    
    cout << "Is queue empty now? " << (queue.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}
