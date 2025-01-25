#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int availableCopies;

public:
    Book(string title, string author, int availableCopies)
    {
        this->title = title;
        this->author = author;
        this->availableCopies = availableCopies;
    }

    void setTitle(string title)
    {
        this->title = title;
    }

    void setAuthor(string author)
    {
        this->author = author;
    }

    void setAvailableCopies(int availableCopies)
    {
        this->availableCopies = availableCopies;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    int getAvailableCopies()
    {
        return availableCopies;
    }
};

class Member
{
private:
    string name;
    int borrowedBooksCount;
    vector<Book> borrowedBooks;

public:
    Member(string name)
    {
        this->name = name;
        borrowedBooksCount = 0;
    }

    void borrowBook(Book book)
    {
        if (book.getAvailableCopies() == 0)
        {
            cout << "No available copies of the book " << endl;
            return;
        }
        borrowedBooks.push_back(book);
        borrowedBooksCount++;
        book.setAvailableCopies(book.getAvailableCopies() - 1);
    }

    void returnBook(Book book)
    {
        for (int i = 0; i < borrowedBooks.size(); i++)
        {
            if (borrowedBooks[i].getTitle() == book.getTitle())
            {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                borrowedBooksCount--;
                book.setAvailableCopies(book.getAvailableCopies() + 1);
                break;
            }
        }
    }

    string getName()
    {
        return name;
    }

    int getBorrowedBooksCount()
    {
        return borrowedBooksCount;
    }
};

int main()
{
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 3);
    Book book2("To Kill a Mockingbird", "Harper Lee", 2);

    Member member1("John");
    Member member2("Alice");

    member1.borrowBook(book1);
    member1.borrowBook(book2);

    member2.borrowBook(book1);
    member2.borrowBook(book2);

    cout << "John borrowed " << member1.getBorrowedBooksCount() << " books" << endl;
    cout << "Alice borrowed " << member2.getBorrowedBooksCount() << " books" << endl;

    member1.returnBook(book1);
    member2.returnBook(book2);

    cout << "John borrowed " << member1.getBorrowedBooksCount() << " books" << endl;
    cout << "Alice borrowed " << member2.getBorrowedBooksCount() << " books" << endl;

    return 0;
}