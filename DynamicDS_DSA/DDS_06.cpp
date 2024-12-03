#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    bool available;
};

struct Member {
    string name;
    int id;
    vector<Book*> borrowedBooks;
};

class LibrarySystem {
private:
    vector<Book*> books;
    vector<Member*> members;
    int nextMemberID;

public:
    LibrarySystem() : nextMemberID(1) {}

    void addBook(string title, string author) {
        Book *newBook = new Book;
        newBook->title = title;
        newBook->author = author;
        newBook->available = true;
        books.push_back(newBook);
        cout << "Book added to the library.\n";
    }

    void registerMember(string name) {
        Member *newMember = new Member;
        newMember->name = name;
        newMember->id = nextMemberID++;
        members.push_back(newMember);
        cout << "Member registered successfully. Member ID: " << newMember->id << endl;
    }

    void borrowBook(int memberID, string bookTitle) {
        Member *member = findMember(memberID);
        if (member == nullptr) {
            cout << "Member with ID " << memberID << " not found.\n";
            return;
        }

        Book *book = findBook(bookTitle);
        if (book == nullptr) {
            cout << "Book with title \"" << bookTitle << "\" not found.\n";
            return;
        }

        if (!book->available) {
            cout << "Book with title \"" << bookTitle << "\" is not available for borrowing.\n";
            return;
        }

        member->borrowedBooks.push_back(book);
        book->available = false;
        cout << "Book \"" << bookTitle << "\" borrowed successfully by Member ID " << memberID << ".\n";
    }

    void returnBook(int memberID, string bookTitle) {
        Member *member = findMember(memberID);
        if (member == nullptr) {
            cout << "Member with ID " << memberID << " not found.\n";
            return;
        }

        bool found = false;
        for (size_t i = 0; i < member->borrowedBooks.size(); ++i) {
            if (member->borrowedBooks[i]->title == bookTitle) {
                member->borrowedBooks[i]->available = true;
                member->borrowedBooks.erase(member->borrowedBooks.begin() + i);
                cout << "Book \"" << bookTitle << "\" returned successfully by Member ID " << memberID << ".\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Member ID " << memberID << " has not borrowed \"" << bookTitle << "\".\n";
        }
    }

    void printLibrary() {
        cout << "\nLibrary Details:\n";
        cout << "Books:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << "Book " << i + 1 << ":\n";
            cout << "Title: " << books[i]->title << endl;
            cout << "Author: " << books[i]->author << endl;
            cout << "Availability: " << (books[i]->available ? "Available" : "Not Available") << endl << endl;
        }
        cout << "Members:\n";
        for (size_t i = 0; i < members.size(); ++i) {
            cout << "Member " << i + 1 << ":\n";
            cout << "ID: " << members[i]->id << endl;
            cout << "Name: " << members[i]->name << endl;
            cout << "Borrowed Books:\n";
            for (size_t j = 0; j < members[i]->borrowedBooks.size(); ++j) {
                cout << "  " << members[i]->borrowedBooks[j]->title << endl;
            }
            cout << endl;
        }
    }

    ~LibrarySystem() {
        for (size_t i = 0; i < books.size(); ++i) {
            delete books[i];
        }
        for (size_t i = 0; i < members.size(); ++i) {
            delete members[i];
        }
    }

private:
    Member* findMember(int id) {
        for (size_t i = 0; i < members.size(); ++i) {
            if (members[i]->id == id) {
                return members[i];
            }
        }
        return nullptr;
    }

    Book* findBook(string title) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i]->title == title) {
                return books[i];
            }
        }
        return nullptr;
    }
};

void manageLibrary() {
    LibrarySystem library;
    int choice;
    string title, author, name, bookTitle;
    int memberID;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new book\n";
        cout << "2. Register a new member\n";
        cout << "3. Borrow a book\n";
        cout << "4. Return a book\n";
        cout << "5. Print library details\n";
        cout << "6. Exit\n";
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
                library.addBook(title, author);
                break;
            case 2:
                cout << "Enter name of the new member: ";
                cin.ignore();
                getline(cin, name);
                library.registerMember(name);
                break;
            case 3:
                cout << "Enter member ID: ";
                cin >> memberID;
                cout << "Enter title of book to borrow: ";
                cin.ignore();
                getline(cin, bookTitle);
                library.borrowBook(memberID, bookTitle);
                break;
            case 4:
                cout << "Enter member ID: ";
                cin >> memberID;
                cout << "Enter title of book to return: ";
                cin.ignore();
                getline(cin, bookTitle);
                library.returnBook(memberID, bookTitle);
                break;
            case 5:
                library.printLibrary();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    manageLibrary();
    return 0;
}
