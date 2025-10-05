// COMSC-210 | Lab 19 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
#include <string>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
using namespace std;

class Movie {
private:
    struct Node {
        double rating;
        string comment;
        Node *next;
    };

    string title;
    Node *head;

public:
    // default constructor
    Movie(string movieTitle = "") {
        title = movieTitle;
        head = nullptr;
    }

    // addFront() adds a review node to head of linked list.
    // arguments: head, rating, comment
    // returns: nothing
    void addFront(double rating, string comment) {
        Node *newNode = new Node;
        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;
        head = newNode;
    }

    // output() traverses linked list, outputs reviews, and calculates average rating
    // arguments: head
    // returns: nothing
    void output() {
        Node *current = head;
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
};

int main() {
    srand(time(0));

    Movie movie1("Mamma Mia");

    char inputMore = 'Y';
    while (inputMore == 'Y' || inputMore == 'y') {
        double rating = (rand() % 41 + 10) / 10.0;
        string comment;

        cout << "Enter review comments: ";
        getline(cin, comment);

        movie1.addFront(rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> inputMore;
        cin.ignore();
    }

    movie1.output();

    return 0;
}