// COMSC-210 | Lab 19 | Jasmine Suarez
// IDE used: VS Code

// NOTE: I used ai to generate random reviews to put into reviews.txt

#include <iostream>
#include <string>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include <fstream> // file input
#include <vector>
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

    // reviewsFile() reads reviews from txt file and randomizes ratings
    // arguments: filename, numReviews
    // returns: nothing
    void reviewsFile(string filename, int numReviews) {
        ifstream fin(filename);

        string comment;
        if (fin.good()) {
            while (getline(fin, comment)) {
                double rating = (rand() % 41 + 10) / 10.0;
                addFront(rating, comment);
            }
            fin.close();
        }
        else
            cout << "Input file not found.\n";
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

    vector<Movie> movies = {
        Movie("Wicked"),
        Movie("The Conjuring"),
        Movie("Shrek"),
        Movie("Crazy Rich Asians")
    };

    for (auto &m : movies)
        m.reviewsFile("reviews.txt", 3);

    for (auto &m : movies)
        m.output();

    return 0;
}