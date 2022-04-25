#include <iostream>
using namespace std;

class DoubleLinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };
    Node *head = NULL;

public:
    int size = 0;

    void InsertatBeg(int x)
    {
        Node *new_node = new Node;
        new_node->data = x;
        new_node->next = head;
        new_node->prev = NULL;
        if (head != NULL)
        {
            new_node->next = head;
            new_node->prev = NULL;
            head->prev = new_node;
        }
        head = new_node;
        size++;
    }

    void InsertatEnd(int x)
    {
        if (size == 0)
        {
            InsertatBeg(x);
        }
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
            new_node->prev = temp;
            temp->next = new_node;
            size++;
        }
    }

    void Insertafter(int element, int eleafter)
    {
        int s = 1;
        Node *new_node = new Node;
        Node *prev = head;
        Node *temp;
        if (head != NULL)
        {
            while (prev->data != eleafter && s < size)
            {
                prev = prev->next;
                s++;
            }
            if (prev->data == eleafter && s < size)
            {
                new_node->data = element;
                new_node->next = prev->next;
                new_node->prev = prev;
                temp = prev->next;
                temp->prev = new_node;
                prev->next = new_node;
                size++;
            }
            else if (prev->data == eleafter && s == size)
            {
                InsertatEnd(element);
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

    int Insertat(int element, int pos)
    {
        if (pos == 1)
        {
            InsertatBeg(element);
        }
        else if (pos == size + 1)
        {
            InsertatEnd(element);
        }

        else if (pos > 1)
        {
            Node *new_node = new Node;
            Node *temp = head;
            Node *temp2;
            for (int i = 1; i < pos - 1; i++)
            {
                if (temp->next == NULL)
                {
                    cout << "Index out of range" << endl;
                    return 0;
                }
                temp = temp->next;
            }
            new_node->data = element;
            new_node->next = temp->next;
            new_node->prev = temp;
            temp2 = temp->next;
            temp2->prev = new_node;
            temp->next = new_node;
            size++;
        }
        else
        {
            cout << "Enter valid Index" << endl;
        }
    }

    void RemoveatBeg()
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
            Node *temp2;
            head = temp->next;
            temp2 = temp->next;
            temp2->prev = NULL;
            delete temp;
            size--;
        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    void RemoveatEnd()
    {
        if (size == 1)
        {
            RemoveatBeg();
        }

        else if (size > 0)
        {
            Node *temp = head;
            Node *last;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            last = temp->prev;
            last->next = NULL;
            delete temp;
            size--;
        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    int Remove(int element)
    {
        int s = 1;
        if (head != NULL && head->data == element)
        {
            RemoveatBeg();
            return 0;
        }
        else if (head != NULL)
        {
            Node *temp = head;
            Node *prev;
            while (temp->data != element && s < size)
            {
                temp = temp->next;
                s++;
            }
            if (temp->data == element)
            {
                if (temp->next == NULL)
                {
                    RemoveatEnd();
                    return 0;
                }
                prev = temp->next;
                prev->prev = temp->prev;
                prev = temp->prev;
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

    int Removeat(int pos)
    {
        if (pos == 1 && size > 0)
        {
            RemoveatBeg();
        }
        else if (pos == size && size > 0)
        {
            RemoveatEnd();
        }
        else if (pos > 1 && pos < size)
        {
            Node *temp = head;
            Node *prev;
            for (int j = 1; j < pos; j++)
            {
                temp = temp->next;
            }
            prev = temp->next;
            prev->prev = temp->prev;
            prev = temp->prev;
            prev->next = temp->next;
            delete temp;
            size--;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }

    void Print()
    {
        Node *temp = head;
        if (head != NULL)
        {
            cout << temp->data << " ";
            while (temp->next != NULL)
            {
                temp = temp->next;
                cout << temp->data << " ";
            }
        }
        cout << endl;
    }

    void PrintReverse()
    {
        Node *temp = head;
        Node *reverse;
        while (temp != NULL)
        {
            reverse = temp;
            temp = temp->next;
        }
        while (reverse->prev != NULL)
        {
            cout << reverse->data << " ";
            reverse = reverse->prev;
        }
        cout << reverse->data << endl;
    }
};

int main()
{
    string choice;
    int element, pos;
    DoubleLinkedList dll;
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
                dll.InsertatBeg(element);
                cout << "New Linked List: ";
                dll.Print();
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
                dll.Insertat(element, pos);
                cout << "New Linked List: ";
                dll.Print();
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
            if (int(element) && int(pos))
            {
                dll.Insertafter(element, pos);
                cout << "New Linked List: ";
                dll.Print();
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
                dll.InsertatEnd(element);
                cout << "New Linked List: ";
                dll.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "5")
        {
            dll.RemoveatBeg();
            cout << "New Linked List: ";
            dll.Print();
        }

        else if (choice == "6")
        {
            cout << "\nEnter the Position to Remove: ";
            cin >> pos;
            if (int(pos))
            {
                dll.Removeat(pos);
                cout << "New Linked List: ";
                dll.Print();
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
                dll.Remove(element);
                cout << "New Linked List: ";
                dll.Print();
            }
            else
            {
                break;
            }
        }

        else if (choice == "8")
        {
            dll.RemoveatEnd();
            cout << "\nNew Linked List: ";
            dll.Print();
        }

        else if (choice == "0")
        {
            cout << "\nReversed Linked List: ";
            dll.PrintReverse();
        }
        else
        {
            exit(0);
        }

        cout << "Size: " << dll.size << endl;
    }
}