// Names of persons are saved in a list. Create function to check if the names are palindrome or not.


#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;
};

bool isPalindrome(Node* head) {
    std::string str = "";
    Node* current = head;
    while (current != nullptr) {
        str += current->data;
        current = current->next;
    }
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node{"race", new Node{"car", new Node{"madam", nullptr}}};
    std::cout << "List: ";
    printList(head);
    std::cout << "Is palindrome: " << isPalindrome(head) << std::endl;
    return 0;
}
