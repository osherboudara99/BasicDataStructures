//Osher Boudara Co Sci 136 -- Assignment 2
// 03/13/2020

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

class LinkedList
{
public:
    Date* headFirstNode(Date);
    void push_front();
    void push_back();
    void remove_front();
    void remove_back();
    void pop_front();
    void pop_back();
    int search();
    void display();
    LinkedList();
};

#endif

LinkedList::LinkedList()
{
    start = NULL;
}

Date *LinkedList::headFirstNode(struct Date newDate)
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

void LinkedList::push_front()
{
    struct Date *tempNode, *start1, addNode;

    cout << "Enter the month: ";
    cin >> addNode.month;
    cout << "Enter the day: ";
    cin >> addNode.day;
    cout << "Enter the year: ";
    cin >> addNode.year;
    tempNode = headFirstNode(addNode);

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

void LinkedList::push_back()
{
    struct Date *tempNode, *start1, addNode;
    cout << "Enter the month: ";
    cin >> addNode.month;
    cout << "Enter the day: ";
    cin >> addNode.day;
    cout << "Enter the year: ";
    cin >> addNode.year;

    tempNode = headFirstNode(addNode);
    start1 = start;
    while (start1->nodeType != NULL)
        start1 = start1->nodeType;

    tempNode->nodeType = NULL;
    start1->nodeType = tempNode;

    cout << "Element has been inserted in the end." << endl;
}
void LinkedList::remove_front()
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

void LinkedList::remove_back()
{
    struct Date *start1, *position;
    if (start == NULL)
    {
        cout << "The list is empty " << endl;
    }
    else if (start->nodeType == NULL)
    {
        start1 = start;
        start = NULL;
    }
    else
    {
        position = start;
        start1 = start->nodeType;
        while(start1->nodeType != NULL)
        {
            position = start1;
            start1 = start1->nodeType;
        }
    }
    position->nodeType = NULL;
    cout << endl << "Deleted Date: " << start1->month << "/" << start1->day << "/" << start1->year;
	delete(start1);
}
void LinkedList::pop_front()
{
    if (start == NULL)
    {
        cout << "The list is empty." << endl;
    }
    else
        cout << endl << "First Date: " << start->month << "/" << start->day << "/" << start->year;
}
void LinkedList::pop_back()
{
    struct Date *start1, *position;
    if (start == NULL)
    {
        cout << "The list is empty. " << endl;
    }
    else
    {
        position = start;
        start1 = start->nodeType;
        while(start1->nodeType != NULL)
        {
            position = start1;
            start1 = start1->nodeType;
        }
        cout << endl << "Last Date: " << start1->month << "/" << start1->day << "/" << start1->year;
    }
}
int LinkedList::search()
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

void LinkedList::display()
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
    int userChoice = 0, choicePush, choicePop, choiceRemove, returned;
    LinkedList *functionCall;
    start = NULL;

    cout << "Create a linked list with dates and manipulate it today with this cool program!" << endl;


	cout << "------------------------------------" << endl;
    while(userChoice != 6)
    {
        cout << endl << "         Menu For The Dates Linked List " << endl;
        cout << endl;
        cout << "1. Display All Elements of the List " << endl;
        cout << "2. Insert Node " << endl;
        cout << "3. Remove Node " << endl;
        cout << "4. Search For Node " << endl;
        cout << "5. Display Node " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch(userChoice)
        {
        case 1:
            cout << "All Elements of Linked List: " << endl;
            functionCall->display();
            cout << endl;
            break;
        case 2:
            cout << "Inserting Node: " << endl;
            cout << "Would you like to insert a node in front or back of the list? (Enter 1 for front and 2 for back)" << endl;
            cin >> choicePush;

            if (choicePush == 1)
            {
                functionCall->push_front();
                cout << "Node has been inserted in front of the list." << endl;
            }
            else if (choicePush == 2)
            {
                functionCall->push_back();
                cout << "Node has been inserted in back of the list." << endl;
            }
            else
            {
                cout << "Invalid Input..." << endl;
            }
            cout << endl;
            break;
        case 3:
            cout << "Removing Node: " << endl;
            cout << "Would you like to remove a node in front or back of the list? (Enter 1 for front and 2 for back)" << endl;
            cin >> choiceRemove;

            if (choiceRemove == 1)
            {
                functionCall->remove_front();
                cout << "Node has been removed from in front of the list." << endl;
            }
            else if (choiceRemove == 2)
            {
                functionCall->remove_back();
                cout << "Node has been removed from in back of the list." << endl;
            }
            else
            {
                cout << "Invalid Input..." << endl;
            }
            cout << endl;
            break;
        case 4:
            cout << "Find a Node: " << endl;
            returned = functionCall->search();
            if(returned == -1)
            {
            	cout << "The date was not found in the list." << endl;
			}
			else if(returned == 1)
			{
				cout << " The date has been found in the list." << endl;
			}
            cout << endl;
            break;
        case 5:
            cout << "Display a Node: " << endl;
            cout << "Would you like to display a node in front or back of the list? (Enter 1 for front and 2 for back)" << endl;
            cin >> choicePop;

            if (choicePop == 1)
            {
                functionCall->pop_front();
            }
            else if (choicePop == 2)
            {
                functionCall->pop_back();
            }
            else
            {
                cout << "Invalid Input..." << endl;
            }
            cout << endl;
            break;

        case 6:
            cout << "Exiting Program ..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

