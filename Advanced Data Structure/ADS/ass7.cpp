#include <iostream>
using namespace std;
int key[20], c[10], n, i;
class medical
{
public:
    int pno;
    string patient_name, date;
    float amount;
    void declare();
    void Htable();
    void accept();
    void search();
    void delete_patient();
} h[20];
void medical ::declare()
{
    cout << "Enter the total number of patients : ";
    cin >> n;
    cout << "\nEnter the patient numbers : ";
    for (int i = 0; i < n; i++)
    {
        cin >> key[i];
    }
    for (i = 0; i < 10; i++)
    {
        h[i].pno = 0;
        c[i] = -1;
    }
}
void medical ::Htable()
{
    cout << "\nINDEX \tPNO Patient_Name  Date  \tBill Amount \t\t chain \n";
    for (i = 0; i < 10; i++)
    {
        cout << i << "\t" << h[i].pno << "\t" << h[i].patient_name << "\t" << h[i].date << "\t" << h[i].amount << " \t\t " << c[i] << "\n";
    }
}
void medical ::accept()
{
    int no, pos;
    for (int i = 0; i < n; i++)
    {
        no = key[i] % 10;
        pos = no;
        do
        {
            if (h[no].pno == 0)
            {
                h[no].pno = key[i];
                if (no != pos)
                {
                    c[pos] = no;
                }
                cout << "Enter Patient Name, Date, Bill Amount : ";
                cin >> h[no].patient_name >> h[no].date >> h[no].amount;
                break;
            }
            else
            {
                no++;
                if (no >= 10)
                {
                    no = 0;
                }
            }
        } while (no < 10);
    }
}

void medical::search()
{
    int s, fl = 0;
    cout << "Enter Patient number to search : ";
    cin >> s;
    int k = s % 10;
    do
    {
        if (h[k].pno == s)
        {
            fl = 1;
            break;
        }
        else
        {
            k = c[k];
        }
    } while (k != -1);
    if (fl == 1)
    {
        cout << "Patient Found as follows : " << endl;
        cout << "\nINDEX \tPNO Patient_Name  Date  \tBill Amount \t\t chain \n";
        cout << k << "\t" << h[k].pno << "\t" << h[k].patient_name << "" << h[k].date << "\t" << h[k].amount<< " \t\t " << c[k] << "\n";
    }
    else
    {
        cout << "Patient Not Found !!" << endl;
    }
}
void medical::delete_patient()
{
    int s, fl = 0;
    cout << "Enter Patient number to delete : ";
    cin >> s;
    int k = s % 10;
    do
    {
        if (h[k].pno == s)
        {
            fl = 1;
            break;
        }
        else
        {
            k = c[k];
        }
    } while (k != -1);
    if (fl == 1)
    {
        cout << "Pacient Deleted Successfully !! " << endl;
        n--;
        h[k].pno = 0;
        h[k].patient_name = " ";
        h[k].date = " ";
        h[k].amount = 0;
    }
    else
    {
        cout << "Patient Not Found !!" << endl;
    }
}

int main()
{
    int ch;
    medical m;
    do
    {
        cout << "MENU\n1.declare\n2.accept\n3.Display Hash Table \n4.Search Patient \n5.Delete patient \n6.Exit \nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            m.declare();
            break;
        case 2:
            m.accept();
            break;
        case 3:
            m.Htable();
            break;
        case 4:
            m.search();
            break;
        case 5:
            m.delete_patient();
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"Wrong choice !!"<<endl;
            break;
        }
    } while (ch);
    return 0;
}
