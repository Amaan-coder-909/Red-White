#include <iostream>
using namespace std;

/* Node Structure */
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

/* Linked List Class */
class DynamicMemoryAllocation {
private:
    Node* head;

public:
    /* Constructor */
    DynamicMemoryAllocation() {
        head = NULL;
    }

    /* Append at end */
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    /* Insert at Beginning */
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    /* Display Linked List */
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    /* Search Element */
    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element not found\n";
    }

    /* Delete Node by Value */
    void delete_node(int key) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Node deleted\n";
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node not found\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Node deleted\n";
    }

    /* Reverse Linked List */
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
        cout << "Linked List Reversed\n";
    }
};

/* Main Function */
int main() {
    DynamicMemoryAllocation list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Linked List:\n";
    list.display();

    list.insert_at_beginning(5);
    cout << "\nAfter inserting at beginning:\n";
    list.display();

    list.search(20);

    list.delete_node(10);
    cout << "\nAfter deletion:\n";
    list.display();

    list.reverse();
    cout << "\nAfter reversing:\n";
    list.display();

    return 0;
}

