#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;

public:
    int size = 0;
    LinkedList()
    {
        head = NULL;
    }

    void InsertatBeg(int x)
    {
        struct Node *temp = (Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = NULL;
        if (head != NULL)
            temp->next = head;
        head = temp;
        size++;
    }

    void InsertatEnd(int x)
    {
        if (size == 0)
            InsertatBeg(x);
        else
        {
            Node *new_node = new Node;
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            new_node->data = x;
            new_node->next = NULL;
            temp->next = new_node;
            size++;
        }
    }

    void Insertafter(int element, int eleafter)
    {
        int s = 1;
        Node *new_node = new Node;
        Node *prev = head;
        if (head != NULL)
        {
            while (prev->data != eleafter && s < size)
            {
                prev = prev->next;
                s++;
            }
            if (prev->data == eleafter)
            {
                new_node->data = element;
                new_node->next = prev->next;
                prev->next = new_node;
                size++;
            }
            else
            {
                cout << "Element not found" << endl;
            }
        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    int Insertat(int x, int i)
    {
        if (i == 1)
            InsertatBeg(x);
        else if (i > 1)
        {
            Node *new_node = new Node;
            Node *temp = head;
            for (int j = 1; j < i - 1; j++)
            {
                if (temp->next == NULL)
                {
                    cout << "Index out of range" << endl;
                    return 0;
                }
                temp = temp->next;
            }
            new_node->data = x;
            new_node->next = temp->next;
            temp->next = new_node;
            size++;
            return 0;
        }
        else
        {
            cout << "Enter valid Index" << endl;
        }
    }

    void RemoveatBeg()
    {
        if (size > 0)
        {
            Node *temp = head;
            head = temp->next;
            size--;
            delete temp;
        }
        else
        {
            cout << "\nLinked List is Empty" << endl;
        }
    }

    void RemoveatEnd()
    {
        if (size == 1)
        {
            Node *temp = head;
            head = NULL;
            delete temp;
            size--;
        }
        else if (size > 1)
        {
            Node *temp = head;
            Node *prev;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
            size--;
        }
        else
        {
            cout << "\nLinked List is Empty" << endl;
        }
    }

    int Remove(int x)
    {
        int s = 1;
        Node *temp = head;
        Node *prev;
        if (head != NULL && temp->data == x)
        {
            RemoveatBeg();
            return 0;
        }
        else if (head != NULL)
        {
            while (temp->data != x && s < size)
            {
                prev = temp;
                temp = temp->next;
                s++;
            }
            if (temp->data == x)
            {
                if (temp->next == NULL)
                {
                    RemoveatEnd();
                    return 0;
                }
                prev->next = temp->next;
                delete temp;
                size--;
            }
            else
            {
                cout << "Element not found" << endl;
            }
        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    int Removeat(int x)
    {
        if (x == 1 && size > 0)
        {
            RemoveatBeg();
            return 0;
        }
        else if (x > 1 && x <= size)
        {
            Node *temp = head;
            Node *prev;
            for (int j = 1; j < x; j++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            size--;
            delete temp;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }

    void Print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList linklist;
    string choice;
    int element, pos;
    while (true)
    {
        cout << "\n------------------------------------------------" << endl;
        cout << "          1-> Insert at Begining                " << endl;
        cout << "          2-> Insert at X Position              " << endl;
        cout << "          3-> Insert after X Element            " << endl;
        cout << "          4-> Insert at End                     " << endl;
        cout << "          5-> Remove at Begining                " << endl;
        cout << "          6-> Remove at X Position              " << endl;
        cout << "          7-> Remove X Element                  " << endl;
        cout << "          8-> Remove at End                     " << endl;
        cout << "------------------------------------------------" << endl
             << endl;
        cout << ">> ";
        cin >> choice;

        if (choice == "1")
        {
            cout << "\nEnter the element: ";
            cin >> element;
            if (int(element))
            {
                linklist.InsertatBeg(element);
                cout << "New Linked List: ";
                linklist.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "2")
        {
            cout << "\nEnter the Position: ";
            cin >> pos;
            cout << "Enter the element: ";
            cin >> element;
            if (int(element) && int(pos))
            {
                linklist.Insertat(element, pos);
                cout << "New Linked List: ";
                linklist.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "3")
        {
            cout << "\nEnter the element after which you want to add: ";
            cin >> pos;
            cout << "Enter the element: ";
            cin >> element;
            if (int(element) && int(element))
            {
                linklist.Insertafter(element, pos);
                cout << "New Linked List: ";
                linklist.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "4")
        {
            cout << "\nEnter the element: ";
            cin >> element;
            if (int(element))
            {
                linklist.InsertatEnd(element);
                cout << "New Linked List: ";
                linklist.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "5")
        {
            linklist.RemoveatBeg();
            cout << "\nNew Linked List: ";
            linklist.Print();
        }

        else if (choice == "6")
        {
            cout << "\nEnter the Position to Remove: ";
            cin >> pos;
            if (int(pos))
            {
                linklist.Removeat(pos);
                cout << "New Linked List: ";
                linklist.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "7")
        {
            cout << "\nEnter the element you want to remove: ";
            cin >> element;
            if (int(element))
            {
                linklist.Remove(element);
                cout << "New Linked List: ";
                linklist.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "8")
        {
            linklist.RemoveatEnd();
            cout << "\nNew Linked List: ";
            linklist.Print();
        }

        else
        {
            exit(0);
        }
        cout << "Size: " << linklist.size << endl;
    }
}
