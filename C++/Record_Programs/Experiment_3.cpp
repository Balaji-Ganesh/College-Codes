/*Write a C++ program to declare a class. Declare pointer to class. Initialize and display the contents of the class member.
Output:
Book no : 1321  Name : C Programming    Price : 299.5                                                     
Book no : 4567  Name : C++ Programming  Price : 399.89  */


#include <iostream>
using namespace std;

class Book
{
    public:
        int bookid;
        string book_name;
        double book_price;
        
        Book(int id, string name, double price)
        {
            bookid = id;
            book_name = name;
            book_price = price;
        }
};

int main()
{
    Book book1(1321, "C Programming", 299.5);
    Book book2(4567, "C++ Programming", 399.89);
    
    Book *books = &book1;
    cout << "Book no :" << books->bookid <<"\tName : " << books->book_name <<"\tPrice :" << books->book_price << endl;
    books = &book2;
    cout << "Book no :" << books->bookid <<"\tName : " << books->book_name <<"\tPrice :" << books->book_price;
}