/*
    5. There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A or the amount of fuel used for the journey. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph and adjacency matrix representation of the graph. Justify the storage representation used
*/

#include <iostream>
using namespace std;

int n;
class flight
{
public:
    int fuel;
    int dist;
}*fli[10][10];

string city[10];

void create()
{
    cout<<"Enter number of cities : ";
    cin>>n;
    cout<<"Enter city names : ";
    for(int i=0;i<n;i++)
    {
        cin>>city[i];
    }
    cout<<"Enter distance and fuel between "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            fli[i][j]=new flight;
            fli[j][i]=new flight;
            if(i!=j)
            {
                cout<<city[i]<<" and "<<city[j]<<" : ";
                cin>>fli[i][j]->dist>>fli[i][j]->fuel;
                fli[j][i]->dist=fli[i][j]->dist;
                fli[j][i]->fuel=fli[i][j]->fuel;
            }
            else
            {
                fli[i][j]->dist=fli[i][j]->fuel=0;
            }
        }
    }
}

void display()
{
    cout<<"        ";
    for(int i=0;i<n;i++)
    {
        cout<<city[i]<<"\t";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<city[i]<<" : ";
        for(int j=0;j<n;j++)
        {
            cout<<fli[i][j]->fuel<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    create();
    display();

    return 0;
}