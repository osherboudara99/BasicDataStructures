//Osher Boudara Co Sci 136 -- Assignment 4
//class/structures and function definition header file
// 04/25/2020


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


class Queue
{
public:
    Date* beginQueue(Date);
    void queuePushBack();
    void queuePopFront();
    int queueSearch();
    void queueDisplay();
    Queue();
};


Queue::Queue()
{
    start = NULL;
}

Date *Queue::beginQueue(struct Date newDate)
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

void Queue::queuePushBack()
{
    struct Date *tempNode, *start1, addNode;
    cout << "Enter the month: ";
    cin >> addNode.month;
    cout << "Enter the day: ";
    cin >> addNode.day;
    cout << "Enter the year: ";
    cin >> addNode.year;

    tempNode = beginQueue(addNode);
    start1 = start;
    if(start == NULL)
    {
        start = tempNode;
        start->nodeType = NULL;
        cout << endl << "First element has been inserted in the queue." << endl;
    }
    else
    {
        while (start1->nodeType != NULL)
            start1 = start1->nodeType;

        tempNode->nodeType = NULL;
        start1->nodeType = tempNode;
        cout << endl << "The element has been inserted at the end of the queue." << endl;
    }
}
void Queue::queuePopFront()
{
    struct Date *start1;
    start1 = start;
    if(start != NULL)
    {
        cout << endl << "Top element has been popped.";
        cout << endl << "Deleted Date: " << start1->month << "/" << start1->day << "/" << start1->year;
        start = start1->nodeType;

        delete(start1);
    }
    else
    {
        cout << endl << "There is no element to pop because queue is empty.";
    }
}


int Queue::queueSearch()
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
    if(currentNode == NULL)
    {
        cout << "The date searched cannot be found because the queue is empty." << endl;
    }
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

void Queue::queueDisplay()
{
    struct Date *tempNode;
    if (start == NULL)
    {
        cout << "The queue is empty. " << endl;
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
    Queue q;
    start = NULL;

    cout << "Create a queue data structure with this cool program today!" << endl;
    cout << endl;
    while (selection != 5)
    {
        cout << endl << "------------------------------------------" << endl << endl;
        cout << endl << "        Menu for Queue Dates List " << endl;
        cout << "1. Push the Queue" << endl;
        cout << "2. Pop the Queue" << endl;
        cout << "3. Search an element in the queue" << endl;
        cout << "4. Display the Queue" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter a selection: ";
        cin >> selection;

        cout << endl << "------------------------------------------" << endl << endl;

        switch (selection)
        {

            case 1:
                cout << endl << "Pushing Queue: " << endl << endl;
                q.queuePushBack();
                cout << endl;
                break;

            case 2:
                cout << endl << "Popping the top piece of data in Queue" << endl;
                q.queuePopFront();
                cout << endl;
                break;

            case 3:
                cout << "Searching date in Queue: " << endl;
                returned = q.queueSearch();
                if(returned == -1)
                {
                    cout << "The date was not found in the queue." << endl;
                }
                else if(returned == 1)
                {
                    cout << " The date has been found in the queue." << endl;
                }
                cout << endl << endl;
                break;

            case 4:
                cout << endl << "The Full Queue: " << endl;
                q.queueDisplay();
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



