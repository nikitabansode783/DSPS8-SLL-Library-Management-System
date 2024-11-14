#include <iostream>
using namespace std;

class LMS {
    string tt, aut, pub;
    int pz;
    LMS* next; // Pointer to the next node
public:
    LMS() : next(NULL) {} // Constructor to initialize next
    void accept();
    void display();
} *start = NULL, *temp = NULL; // Initialize pointers

void LMS::accept() {
    LMS* newn = new LMS; // Create a new book node
    cout << "Enter Title, Author, Publisher and Price of the Book: ";
    cin >> newn->tt >> newn->aut >> newn->pub >> newn->pz;
    newn->next = NULL; // Initialize next pointer to NULL

    if (start == NULL) {
        start = newn; // First book in the list
    } else {
        temp = start; // Start traversing from the beginning
        while (temp->next != NULL) { // Traverse until the end
            temp = temp->next;
        }
        temp->next = newn; // Link the new book
    }
}

void LMS::display() {
    temp = start; // Start from the beginning
    while (temp != NULL) {
        cout << "Title: " << temp->tt
             << ", Author: " << temp->aut
             << ", Publisher: " << temp->pub
             << ", Price: " << temp->pz << endl;
        temp = temp->next; // Move to the next book
    }
}

int main() {
    LMS S; // Create an instance of LMS
    int choice;
    do {
        cout << "1. Add Book\n2. Display Books\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                S.accept();
                break;
            case 2:
                S.display();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
