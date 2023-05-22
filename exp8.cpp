// list of marks obtained by students of your class is maintained in form of linkedlist. 
// Apply a sorting algorithm which has the complexity of O(n2) to sort the list



#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void bubbleSort() {
        if (head == nullptr || head->next == nullptr)
            return;

        bool swapped;
        Node* current;
        Node* previous = nullptr;

        do {
            swapped = false;
            current = head;

            while (current->next != previous) {
                if (current->data > current->next->data) {
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            previous = current;

        } while (swapped);
    }

private:
    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
};

int main() {
    LinkedList linkedList;
    linkedList.append(5);
    linkedList.append(2);
    linkedList.append(10);
    linkedList.append(1);
    linkedList.append(8);

    cout << "Original Linked List: ";
    linkedList.display();

    linkedList.bubbleSort();

    cout << "Sorted Linked List: ";
    linkedList.display();

    return 0;
}
