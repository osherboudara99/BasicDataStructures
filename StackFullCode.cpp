//Osher Boudara Co Sci 136 -- Assignment 3
// 04/13/2020

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;
struct Date
{
    int month, day, year;
    struct Date *nodeType;
}*start;


class stack
{
public:
    Date* beginStack(Date);
    void push_front_stack();
    void pop_front_stack();
    int search_stack();
    void display_stack();
    stack();
};

#endif

stack::stack()
{
    start = NULL;
}

Date *stack::beginStack(struct Date newDate)
{
    struct Date *tempNode, *s;
    tempNode = new(struct Date);

    if (tempNode == NULL)
    {
        cout << "Memory was not allocated. " << endl;

    }
    else
    {
        tempNode->month = newDate.month;
        tempNode->day = newDate.day;
        tempNode->year = newDate.year;
        tempNode->nodeType = NULL;
        return tempNode;
    }
}

void stack::push_front_stack()
{
    struct Date *tempNode, *start1, addNode;

    cout << "Enter the month: ";
    cin >> addNode.month;
    cout << "Enter the day: ";
    cin >> addNode.day;
    cout << "Enter the year: ";
    cin >> addNode.year;
    tempNode = beginStack(addNode);

    if (start == NULL)
    {
        start = tempNode;
        start->nodeType = NULL;
    }
    else
    {
        start1 = start;
        start = tempNode;
        start->nodeType = start1;
    }
}

void stack::pop_front_stack()
{
    struct Date *start1;
    start1 = start;
    if(start == NULL)
    {
        cout << endl << "Deleted Date: " << start1->month << "/" << start1->day << "/" << start1->year;
    }
    start = start1->nodeType;

    delete(start1);

}


int stack::search_stack()
{
    struct Date *currentNode, dateSearch;
    bool boolean = false;

    cout << "Enter a date to search: " << endl;
    cout << "Enter the month: ";
    cin >> dateSearch.month;
    cout << "Enter the day: ";
    cin >> dateSearch.day;
    cout << "Enter year: ";
    cin >> dateSearch.year;
    cout << endl;

    currentNode = start;
    while (currentNode != NULL)
    {
        if (currentNode->month == dateSearch.month && currentNode->day == dateSearch.day && currentNode->year == dateSearch.year)
        {
            boolean = true;
            currentNode = currentNode->nodeType;
            return 1;
        }
        else if (!boolean)
            return -1;

        break;
    }
}

void stack::display_stack()
{
    struct Date *tempNode;
    if (start == NULL)
    {
        cout << "The List is empty. " << endl;
        return;
    }
    tempNode = start;
    while (tempNode != NULL)
    {
        cout << tempNode->month << "/"<< tempNode->day << "/" << tempNode->year << endl;
        tempNode = tempNode->nodeType;
    }
}


int main()
{
    int selection, returned;
    stack stacks;
    start = NULL;

    cout << "Create a stack list with this cool program today!" << endl;
    cout << endl;
    while (selection != 5)
    {
        cout << endl << "        Menu for Dates Stack " << endl;
        cout << "1. Push the Stack" << endl;
        cout << "2. Pop the Stack" << endl;
        cout << "3. Search an element in the Stack" << endl;
        cout << "4. Display the Stack" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter a selection: ";
        cin >> selection;

        cout << endl << "------------------------------------------" << endl << endl;

        switch (selection)
        {

            case 1:
                cout << endl << "Pushing Stack: " << endl << endl;
                stacks.push_front_stack();
                cout << endl;
                break;

            case 2:
                cout << endl << "Popping the top piece of data in Stack...." << endl;
                stacks.pop_front_stack();
                cout << "The top element has been popped." << endl;
                cout << endl;
                break;

            case 3:
                cout << "Searching date in Stack: " << endl;
                returned = stacks.search_stack();
                if(returned == -1)
                {
                    cout << "The date was not found in the list." << endl;
                }
                else if(returned == 1)
                {
                    cout << " The date has been found in the list." << endl;
                }
                cout << endl << endl;
                break;

            case 4:
                cout << endl << "The Full Stack: " << endl;
                stacks.display_stack();
                cout << endl;
                break;

            case 5:
                cout << "Program is exiting... " << endl;
                break;

            default:
                cout << "Your input is invalid." << endl;

        }

    }
    return 0;
}
