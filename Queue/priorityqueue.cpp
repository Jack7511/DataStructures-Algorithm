#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int queue[MAX_SIZE];
int priority[MAX_SIZE];
int size = 0;

bool Enqueue(int num, int precendence)
{
    if (size == MAX_SIZE)
    {
        cout << "Queue is full\n" << endl;
    }
    else if (size == 0)
    {
        queue[0] = num;
        priority[0] = precendence;
        size++;
    }
    else
    {
        int i = 0;
        while (i < size)
        {
            if (priority[i] > precendence)
            {
                break;
            }
            i++;
        }
        for (int j = size; j > i; j--)
        {
            queue[j] = queue[j - 1];
            priority[j] = priority[j - 1];
        }
        queue[i] = num;
        priority[i] = precendence;
        size++;
    }
}

bool Dequeue(int num)
{
    if (size == 0)
    {
        cout << "\nQueue is Empty" << endl;
        return 0;
    }

    int i = 0;
    while (i < size)
    {
        if (queue[i] == num)
        {
            for (int j = i; j < size - 1; j++)
            {
                queue[j] = queue[j + 1];
                priority[j] = priority[j + 1];
            }
            break;
        }
        i++;
    }

    if (i == size)
        cout << "Element not found" << endl;
    else
        size--;
}

void Print()
{
    if (size != 0)
    {
        cout << "\nElement  Priority" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "   " << queue[i] << "       " << priority[i] << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "\nQueue is Empty\n" << endl;
    }
}

int main()
{
    int push, precedence;
    char choice;
    while (true)
    {
        cout << "------------------------------------------------" << endl;
        cout << "           1--> Enqueue                         " << endl;
        cout << "           2--> Dequeue                         " << endl;
        cout << "           3--> Peek                            " << endl;
        cout << "           4--> Show Queue                      " << endl;
        cout << "           5--> Exit                            " << endl;
        cout << "------------------------------------------------" << endl;

        cout << " >> ";
        cin >> choice;

        if (choice == '1')
        {
            cout << "\nEnter the element you want to Enqueue: ";
            cin >> push;
            cout << "Enter the priority: ";
            cin >> precedence;
            Enqueue(push, precedence);
            Print();
        }

        else if (choice == '2')
        {
            cout << "\nEnter the element: ";
            cin >> push;
            Dequeue(push);
            Print();
        }

        else if (choice == '3')
        {
            if (size == 0)
            {
                cout << "\nQueue is Empty\n"
                     << endl;
            }
            else
            {
                cout << "\nPeek Element " << queue[size - 1] << endl
                     << endl;
            }
        }

        else if (choice == '4')
        {
            Print();
        }

        else if (choice == '5')
        {
            exit(0);
        }

        else
        {
            cout << "\nEnter Valid Choice\n"
                 << endl;
        }
    }
}