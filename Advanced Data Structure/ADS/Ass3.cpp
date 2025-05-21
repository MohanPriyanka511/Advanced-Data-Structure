// 3. Design and implement a family tree hierarchy using a tree data structure. The family tree should allow
// efficient storage, retrieval, and manipulation of information related to individuals and their relationships
// within

#include <iostream>
using namespace std;

#define mx 15
int top=-1,cnt=0,cnt1=0,cnt2=0;
class Family
{
public:
    int aadhar_no;
    string name;
    int age;
    string edu;
    Family *l_child, *r_child;
} *root = NULL,*st[mx];

void insert(Family *rt, Family *n_member)
{
    char c;
    cout << "Where you want to add left(L) or right(R) of " << rt->name << " : ";
    cin >> c;
    if (c == 'L' || c == 'l')
    {
        if (rt->l_child == NULL)
        {
            rt->l_child = n_member;
            cnt1++;
            cnt++;
            return;
        }
        insert(rt->l_child, n_member);
    }
    if (c == 'R' || c == 'r')
    {
        if (rt->r_child == NULL)
        {
            rt->r_child = n_member;
            cnt2++;
            cnt++;
            return;
        }
        insert(rt->r_child, n_member);
    }
}

void add_family_info()
{
    int ch;
    do
    {
        Family *new_member = new Family;
        new_member->l_child = NULL;
        new_member->r_child = NULL;
        cout<<"Enter Aadhar No, Name, Age, Education : ";
        // cout << "Enter Aadhar no : ";
        cin >> new_member->aadhar_no;
        // cout << "Enter Name : ";
        cin >> new_member->name;
        // cout << "Enter Age : ";
        cin >> new_member->age;
        // cout << "Enter Education : ";
        cin >> new_member->edu;
        if (root == NULL)
        {
            root = new_member;
        }
        else
        {
            insert(root, new_member);
        }
        cout << "Do you want to add another member : ";
        cin >> ch;
    } while (ch == 1);
}
void preorder(Family *rt)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {
        cout << rt->aadhar_no << "\t\t" << rt->name << "\t\t" << rt->age << " \t\t " << rt->edu << endl;
        preorder(rt->l_child);
        preorder(rt->r_child);
    }
}
void inorder(Family *rt)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {
        inorder(rt->l_child);
        cout << rt->aadhar_no << "\t\t" << rt->name << "\t\t" << rt->age << " \t\t " << rt->edu << endl;
        inorder(rt->r_child);
    }
}
void postorder(Family *rt)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {
        postorder(rt->l_child);
        postorder(rt->r_child);
        cout << rt->aadhar_no << "\t\t" << rt->name << "\t\t" << rt->age << " \t\t " << rt->edu << endl;
    }
}
void current_generation(Family *rt)
{
    if (root == NULL)
    {
        cout << "Empty Tree !!" << endl;
        return;
    }
    else if (rt == NULL)
    {
        return;
    }
    else if (rt->l_child == NULL && rt->r_child == NULL)
    {
       cout << rt->aadhar_no << "\t\t" << rt->name << "\t\t" << rt->age << " \t\t " << rt->edu << endl;
    }
    current_generation(rt->l_child);
    current_generation(rt->r_child);
}

void display()
{
    Family *temp=root;
    if(root!=NULL)
    {
        do
        {
            while(temp!=NULL)
            {
                top++;
                st[top]=temp;
                temp=temp->l_child;
            }
            if(top!=-1)
            {
                temp=st[top];
                cout << temp->aadhar_no << "\t\t" << temp->name << "\t\t" << temp->age << " \t\t " << temp->edu << endl;
                temp=temp->r_child;
                top--;
            }
        }
        while(top!=-1 || temp!=NULL);
    }
}

int height_of_tree(Family *rt)
{
    if(rt==NULL)
    {
        return 0;
    }
    int lh=height_of_tree(rt->l_child);
    int rh=height_of_tree(rt->r_child);
    return 1+max(lh,rh);
}

int main()
{
    int c;
    do
    {
        cout << "\nMENU :--->>" << endl;
        cout << "1.Add Family member info. into Tree \n2.Inorder Traversal \n3.Preorder Traversal \n4.Postorder Traversal \n5.Show current generation record \n6.Non_recursive Display \n7.Display Height of tree \n8.Exit \nEnter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            add_family_info();
            break;
        case 2:
            cout << "---- : Inorder Traversal : ----"<<endl;
            cout << "Aadhar No." << "\t" <<"Name" << "\t\t" << "Age" << "\t" << "Education" << endl;
            inorder(root);
            break;
        case 3:
            cout << "---- : Preorder Traversal : ----"<<endl;
            cout << "Aadhar No." << "\t" <<"Name" << "\t\t" << "Age" << "\t" << "Education" << endl;
            preorder(root);
            break;
        case 4:
            cout << "---- : Postorder Traversal : ----"<<endl;
            cout << "Aadhar No." << "\t" <<"Name" << "\t\t" << "Age" << "\t" << "Education" << endl;
            postorder(root);
            break;
        case 5:
            cout << "---- : Current Generation Record : ----"<<endl;
            cout << "Aadhar No." << "\t" <<"Name" << "\t\t" << "Age" << "\t" << "Education" << endl;
            current_generation(root);
            break;
        case 6:
            cout << "Aadhar No." << "\t" <<"Name" << "\t\t" << "Age" << "\t" << "Education" << endl;
            display();
            break;
        case 7:
            cout<<"Height of tree = "<<height_of_tree(root)<<endl;
            break;
        case 8:
            exit(1);
            break;
        default:
            cout << "Wrong choice !!";
            break;
        }
    } while (1);

    return 0;
}