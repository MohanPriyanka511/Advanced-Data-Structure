/*
    4. Design and implement a Employee Management system tree hierarchy using a binary search tree data structure. The Employee tree should allow efficient storage, retrieval, and manipulation of information related to individuals and their relationships within the employee. The insertion of new employee carried out based on their salary.
*/

#include <iostream>
using namespace std;

class Employee
{
public:
    int emp_id;
    string emp_name;
    double emp_sal;
    string emp_add;
    Employee *l_child, *r_child;
} *root = NULL;

void insert(Employee *rt, Employee *new_emp)
{
    if (new_emp->emp_sal < rt->emp_sal)
    {
        if (rt->l_child == NULL)
        {
            rt->l_child = new_emp;
            return;
        }
        insert(rt->l_child, new_emp);
    }
    else if (new_emp->emp_sal >= rt->emp_sal)
    {
        if (rt->r_child == NULL)
        {
            rt->r_child = new_emp;
            return;
        }
        insert(rt->r_child, new_emp);
    }
}
void accept_emp_info()
{
    int c;
    do
    {
        Employee *new_emp = new Employee;
        new_emp->l_child = NULL;
        new_emp->r_child = NULL;
        cout << "Enter Employee ID, Name, Salary, Address : ";
        cin >> new_emp->emp_id >> new_emp->emp_name >> new_emp->emp_sal >> new_emp->emp_add;
        if (root == NULL)
        {
            root = new_emp;
        }
        else
        {
            insert(root, new_emp);
        }
        cout << "Do you want to add more employee (1/0) : ";
        cin >> c;
    } while (c == 1);
}

void preorder(Employee *rt)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {
        cout << rt->emp_id << "\t" << rt->emp_name << "\t  " << rt->emp_sal << "\t\t" << rt->emp_add << endl;
        preorder(rt->l_child);
        preorder(rt->r_child);
    }
}
void inorder(Employee *rt)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {
        inorder(rt->l_child);
        cout << rt->emp_id << "\t" << rt->emp_name << "\t  " << rt->emp_sal << "\t\t" << rt->emp_add << endl;
        inorder(rt->r_child);
    }
}
void postorder(Employee *rt)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {
        postorder(rt->l_child);
        postorder(rt->r_child);
        cout << rt->emp_id << "\t" << rt->emp_name << "\t  " << rt->emp_sal << "\t\t" << rt->emp_add << endl;
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\nMENU :--->>" << endl;
        cout << "1.Add Employee info. into Tree \n2.Inorder Traversal \n3.Preorder Traversal \n4.Postorder Traversal \n5.exit \nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            accept_emp_info();
            break;
        case 2:
            cout << "---- : Inorder Traversal : ----" << endl;
            cout << "Emp_ID  Emp_Name  Emp_Salary  Emp_Address" << endl;
            inorder(root);
            break;
        case 3:
            cout << "---- : Preorder Traversal : ----" << endl;
            cout << "Emp_ID  Emp_Name  Emp_Salary  Emp_Address" << endl;
            preorder(root);
            break;
        case 4:
            cout << "---- : Postorder Traversal : ----" << endl;
            cout << "Emp_ID  Emp_Name  Emp_Salary  Emp_Address" << endl;
            postorder(root);
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "Wrong choice !!";
            break;
        }
    } while (1);
    return 0;
}