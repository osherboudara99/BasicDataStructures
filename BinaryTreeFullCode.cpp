//Osher Boudara
// Comp Sci 136 -- Assignment 5
//5/20/20


#include<iostream>

using namespace std;

struct Date
{
    int month, day, year;
    Date* left;
    Date* right;
};
class Tree
{
    Date* root;
    Date* insert(int m, int d, int y, Date* t);
    Date* findMin(Date* t);
    Date* remove(int m, int d, int y, Date* t);
    void display(Date* t);
    bool find(int m, int d, int y, Date* t);

public:
    Tree();
    void display();
    void insert();
    void remove();
    void search();
};


Date* Tree:: insert(int m, int d, int y, Date* t)
{
    if(t == NULL)
    {
        t = new Date;
        t->month = m;
        t->day = d;
        t->year = y;
        t->left = t->right = NULL;
    }
    else if(y < t->year)
        t->left = insert(m,d,y, t->left);
    else if (y == t->year)
    {
        if(m < t->month)
            t->left = insert(m,d,y, t->left);
        else if (m > t->month)
            t->right = insert(m,d,y, t->right);
        else if (m == t->month)
        {
            if(d < t->day)
                t->left = insert(m,d,y, t->left);
            else if (d > t->day)
                t->right = insert(m,d,y, t->right);
        }
    }
    else if(y > t->year)
        t->right = insert(m,d,y, t->right);

    return t;
}

Date* Tree:: findMin(Date* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

Date* Tree:: remove(int m, int d, int y, Date* t)
{

    Date* temp;

    if(t == NULL)
        return NULL;
    else if(y < t->year)
        t->left = remove(m,d,y, t->left);
    else if (y == t->year)
    {
        if(m < t->month)
            t->left = remove(m,d,y, t->left);
        else if (m > t->month)
            t->right = remove(m,d,y, t->right);
        else if (m == t->month)
        {
            if(d < t->day)
                t->left = remove(m,d,y, t->left);
            else if (d > t->day)
                t->right = remove(m,d,y, t->right);
            else
            {
                if(t->left && t->right)
                {
                    temp = findMin(t->right);
                    t->month = temp->month;
                    t->day = temp->day;
                    t->year = temp->year;
                    t->right = remove(t->month,t->day,t->year, t->right);
                }
                else
                {
                    temp = t;
                    if(t->left == NULL)
                        t = t->right;
                    else if(t->right == NULL)
                        t = t->left;
                    delete temp;

                    cout << " The Date entered has been deleted." << endl;
                }
            }
        }
    }
    else if(y > t->year)
        t->right = insert(m,d,y, t->right);

    return t;
}

void Tree:: display(Date* t)
{
    if(t == NULL)
        return;
    display(t->left);

    cout << t->month << "/"<< t->day << "/" << t->year << endl;

    display(t->right);
}

bool Tree:: find(int m, int d, int y, Date* t)
{

    if(t == NULL)
        return false;
    else if(y < t->year)
        return find(m,d,y, t->left);
    else if (y == t->year)
    {

        if(m < t->month)
            return find(m,d,y, t->left);
        else if (m > t->month)
            return find(m,d,y, t->right);
        else if (m == t->month)
        {
            if(d < t->day)
                return find(m,d,y, t->left);
            else if (d > t->day)
                return find(m,d,y, t->right);
            else
                return true;
        }
    }
    else if(y > t->year)
        return find(m,d,y, t->right);
    else
        return false;
}

Tree:: Tree()
{
    root = NULL;
}

void Tree::display()
{
    cout <<"Full Binary Tree: " << endl;
    display(root);
    cout << endl << endl;
}

void Tree:: insert()
{
    int m, d, y;
    cout <<"Enter the month: ";
    cin >> m;
    cout <<"Enter the day: ";
    cin >> d;
    cout <<"Enter the year: ";
    cin >> y;

    cout << endl;

    root = insert(m, d, y, root);
    cout << "The date has been inserted." << endl << endl;
}

void Tree::remove()
{
    int m, d, y;
    cout <<"Enter the month: ";
    cin >> m;
    cout <<"Enter the day: ";
    cin >> d;
    cout <<"Enter the year: ";
    cin >> y;

    cout << endl;

    bool result = find(m, d, y, root);
    if (result == false)
        cout << "The Date has not been found in Binary Tree. Therefore no deletion available.";
    else
        root = remove(m, d, y, root);

    cout << endl << endl;
}

void Tree::search()
{
    int m, d, y;
    cout <<"Enter the month: ";
    cin >> m;
    cout << "Enter the day: ";
    cin >> d;
    cout <<"Enter the year: ";
    cin >> y;

    cout << endl;

    bool result = find(m, d, y, root);
    if (result == true)
        cout << "The Date searched was found in the Binary Tree. " << endl;
    else
        cout << "The Date was not found in the Binary Tree. " << endl << endl;
}

int main()
{
    Tree t;
    int selection;
    do
    {
        cout << endl << "-------------------------------------------------" << endl;
        cout << "                  Menu for Binary Tree  " << endl << endl;
        cout << "1. Display all Dates in Binary Tree " << endl;
        cout << "2. Insert a Date " << endl;
        cout << "3. Remove a Date " << endl;
        cout << "4. Search for a Date " << endl;
        cout << "5. Quit " << endl;
        cout << "Enter your selection: ";
        cin >> selection;

        cout << endl;

        if(selection == 1)
        {
            t.display();
        }
        else if (selection == 2)
        {
            t.insert();
        }
        else if (selection == 3)
        {
            t.remove();
        }
        else if (selection == 4)
        {
            t.search();
        }
        else if (selection == 5)
        {
            cout << "Program is exiting... ";
        }
        else
            cout << "Error: Invalid menu selection.";

    }while(selection != 5);

    return 0;
}
