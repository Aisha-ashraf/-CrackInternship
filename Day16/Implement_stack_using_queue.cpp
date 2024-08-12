#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1; // Primary queue to hold elements in stack order
    queue<int> q2; // Auxiliary queue to assist in the push operation

    MyStack() {}
    
    // Push element x onto stack
    void push(int x) {
        q2.push(x); // Push element onto q2
        // Move all elements from q1 to q2 to maintain stack order
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap q1 and q2 so q1 has the stack elements in correct order
        swap(q1, q2);
    }
    
    // Removes the element on top of the stack and returns that element
    int pop() {
        if (q1.empty()) {
            return 0; // Return 0 or appropriate value if stack is empty
        }
        int x = q1.front(); // Get the top element
        q1.pop(); // Remove the top element
        return x;
    }
    
    // Get the top element
    int top() {
        return q1.front();
    }
    
    // Returns whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element is: " << stack.top() << endl; // Should print 3
    
    cout << "Popped element: " << stack.pop() << endl; // Should remove and print 3
    cout << "Top element is now: " << stack.top() << endl; // Should print 2
    
    stack.push(4);
    cout << "Top element after pushing 4: " << stack.top() << endl; // Should print 4
    
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print No
    
    stack.pop(); // Removes 4
    stack.pop(); // Removes 2
    stack.pop(); // Removes 1
    
    cout << "Is stack empty now? " << (stack.empty() ? "Yes" : "No") << endl; // Should print Yes
    
    return 0;
}
