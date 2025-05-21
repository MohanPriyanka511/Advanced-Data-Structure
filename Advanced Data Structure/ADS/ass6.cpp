#include <iostream>
using namespace std;
int key[20], c[10], n, i;
class music
{
public:
    int tno;
    string music_name, singer_name;
    float time;
    void declare();
    void Htable();
    void accept();
    void search();
    void delete_music();
} h[20];
void music ::declare()
{
    cout << "Enter the total number of tracks : ";
    cin >> n;
    cout << "\nEnter the track numbers : ";
    for (int i = 0; i < n; i++)
    {
        cin >> key[i];
    }
    for (i = 0; i < 10; i++)
    {
        h[i].tno = 0;
        c[i] = -1;
    }
}
void music ::Htable()
{
    cout << "\n INDEX \tTNO \t Music_Name \t Singer_Name \t Time \t chain \n";
    for (i = 0; i < 10; i++)
    {
        cout << i << "\t" << h[i].tno << "\t" << h[i].music_name << "\t" << h[i].singer_name << "\t" << h[i].time << " \t\t " << c[i] << "\n";
    }
}
void music ::accept()
{
    int no, pos;
    for (int i = 0; i < n; i++)
    {
        no = key[i] % 10;
        pos = no;
        do
        {
            if (h[no].tno == 0)
            {
                h[no].tno = key[i];
                if (no != pos)
                {
                    c[pos] = no;
                }
                cout << "Enter Music Name, Singer Name, Time : ";
                cin >> h[no].music_name >> h[no].singer_name >> h[no].time;
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

void music::search()
{
    int s, fl = 0;
    cout << "Enter track number to search : ";
    cin >> s;
    int k = s % 10;
    do
    {
        if (h[k].tno == s)
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
        cout << "Music Found as follows : " << endl;
        cout << "\nINDEX \tTNO Music_Name Singer_Name  Time \t chain \n";
        cout << k << "\t" << h[k].tno << "\t" << h[k].music_name << "\t" << h[k].singer_name << "\t" << h[k].time << " \t\t " << c[k] << "\n";
    }
    else
    {
        cout << "Music Not Found !!" << endl;
    }
}
void music::delete_music()
{
    int s, fl = 0;
    cout << "Enter track number to delete : ";
    cin >> s;
    int k = s % 10;
    do
    {
        if (h[k].tno == s)
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
        cout << "Music Deleted Successfully !! " << endl;
        n--;
        h[k].tno = 0;
        h[k].music_name = " ";
        h[k].singer_name = " ";
        h[k].time = 0;
        
    }
    else
    {
        cout << "Music Not Found !!" << endl;
    }
}

int main()
{
    int ch;
    music m;
    do
    {
        cout << "MENU\n1.declare\n2.accept\n3.Display Hash Table \n4.Search music \n5.Delete music \n6.Exit \nEnter your choice : ";
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
            m.delete_music();
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
