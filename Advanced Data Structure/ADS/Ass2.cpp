
/*
    2. A Charity Management system need to manage the information about donors, donations and other relevant data. System need to maintain information about each donors. System should able to add new donor, remove the donor, update the information of the donor, search the specific donor also it should display the information of all the donor which are present in the database. Use the concept of the Linked List to implement the above system
*/

#include <iostream>
using namespace std;

class Donor
{
public:
    int d_id;
    string d_name;
    int amount;
    string d_add;
    Donor *next, *prev;
} *head = NULL, *tail = NULL;

void add_new_donor()
{
    int c;
    do
    {
        Donor *new_donor = new Donor;
        new_donor->next = NULL;
        new_donor->prev = NULL;
        cout << "Enter Doner ID, Donor name ,Donor Address and Amount: ";
        cin >> new_donor->d_id >> new_donor->d_name >> new_donor->d_add >> new_donor->amount;
        if (head == NULL)
        {
            head = new_donor;
            tail = new_donor;
        }
        else
        {
            tail->next = new_donor;
            new_donor->prev = tail;
            tail = new_donor;
        }
        cout << "Do you want to add another donor (1/0) : ";
        cin >> c;
    } while (c);
}

void display()
{
    if (head == NULL)
    {
        cout << "Database is Empty !!" << endl;
    }
    else
    {
        Donor *temp = head;
        cout << "Donor_ID  Donor_Name  Donor_Address  Amount_Donated" << endl;
        while (temp != NULL)
        {
            cout << temp->d_id << "\t\t" << temp->d_name << "\t\t" << temp->d_add << "\t\t" << temp->amount << endl;
            temp = temp->next;
        }
    }
}

void delete_donor()
{
    if (head == NULL)
    {
        cout << "Database is Empty !!" << endl;
    }
    else
    {
        int id;
        cout << "Enter Donor Id to delete : ";
        cin >> id;
        Donor *temp = head;
        int fl = 0;
        while (temp != NULL)
        {
            if (id == temp->d_id)
            {
                if (temp == head)
                {
                    head = temp->next;
                    head->prev = NULL;
                    temp->next = NULL;
                }
                else if (temp == tail)
                {
                    (temp->prev)->next = temp->next;
                    tail = temp->prev;
                    temp->prev = NULL;
                }
                else
                {
                    (temp->prev)->next = temp->next;
                    (temp->next)->prev = temp->prev;
                    temp->prev = NULL;
                    temp->next = NULL;
                }
                delete temp;
                fl = 1;
                break;
            }
            temp = temp->next;
        }
        if (fl == 0)
        {
            cout << "Donor Not Found with ID : " << id << endl;
        }
        else
        {
            cout << "Donor with ID " << id << " Deleted Successfully !!" << endl;
        }
    }
}

void search_donor()
{
    if (head == NULL)
    {
        cout << "Database is Empty !!" << endl;
    }
    else
    {
        int id;
        cout << "Enter Donor Id to Search : ";
        cin >> id;
        Donor *temp = head;
        int fl = 0;
        while (temp != NULL)
        {
            if (id == temp->d_id)
            {
                cout << "Donor Info. Found as Follows : " << endl;
                cout << "Donor_ID  Donor_Name  Donor_Address  Amount_Donated" << endl;
                cout << temp->d_id << "\t\t" << temp->d_name << "\t\t" << temp->d_add << "\t\t" << temp->amount << endl;
                fl = 1;
                break;
            }
            temp = temp->next;
        }
        if (fl == 0)
        {
            cout << "Donor Not Found with ID : " << id << endl;
        }
    }
}

void update_donor()
{
    if (head == NULL)
    {
        cout << "Database is Empty !!" << endl;
    }
    else
    {
        int id;
        cout << "Enter Donor Id to Update : ";
        cin >> id;
        Donor *temp = head;
        int fl = 0;
        while (temp != NULL)
        {
            if (id == temp->d_id)
            {
                cout << "Enter new Doner ID, Donor name ,Donor address and Amount: ";
                cin >> temp->d_id >> temp->d_name >> temp->d_add >> temp->amount;
                fl = 1;
                break;
            }
            temp = temp->next;
        }
        if (fl == 0)
        {
            cout << "Donor Not Found with ID : " << id << endl;
        }
        else
        {
            cout << "Donor info with ID " << id << " Updated Successfully !!" << endl;
        }
    }
}

int main()
{
    cout << "  =-=-=-=-=-=-=-=-=-=- Welcome to Charity Management System -=-=-=-=-=-=-=-=-= \n1.Create Donor list\n2.Display Donor info \n3.Delete Donor info \n4.Search Donor info \n5.Update Donor Info \n6.Exit \n";
    int ch;
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            add_new_donor();
            break;
        case 2:
            display();
            break;
        case 3:
            delete_donor();
            break;
        case 4:
            search_donor();
            break;
        case 5:
            update_donor();
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "!!! Wrong Choice !!!" << endl;
        }
    } while (1);

    return 0;
}