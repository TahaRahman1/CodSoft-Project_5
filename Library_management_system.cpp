// Taha Rahman

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool checkedOut;
};

struct Borrower {
    string name;
    int borrowedBooks;
};

void displayMenu();
void addBook(vector<Book> &library);
void searchBook(const vector<Book> &library);
void checkOutBook(vector<Book> &library, vector<Borrower> &borrowers);
void returnBook(vector<Book> &library, vector<Borrower> &borrowers);
void calculateFine(const vector<Book> &library);
void displayBooks(const vector<Book> &library);

int main() {
    vector<Book> library;
    vector<Borrower> borrowers;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                searchBook(library);
                break;
            case 3:
                checkOutBook(library, borrowers);
                break;
            case 4:
                returnBook(library, borrowers);
                break;
            case 5:
                calculateFine(library);
                break;
            case 6:
                displayBooks(library);
                break;
            case 7:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\n=== Library Management System ===\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Check Out Book\n";
    cout << "4. Return Book\n";
    cout << "5. Calculate Fine\n";
    cout << "6. Display Books\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void addBook(vector<Book> &library) {
    Book newBook;
    cout << "Enter title: ";
    cin.ignore(); 
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    getline(cin, newBook.ISBN);
    newBook.checkedOut = false;
    library.push_back(newBook);
    cout << "Book added successfully.\n";
}


void searchBook(const vector<Book> &library) {
    string searchTerm;
    cout << "Enter search term (title, author, or ISBN): ";
    cin >> searchTerm;

    bool found = false;
    for (const Book &book : library) {
        if (book.title == searchTerm || book.author == searchTerm || book.ISBN == searchTerm) {
            cout << "Book found:\n";
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.ISBN << endl;
            cout << "Checked Out: " << (book.checkedOut ? "Yes" : "No") << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}

void checkOutBook(vector<Book> &library, vector<Borrower> &borrowers) {
    string ISBN;
    cout << "Enter ISBN of the book to check out: ";
    cin >> ISBN;

    auto it = find_if(library.begin(), library.end(), [&](const Book &book) {
        return book.ISBN == ISBN && !book.checkedOut;
    });

    if (it != library.end()) {
        it->checkedOut = true;
        cout << "Book checked out successfully.\n";
    } else {
        cout << "Book not available for checkout.\n";
    }
}

void returnBook(vector<Book> &library, vector<Borrower> &borrowers) {
    string ISBN;
    cout << "Enter ISBN of the book to return: ";
    cin >> ISBN;

    auto it = find_if(library.begin(), library.end(), [&](const Book &book) {
        return book.ISBN == ISBN && book.checkedOut;
    });

    if (it != library.end()) {
        it->checkedOut = false;
        cout << "Book returned successfully.\n";
    } else {
        cout << "Invalid ISBN or book already returned.\n";
    }
}

void calculateFine(const vector<Book> &library) {
    cout << "Fine calculation feature not implemented yet.\n";
}

void displayBooks(const vector<Book> &library) {
    cout << "=== Library Books ===\n";
    for (const Book &book : library) {
        cout << "Title: " << book.title << " | Author: " << book.author << " | ISBN: " << book.ISBN << " | Checked Out: " << (book.checkedOut ? "Yes" : "No") << endl;
    }
}
