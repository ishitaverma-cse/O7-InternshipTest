#include <iostream>
#include <string>
using namespace std;

// Book Class
class Book
{
private:
    // Fields
    string title;
    string author;
    bool isBorrowed;

public:
    Book()
    {
        title = "";
        author = "";
        isBorrowed = false;
    }
    Book(string t, string a)
    {
        title = t;
        author = a;
        isBorrowed = false;
    }
    string getTitle()
    { // Get Method 1
        return title;
    }
    string getAuthor()
    { // Get Method 2
        return author;
    }
    bool getIsBorrowed()
    { // Get Method 3
        return isBorrowed;
    }
    void setTitle(string t)
    { // Set Method 1
        title = t;
    }
    void setAuthor(string a)
    { // Set Method 2
        author = a;
    }
    void setIsBorrowed(bool status)
    { // Set Method 3
        isBorrowed = status;
    }
};

// Library Member Class
class LibraryMember
{
private:
    // Fields
    string name;
    int memberId;

public:
    LibraryMember()
    {
        name = "";
        memberId = 0;
    }
    LibraryMember(string n, int id)
    {
        name = n;
        memberId = id;
    }
    string getName()
    {
        return name;
    }
    int getMemberId()
    {
        return memberId;
    }

    void setName(string n)
    {
        name = n;
    }
    void setMemberId(int id)
    {
        memberId = id;
    }
};

// Library Class
class Library
{
private:
    // Fields
    Book books[100];
    LibraryMember members[100];
    int bookCount;
    int memberCount;

public:
    Library()
    {
        bookCount = 0;
        memberCount = 0;
    }

    // Add a new Book
    void addBook(Book b)
    {
        if (bookCount < 100)
        {
            books[bookCount++] = b;
            cout << "Book added successfully!" << endl;
        }
        else
        {
            cout << "Library is full!" << endl;
        }
    }

    // Register a member b
    void registerMember(LibraryMember m)
    {
        if (memberCount < 100)
        {
            members[memberCount++] = m;
            cout << "Members registered successfully!" << endl;
        }
        else
        {
            cout << "Member limit is reached!";
        }
    }

    // Borrow a book
    void borrowBook(string title, int memberId)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getTitle() == title)
            {
                if (books[i].getIsBorrowed())
                {
                    cout << "Error: Book already Borrowed!" << endl;
                    return;
                }
                books[i].setIsBorrowed(true);
                cout << "Book borrowed successfully by Member ID: " << memberId << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // return a book
    void returnBook(string title, int memberId)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getTitle() == title)
            {
                if (books[i].getIsBorrowed())
                {
                    cout << "Error: Book not Borrowed!" << endl;
                    return;
                }
                books[i].setIsBorrowed(false);
                cout << "Book returned successfully by Member ID: " << memberId << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

// Main Program
int main()
{
    Library library;
    // Initial books
    library.addBook(Book("C++ Basics", "Bjarne Stroupe"));
    library.addBook(Book("DSA", "xyz"));
    library.addBook(Book("OS", "abc"));

    // Initial members
    library.registerMember(LibraryMember("Alice", 101));
    library.registerMember(LibraryMember("Bob", 102));

    int choice;
    while (true)
    {
        cout << "\n Library Menu" << endl;
        cout << "1. Add Book\n2. Register Member\n3. Borrow Book\n4. Return Book\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string t, a;
            cout << "Enter book title: ";
            getline(cin, t);
            cout << "Enter author name: ";
            getline(cin, a);
            library.addBook(Book(t, a));
        }

        else if (choice == 2)
        {
            string n;
            int id;
            cout << "Enter member name: ";
            getline(cin, n);
            cout << "Enter member ID: ";
            cin >> id;
            cin.ignore();
            library.registerMember(LibraryMember(n, id));
        }

        else if (choice == 3)
        {
            string t;
            int id;
            cout << "Enter book title to borrow: ";
            getline(cin, t);
            cout << "Enter member ID: ";
            cin >> id;
            cin.ignore();
            library.borrowBook(t, id);
        }

        else if (choice == 4)
        {
            string t;
            int id;
            cout << "Enter book title to return: ";
            getline(cin, t);
            cout << "Enter member ID: ";
            cin >> id;
            cin.ignore();
            library.returnBook(t, id);
        }

        else if (choice == 5)
        {
            cout << "Exiting program..." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

