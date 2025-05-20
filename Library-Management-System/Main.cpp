#include<Library_class.h>

int main()
{
    library li;
    string command;

    // Read and execute commands until "Done"
    while( cin>>command )
    {
        if(command == "Book")
        {
            string s1;
            cin >>s1;
            if(s1 == "None")
            {
                Book b;
                li.addBook(b);
            }
            else if(s1 == "ExistingBook")
            {
                string s13,s14;
                cin >>s13>>s14;
                Book* b=li.searchBook(s13);
                Book b1(*b,s14); // Copy book with new ISBN
                li.addBook(b1);
            }
            else
            {
                string s2,s3;
                int a,c;
                cin >>s2>>s3>>a>>c;
                Book b(s1,s2,s3,a,c);
                li.addBook(b);
            }
        }
        else if(command == "UpdateCopiesCount")
        {
            string s4;
            int d;
            cin >>s4>>d;
            Book* b1=li.searchBook(s4);
            b1->updateCopies(d);
        }
        else if(command == "Member")
        {
            string s5,s6;
            cin >>s5>>s6;
            if(s5 == "NoBorrowLimit")
            {
                string s20;
                cin >>s20;
                Member m(s6,s20);
                li.registerMember(m);
            }
            else
            {
                int e;
                cin >>e;
                Member m(s5,s6,e);
                li.registerMember(m);
            }
        }
        else if(command == "Borrow")
        {
            string s7,s8;
            cin >>s7>>s8;
            li.borrowBook(s7,s8);
        }
        else if(command == "Return")
        {
            string s9,s10;
            cin >>s9>>s10;
            li.returnBook(s9,s10);
        }
        else if(command == "PrintBook")
        {
            string s11;
            cin >>s11;
            Book* b=li.searchBook(s11);
            b->printDetails();
            cout <<endl;
        }
        else if(command == "PrintMember")
        {
            string s12;
            cin >>s12;
            Member* m=li.searchmember(s12);
            m->printDetails();
        }
        else if(command == "PrintLibrary")
        {
            li.printLibraryDetails();
        }
        else if(command == "Done")
        {
            break;
        }
    }
    return 0;
}
