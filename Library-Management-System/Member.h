#include<Book_class.h>
#include<map>

// Member class representing a library member
class Member
{
    private:
        string name;                       // Member name
        string memberID;                   // Unique member ID
        map<string,int> borrowedBooks;     // Books currently borrowed by member
        int borrowlimit;                   // Max number of books allowed

    public:
        // Constructors
        Member(string,string,int);
        Member(string,string);

        // Getters
        string getmemberID();
        string getname();

        // Borrow and return book
        bool borrowBook(string);
        bool returnBook(string);

        // Print borrowing details
        void printDetails();
};

// Implementation of Member class
Member::Member(string id,string nam,int limit)
{
    memberID=id;
    name=nam;
    borrowlimit=limit;
}

Member::Member(string id,string nam)
{
    memberID=id;
    name=nam;
    borrowlimit=3; // default limit
}

string Member::getmemberID() { return memberID; }
string Member::getname() { return name; }

bool Member::borrowBook(string bid)
{
    // Check if within borrowing limit
    if(borrowedBooks.size() < borrowlimit)
    {
        borrowedBooks[bid]++;
        return true;
    }
    else
    {
        cout<<"Invalid request! Borrow limit exceeded"<<endl;
        return false;
    }
}

bool Member::returnBook(string bid)
{
    // Ensure book was actually borrowed
    if(borrowedBooks.find(bid) != borrowedBooks.end())
    {
        borrowedBooks[bid]--;
        if(borrowedBooks[bid]==0)
        {
            borrowedBooks.erase(bid); // Clean up if count becomes 0
        }
        return true;
    }
    else
    {
        cout<<"Invalid request! Book not borrowed"<<endl;
        return false;
    }
}

void Member::printDetails()
{
    for(auto itr = borrowedBooks.begin(); itr != borrowedBooks.end(); itr++)
    {
        cout <<memberID<<" "<<name<<" "<<itr->first<<" "<<itr->second<<endl;
    }
}