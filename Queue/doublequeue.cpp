#include <iostream>
#define MAX_QUEUE 5
using namespace std;

int queue[MAX_QUEUE];
int front = -1, rear = -1;

bool isFull()
{
    if ((rear + 1) % MAX_QUEUE == front)
        return true;
    return false;
}

bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    return false;
}

bool Enqueue(int num)
{
    if (isFull())
    {
        cout << "Queue is full\n" << endl;
        return 0;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_QUEUE;
    }
    queue[rear] = num;
    cout << "Enqueued Successfully\n" << endl;
}

bool EnqueueatFront(int num)
{
    if (isFull())
    {
        cout << "Queue is full\n" << endl;
        return 0;
    }
    else if (isEmpty())
    {
        Enqueue(num);
        return 0;
    }
    else
    {
        if (front == 0)
        {
            front = MAX_QUEUE - 1;
        }
        else
        {
            front = front - 1;   
        }
    }
    queue[front] = num;
    cout << "Enqueued Successfully\n" << endl;
    
    
}

bool Dequeue()
{
    if (isEmpty())
    {
        cout << "\nQueue is Empty\n" << endl;
        return 0;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1)  % MAX_QUEUE;
    }
    cout << "\nElement Dequeued Successfully\n" << endl;
}

bool DequeueatEnd()
{
    if (isEmpty())
    {
        cout << "\nQueue is Empty\n" << endl;
        return 0;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear -= 1;
    }
    cout << "\nElement Dequeued Successfully\n" << endl;
}

int main()
{
    int push;
    char choice;
    while (true)
    {
        cout << "------------------------------------------------" << endl;
        cout << "           1--> Enqueue                         " << endl;
        cout << "           2--> Enqueue at Front                " << endl;
        cout << "           3--> Dequeue                         " << endl;
        cout << "           4--> Dequeue at End                  " << endl;
        cout << "           5--> Peek                            " << endl;
        cout << "           6--> Show Queue                      " << endl;
        cout << "           7--> Exit                            " << endl;
        cout << "------------------------------------------------" << endl;

        cout << " >> ";
        cin >> choice;

        if (choice == '1')
        {
            cout << "\nEnter the element you want to Enqueue: ";
            cin >> push;
            Enqueue(push);
        }
        
        else if (choice == '2')
        {
            cout << "\nEnter the element you want to Enqueue at Front: ";
            cin >> push;
            EnqueueatFront(push);
        }

        else if (choice == '3')
        {
           Dequeue();
        }

        else if (choice == '4')
        {
           DequeueatEnd();
        }

        else if (choice == '5')
        {
            if (front == -1 && rear == -1)
            {
                cout << "\nQueue is Empty\n" << endl;
            }
            else
            {
                cout << "\nPeek Element " << queue[front] << endl << endl;
            }
        }

        else if (choice == '6')
        {
            if (!isEmpty())
            {
                cout << "\nQueue from Rear to Front: ";
                int i = rear;
                while ( i != front)
                {
                    cout << queue[i] << " ";
                    i--;
                    if (i < 0)
                    {
                        i = MAX_QUEUE - 1;
                    }
                }
                cout << queue[front];
                cout << endl << endl;
            }
            else
            {
                cout << "\nQueue is Empty\n" << endl;
            }
            
        }
        
        else if (choice == '7')
        {
            exit(0);
        }
        
        else
        {
            cout << "\nEnter Valid Choice\n" << endl;
        }
        
    }
}