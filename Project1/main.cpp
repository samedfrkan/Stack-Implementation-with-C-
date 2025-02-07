#include <iostream>
#include <queue>
using namespace std;

// Stack class implementation using Queue data structure
class Stack {
private:
    queue<int> q1, q2;  // Two queues to implement stack behavior

public:
    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }

    // Return the current size of stack
    int size() {
        return q1.size();
    }

    // Return the top element of stack
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    // Push an element to the top of stack
    void push(int x) {
        // Push element to empty queue q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 to maintain stack order
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Remove the top element from stack
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        q1.pop();
    }

    // Display all elements in stack from last in to first in
    void display() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        queue<int> temp = q1;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice = 0;

    // Main menu loop
    while (choice != -1) {
        cout << "\n=== Stack Operations Menu ===" << endl;
        cout << "1. Push elements" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Get top element" << endl;
        cout << "4. Get stack size" << endl;
        cout << "5. Display stack" << endl;
        cout << "6. Check if stack is empty" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter numbers to push (enter -1 to stop):" << endl;
            int x;
            while (true) {
                cout << "Enter number: ";
                cin >> x;
                if (x == -1) break;
                stack.push(x);
                cout << x << " pushed to stack" << endl;
            }
            break;
        }
        case 2: {
            stack.pop();
            cout << "Top element popped" << endl;
            break;
        }
        case 3: {
            int topElement = stack.top();
            if (topElement != -1) {
                cout << "Top element: " << topElement << endl;
            }
            break;
        }
        case 4: {
            cout << "Stack size: " << stack.size() << endl;
            break;
        }
        case 5: {
            stack.display();
            break;
        }
        case 6: {
            cout << "Stack is " << (stack.empty() ? "empty" : "not empty") << endl;
            break;
        }
        case 0: {
            cout << "Exiting program..." << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice! Please try again." << endl;
        }
        }
    }

    return 0;
}