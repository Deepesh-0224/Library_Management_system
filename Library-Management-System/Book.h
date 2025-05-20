#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Book class representing a book in the library
class Book
{
    private:
        string isbn;            // Unique identifier for the book
        int copiesAvailable;    // Number of copies available for borrowing
        int totalCopies;        // Total number of copies the library has

    public:
        string title;           // Title of the book
        string author;          // Author of the book

        // Constructors
        Book(string, string, string, int, int);  // Parameterized constructor
        Book();                                  // Default constructor
        Book(Book&, string);                     // Copy constructor with new ISBN

        // Getters
        string getisbn();
        int getcopiesAvailable();
        int gettotalCopies();

        // Update copy count
        void updateCopies(int);

        // Borrow and return book methods
        bool borrowBook();
        bool returnBook();

        // Print book title and author
        void printDetails();
};

// Implementation of Book class methods
Book::Book(string ntitle,string nauthor,string nisbn,int nca,int ntc)
{
    title=ntitle;
    author=nauthor;
    isbn=nisbn;
    copiesAvailable=nca;
    totalCopies=ntc;
}

Book::Book()
{
    title="UnknownTitle";
    author="UnknownAuthor";
    isbn="ISBN";
    copiesAvailable=0;
    totalCopies=5;
}

Book::Book(Book& b,string isb)
{
    title=b.title;
    author=b.author;
    isbn=isb;
    copiesAvailable=b.copiesAvailable;
    totalCopies=b.totalCopies;
}

string Book::getisbn() { return isbn; }
int Book::getcopiesAvailable() { return copiesAvailable; }
int Book::gettotalCopies() { return totalCopies; }

void Book::updateCopies(int count)
{
    // Prevent invalid updates (negative values)
    if(copiesAvailable+count < 0 || totalCopies+count < 0)
    {
        cout << "Invalid request! Count becomes negative" <<endl;
        return;
    }
    copiesAvailable += count;
    totalCopies += count;
}

bool Book::borrowBook()
{
    // Check if available before borrowing
    if(copiesAvailable > 0)
    {
        copiesAvailable--;
        return true;
    }
    else
    {
        cout <<"Invalid request! Copy of book not available"<<endl;
        return false;
    }
}

bool Book::returnBook()
{
    // Only return if under total copies
    if(copiesAvailable < totalCopies)
    {
        copiesAvailable++;
        return true;
    }
    else
    {
        cout <<"Invalid request! Copy of book exceeds total copies"<<endl;
        return false;
    }
}

void Book::printDetails()
{
    cout<<title<<" "<<author<<" ";
}