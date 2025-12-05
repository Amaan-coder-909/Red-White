#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

const int MAX_ITEMS = 100;

// ---------------------------------------------------------
// ABSTRACT BASE CLASS: LibraryItem (Abstraction, Encapsulation)
// ---------------------------------------------------------
class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem() : title("N/A"), author("N/A"), dueDate("N/A") {}
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d) {}

    virtual ~LibraryItem() {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    // Setters
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    // Pure virtual functions (Abstraction + Polymorphism)
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

// ---------------------------------------------------------
// HELPER: Simple ISBN Validator (for Book)
// ---------------------------------------------------------
bool isValidISBN(const string& isbn) {
    if (isbn.length() != 10 && isbn.length() != 13) return false;
    for (char c : isbn) {
        if (!isdigit(static_cast<unsigned char>(c)))
            return false;
    }
    return true;
}

// ---------------------------------------------------------
// DERIVED CLASS: Book (Inheritance from LibraryItem)
// ---------------------------------------------------------
class Book : public LibraryItem {
private:
    string isbn;
    int quantity;

public:
    Book(string t, string a, string d, string isbnCode, int qty)
        : LibraryItem(t, a, d) {
        if (!isValidISBN(isbnCode)) {
            throw invalid_argument("Invalid ISBN format! (Must be 10 or 13 digits)");
        }
        if (qty < 0) {
            throw invalid_argument("Quantity cannot be negative!");
        }
        isbn = isbnCode;
        quantity = qty;
    }

    void checkOut() override {
        if (quantity <= 0) {
            throw runtime_error("No copies of this book are available to check out.");
        }
        quantity--;
        setDueDate("Due in 14 days");
        cout << "Book checked out successfully. Remaining copies: " << quantity << endl;
    }

    void returnItem() override {
        quantity++;
        setDueDate("Returned");
        cout << "Book returned successfully. Total copies: " << quantity << endl;
    }

    void displayDetails() const override {
        cout << "\n[BOOK]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

// ---------------------------------------------------------
// DERIVED CLASS: DVD (Inheritance from LibraryItem)
// ---------------------------------------------------------
class DVD : public LibraryItem {
private:
    int durationMinutes;
    bool isCheckedOut;

public:
    DVD(string t, string a, string d, int duration)
        : LibraryItem(t, a, d), durationMinutes(duration), isCheckedOut(false) {
        if (durationMinutes <= 0) {
            throw invalid_argument("DVD duration must be positive!");
        }
    }

    void checkOut() override {
        if (isCheckedOut) {
            throw runtime_error("This DVD is already checked out.");
        }
        isCheckedOut = true;
        setDueDate("Due in 7 days");
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override {
        if (!isCheckedOut) {
            throw runtime_error("This DVD was not checked out.");
        }
        isCheckedOut = false;
        setDueDate("Returned");
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() const override {
        cout << "\n[DVD]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Director: " << getAuthor() << endl; // using 'author' as director
        cout << "Duration: " << durationMinutes << " minutes\n";
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

// ---------------------------------------------------------
// DERIVED CLASS: Magazine (Inheritance from LibraryItem)
// ---------------------------------------------------------
class Magazine : public LibraryItem {
private:
    int issueNumber;
    bool isCheckedOut;

public:
    Magazine(string t, string a, string d, int issueNo)
        : LibraryItem(t, a, d), issueNumber(issueNo), isCheckedOut(false) {
        if (issueNumber <= 0) {
            throw invalid_argument("Issue number must be positive!");
        }
    }

    void checkOut() override {
        if (isCheckedOut) {
            throw runtime_error("This magazine is already checked out.");
        }
        isCheckedOut = true;
        setDueDate("Due in 3 days");
        cout << "Magazine checked out successfully.\n";
    }

    void returnItem() override {
        if (!isCheckedOut) {
            throw runtime_error("This magazine was not checked out.");
        }
        isCheckedOut = false;
        setDueDate("Returned");
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() const override {
        cout << "\n[MAGAZINE]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Publisher: " << getAuthor() << endl; // 'author' used as publisher
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

// ---------------------------------------------------------
// LMS Helper Functions
// ---------------------------------------------------------
int findItemByTitle(LibraryItem* items[], int count, const string& title) {
    for (int i = 0; i < count; ++i) {
        if (items[i]->getTitle() == title) {
            return i;
        }
    }
    return -1;
}

// ---------------------------------------------------------
// MAIN: Menu-driven Library Management System
// ---------------------------------------------------------
int main() {
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;

    try {
        int choice;

        while (true) {
            cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
            cout << "1. Add Item\n";
            cout << "2. Display All Items\n";
            cout << "3. Search Item by Title\n";
            cout << "4. Check Out Item\n";
            cout << "5. Return Item\n";
            cout << "6. Remove Item\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (!cin) {
                throw runtime_error("Invalid input! Exiting.");
            }

            if (choice == 7) break;

            try {
                if (choice == 1) {
                    if (itemCount >= MAX_ITEMS) {
                        cout << "Catalog is full. Cannot add more items.\n";
                        continue;
                    }

                    int type;
                    cout << "\nSelect Item Type to Add:\n";
                    cout << "1. Book\n2. DVD\n3. Magazine\n";
                    cout << "Enter type: ";
                    cin >> type;

                    string title, author, dueDate;
                    cout << "Enter Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter Author/Director/Publisher: ";
                    getline(cin, author);
                    dueDate = "N/A";

                    if (type == 1) {
                        string isbn;
                        int qty;
                        cout << "Enter ISBN (10 or 13 digits): ";
                        getline(cin, isbn);
                        cout << "Enter Quantity: ";
                        cin >> qty;

                        LibraryItem* item = new Book(title, author, dueDate, isbn, qty);
                        libraryItems[itemCount++] = item;
                        cout << "Book added successfully!\n";
                    }
                    else if (type == 2) {
                        int duration;
                        cout << "Enter Duration in minutes: ";
                        cin >> duration;

                        LibraryItem* item = new DVD(title, author, dueDate, duration);
                        libraryItems[itemCount++] = item;
                        cout << "DVD added successfully!\n";
                    }
                    else if (type == 3) {
                        int issueNo;
                        cout << "Enter Issue Number: ";
                        cin >> issueNo;

                        LibraryItem* item = new Magazine(title, author, dueDate, issueNo);
                        libraryItems[itemCount++] = item;
                        cout << "Magazine added successfully!\n";
                    }
                    else {
                        cout << "Invalid item type.\n";
                    }
                }
                else if (choice == 2) {
                    if (itemCount == 0) {
                        cout << "No items in the library catalog.\n";
                    } else {
                        cout << "\n--- Library Catalog ---\n";
                        for (int i = 0; i < itemCount; ++i) {
                            libraryItems[i]->displayDetails(); // Polymorphic call
                        }
                    }
                }
                else if (choice == 3) {
                    cin.ignore();
                    string title;
                    cout << "Enter title to search: ";
                    getline(cin, title);

                    int index = findItemByTitle(libraryItems, itemCount, title);
                    if (index == -1) {
                        cout << "Item not found.\n";
                    } else {
                        cout << "Item found:\n";
                        libraryItems[index]->displayDetails();
                    }
                }
                else if (choice == 4) {
                    cin.ignore();
                    string title;
                    cout << "Enter title to check out: ";
                    getline(cin, title);

                    int index = findItemByTitle(libraryItems, itemCount, title);
                    if (index == -1) {
                        cout << "Item not found.\n";
                    } else {
                        libraryItems[index]->checkOut(); // Polymorphic call
                    }
                }
                else if (choice == 5) {
                    cin.ignore();
                    string title;
                    cout << "Enter title to return: ";
                    getline(cin, title);

                    int index = findItemByTitle(libraryItems, itemCount, title);
                    if (index == -1) {
                        cout << "Item not found.\n";
                    } else {
                        libraryItems[index]->returnItem(); // Polymorphic call
                    }
                }
                else if (choice == 6) {
                    cin.ignore();
                    string title;
                    cout << "Enter title to remove: ";
                    getline(cin, title);

                    int index = findItemByTitle(libraryItems, itemCount, title);
                    if (index == -1) {
                        cout << "Item not found.\n";
                    } else {
                        delete libraryItems[index]; // free memory
                        for (int i = index; i < itemCount - 1; ++i) {
                            libraryItems[i] = libraryItems[i + 1];
                        }
                        itemCount--;
                        cout << "Item removed successfully.\n";
                    }
                }
                else {
                    cout << "Invalid choice. Try again.\n";
                }
            }
            catch (const invalid_argument& ex) {
                cout << "Input Error: " << ex.what() << endl;
            }
            catch (const runtime_error& ex) {
                cout << "Runtime Error: " << ex.what() << endl;
            }
            catch (const exception& ex) {
                cout << "Exception: " << ex.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred.\n";
            }
        }

        // Cleanup dynamically allocated memory
        for (int i = 0; i < itemCount; ++i) {
            delete libraryItems[i];
        }

        cout << "\nExiting Library Management System. Goodbye!\n";
    }
    catch (const exception& ex) {
        cout << "Fatal Error: " << ex.what() << endl;
    }
    catch (...) {
        cout << "A fatal unknown error occurred.\n";
    }

    return 0;
}
