// COMSC-210 | Lab 19 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
#include <string>
using namespace std;

struct Node {
    double rating;
    string comment;
    Node *next;
};

// function prototypes
void addFront(Node *&, double, string);
void addTail(Node *&, double, string);
void output(Node *);

int main() {
    Node *head = nullptr;
    int choice;

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "\tChoice: ";
    cin >> choice;
    cin.ignore();

    char inputMore = 'Y';
    while (inputMore == 'Y' || inputMore == 'y') {
        double rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1)
            addFront(head, rating, comment);
        else
            addTail(head, rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> inputMore;
        cin.ignore();
    }

    output(head);

    return 0;
}

// addFront() adds a review node to head of linked list.
// arguments: head, rating, comment
// returns: nothing
void addFront(Node *&head, double rating, string comment) {
    Node *newNode = new Node;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    head = newNode;
}

// addTail() adds a review node to tail of linked list.
// arguments: head, rating, comment
// returns: nothing
void addTail(Node *&head, double rating, string comment) {
    Node *newNode = new Node;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node *current = head;
        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }
}

// output() traverses linked list, outputs reviews, and calculates average rating
// arguments: head
// returns: nothing
void output(Node *head) {
    Node* current = head;
    int count = 0;
    double total = 0;

    cout << "Outputting all reviews:" << endl;
    while (current != nullptr) {
        count++;
        cout << "\t> Review #" << count << ": " << current->rating
             << ": " << current->comment << endl;
        
        total += current->rating;
        current = current->next;
    }

    cout << "\t> Average: " << total / count << endl;
}