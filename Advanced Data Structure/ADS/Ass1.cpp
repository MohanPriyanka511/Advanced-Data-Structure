/*

1. A library needs to manage a collection of books (data fields such as book titleauthor, ISBN, availability
status, and other relevant information), maintain information about each book, support operations like
adding, removing, and searching for books, and provide efficient access to library resources. Use the
Concept of Linked List for implementation of Library Management system

*/
#include <iostream>
using namespace std;

class Book
{
public:
    int b_id, price, isbn;
    string b_name, a_name, p_name;
    Book *next;
    void accept();
    void display();
    void search();
    void Delete();
    void update();
} *start = NULL, *end1 = NULL;

void Book::accept()
{
    Book *new_book = new Book();
    cout << "Enter Book Id ,Book Name ,Author Name ,Publication Name ,ISBN ,Price :" << endl;
    cin >> new_book->b_id;
    cin >> new_book->b_name;
    cin >> new_book->a_name;
    cin >> new_book->p_name;
    cin >> new_book->isbn;
    cin >> new_book->price;
    new_book->next = NULL;
    if (start == NULL)
    {
        start = new_book;
        end1 = new_book;
    }
    else
    {
        end1->next = new_book;
        end1 = new_book;
    }
}

void Book ::display()
{
    if (start == NULL)
    {
        cout << "Book Record not found!" << endl;
    }
    else
    {
        Book *temp = start;
        cout << "BID\tBName\t AName\t PName\t ISBN\tPrice" << endl;
        while (temp != NULL)
        {
            cout << temp->b_id << " \t" << temp->b_name << "\t" << temp->a_name << "\t"
                 << temp->p_name << "\t" << temp->isbn << "\t" << temp->price << "\n";
            temp = temp->next;
        }
    }
}

void Book ::search()
{
    int sid, fl = 0;
    cout << "Enter Book Id to search : ";
    cin >> sid;
    Book *temp = start;
    while (temp != NULL)
    {
        if (sid == temp->b_id)
        {
            cout << "Book found with book id " << sid << " as follows : " << endl;
            cout << "BID \t BName \t AName \t PName \t ISBN \t Price" << endl;
            cout << temp->b_id << " \t" << temp->b_name << "\t" << temp->a_name << "\t"
                 << temp->p_name << "\t" << temp->isbn << "\t" << temp->price << "\n";
            fl = 1;
            break;
        }
        temp = temp->next;
    }
    if (fl == 0)
    {
        cout << "Book not found with id " << sid << endl;
    }
}

void Book ::Delete()
{
    int did, fl = 0;
    cout << "Enter Book Id to delete : ";
    cin >> did;
    Book *temp = start, *pos = NULL;
    while (temp != NULL)
    {
        if (did == temp->b_id)
        {
            if (temp == start)
            {
                start = temp->next;
                temp->next = NULL;
            }
            else if (temp == end1)
            {
                pos->next = NULL;
                end1 = pos;
            }
            else
            {
                pos->next = temp->next;
                temp->next = NULL;
            }
            delete temp;
            cout << "Book deleted with book id " << did << endl;
            fl = 1;
            break;
        }
        pos = temp;
        temp = temp->next;
    }
    if (fl == 0)
    {
        cout << "Book not found with id " << did << endl;
    }
}

void Book ::update()
{
    int uid, fl = 0;
    cout << "Enter Book Id to Update : ";
    cin >> uid;
    Book *temp = start;
    while (temp != NULL)
    {
        if (uid == temp->b_id)
        {
            cout << "Enter new Book Id , Book Name , Author Name , Publication Name , ISBN , Price : " << endl;
            cin >> temp->b_id >> temp->b_name >> temp->a_name >> temp->p_name >> temp->isbn >> temp->price;
            fl = 1;
            break;
        }
        temp = temp->next;
    }
    if (fl == 0)
    {
        cout << "Book not found with id " << uid << endl;
    }
}

int main()
{
    int ch;
    Book b;
    cout << "-------Library Management Menu--------" << endl;
    do
    {
        cout << "1.Accept \t2.Display \t3.Search \t4.Delete \t5.Update \n";
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.accept();
            break;

        case 2:
            b.display();
            break;

        case 3:
            b.search();
            break;

        case 4:
            b.Delete();
            break;

        case 5:
            b.update();
            break;
        }
    } while (ch != 0);
    return 0;
}