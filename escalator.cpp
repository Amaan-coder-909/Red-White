#include <iostream>
using namespace std;

/* Base Class */
class Stack {
protected:
    int arr[5];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    virtual void push(int value) {
        if (isFull()) {
            cout << "Stack is Full\n";
            return;
        }
        arr[++topIndex] = value;
        cout << "Pushed: " << value << endl;
    }

    virtual void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Popped: " << arr[topIndex--] << endl;
    }

    virtual void top() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top Element: " << arr[topIndex] << endl;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 4;
    }
};

/* Derived Class */
class EscalatorStack : public Stack {
public:
    void push(int value) override {
        cout << "[Escalator Push] ";
        Stack::push(value);
    }

    void pop() override {
        cout << "[Escalator Pop] ";
        Stack::pop();
    }

    void top() override {
        cout << "[Escalator Top] ";
        Stack::top();
    }
};

/* Main Function */
int main() {
    EscalatorStack s;
    int choice, value;

    do {
        cout << "\n--- Escalator Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display Top\n4. Check Empty\n5. Check Full\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.top();
                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is Empty\n";
                else
                    cout << "Stack is Not Empty\n";
                break;

            case 5:
                if (s.isFull())
                    cout << "Stack is Full\n";
                else
                    cout << "Stack is Not Full\n";
                break;

            case 6:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 6);

    return 0;
}

