#include<Member_class.h>

// Library class managing all books and members
class library
{
    private:
        vector<Book>books;       // All books in library
        vector<Member>members;   // All registered members

    public:
        bool addBook(Book&);
        bool registerMember(Member&);
        bool borrowBook(string,string);
        bool returnBook(string,string);
        void printLibraryDetails();
        Book* searchBook(string);
        Member* searchmember(string);
};

bool library::addBook(Book& b)
{
    // Avoid duplicate ISBNs
    for(int i = 0; i < books.size(); i++)
    {
        if(books[i].getisbn() == b.getisbn())
        {
            cout <<"Invalid request! Book with same isbn already exists"<<endl;
            return false;
        }
    }
    books.push_back(b);
    return true;
}

bool library::registerMember(Member& m)
{
    // Avoid duplicate members
    for(int i = 0; i < members.size(); i++)
    {
        if(members[i].getmemberID() == m.getmemberID())
        {
            cout<<"Invalid request! Member with same id already exists"<<endl;
            return false;
        }
    }
    members.push_back(m);
    return true;
}

bool library::borrowBook(string memberID, string isbn)
{
    // Find the book and member
    int i=0,j=0;
    for(;i<books.size();i++)
        if(books[i].getisbn() == isbn) break;
    for(;j<members.size();j++)
        if(members[j].getmemberID()==memberID) break;

    // If book is available and member can borrow, update both
    if(books[i].getcopiesAvailable())
    {
        if(members[j].borrowBook(isbn))
        {
            books[i].borrowBook();
            return true;
        }
        else return false;
    }
    else return books[i].borrowBook();  // Triggers error
}

bool library::returnBook(string memberID, string isbn)
{
    // Find the book and member
    int i=0,j=0;
    for(;i<books.size();i++)
        if(books[i].getisbn() == isbn) break;
    for(;j<members.size();j++)
        if(members[j].getmemberID() == memberID) break;

    // If return is valid, update both book and member
    if(books[i].getcopiesAvailable() < books[i].gettotalCopies())
    {
        if(members[j].returnBook(isbn))
        {
            books[i].returnBook();
            return true;
        }
        else return false;
    }
    else return books[i].returnBook();  // Triggers error
}

void library::printLibraryDetails()
{
    // Print book details
    for(int i=0; i<books.size(); i++)
    {
        books[i].printDetails();
        cout <<books[i].getcopiesAvailable();
        cout <<endl;
    }
    // Print member details
    for(int i=0; i<members.size(); i++)
    {
        cout <<members[i].getmemberID()<<" "<<members[i].getname()<<endl;
    }
}

Book* library::searchBook(string isbn)
{
    // Find book by ISBN
    for(int i=0; i<books.size(); i++)
        if(books[i].getisbn() == isbn) return &books[i];
    return nullptr;
}

Member* library::searchmember(string memberID)
{
    // Find member by ID
    for(int i=0; i < members.size(); i++)
        if(members[i].getmemberID() == memberID) return &members[i];
    return nullptr;
}