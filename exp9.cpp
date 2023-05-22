// TWo arrays are maintained in such a way that marks are descending order. 
// We need two reverse the two arrays using another data structure so, that the arrays are in ascending order.


#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void reverseArrays(int arr1[], int arr2[], int size) {
    stack<int> stack1, stack2;

    for (int i = 0; i < size; i++) {
        stack1.push(arr1[i]);
        stack2.push(arr2[i]);
    }

    for (int i = 0; i < size; i++) {
        arr1[i] = stack2.top();
        stack2.pop();
        arr2[i] = stack1.top();
        stack1.pop();
    }
}

int main() {
    int arr1[] = {5, 4, 3, 2, 1};
    int arr2[] = {10, 9, 8, 7, 6};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Arrays before reversing:" << endl;
    cout << "Array 1: ";
    for (int i = 0; i < size; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    reverseArrays(arr1, arr2, size);

    cout << "Arrays after reversing:" << endl;
    cout << "Array 1: ";
    for (int i = 0; i < size; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
