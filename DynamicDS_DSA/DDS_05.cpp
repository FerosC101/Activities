#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    Book *next;
};

class BookList {
private:
    Book *head;

public:
    BookList() : head(nullptr) {}

    void addBook(string title, string author, string isbn) {
        Book *newBook = new Book;
        newBook->title = title;
        newBook->author = author;
        newBook->isbn = isbn;
        newBook->next = nullptr;

        if (head == nullptr) {
            head = newBook;
        } else {
            Book *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout << "Book added successfully.\n";
    }

    void removeBook(string isbn) {
        if (head == nullptr) {
            cout << "Book list is empty.\n";
            return;
        }

        Book *curr = head;
        Book *prev = nullptr;

        while (curr != nullptr && curr->isbn != isbn) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Book with ISBN " << isbn << " not found.\n";
        } else {
            if (prev == nullptr) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Book with ISBN " << isbn << " removed successfully.\n";
        }
    }

    void printBooks() {
        if (head == nullptr) {
            cout << "Book list is empty.\n";
            return;
        }

        Book *temp = head;
        int count = 1;
        cout << "List of books:\n";
        while (temp != nullptr) {
            cout << "Book " << count++ << ":\n";
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "ISBN: " << temp->isbn << endl << endl;
            temp = temp->next;
        }
    }

    ~BookList() {
        Book *temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void manageBookList() {
    BookList bookList;
    int choice;
    string title, author, isbn;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new book\n";
        cout << "2. Remove a book by ISBN\n";
        cout << "3. Print all books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter details for the new book:\n";
                cout << "Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "ISBN: ";
                getline(cin, isbn);
                bookList.addBook(title, author, isbn);
                break;
            case 2:
                cout << "Enter the ISBN of the book to remove: ";
                cin >> isbn;
                bookList.removeBook(isbn);
                break;
            case 3:
                bookList.printBooks();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    manageBookList();
    return 0;
}
