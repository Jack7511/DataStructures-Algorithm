#include <iostream>
#include <string>
using namespace std;

template <class T>
class CircularDoubleLinkedList
{
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };
    Node *head = NULL;
    int size = 0;

public:
    int Size()
    {
        return size;
    }

    void InsertatBeg(T x)
    {
        Node *new_node = new Node;
        Node *last;
        new_node->data = x;
        new_node->next = new_node;
        new_node->prev = new_node;
        if (head != NULL)
        {
            new_node->next = head;
            new_node->prev = head->prev;
            head->prev = new_node;
        }
        head = new_node;
        last = head->prev;
        last->next = head;
        size++;
    }

    void InsertatEnd(T x)
    {
        if (size == 0)
        {
            InsertatBeg(x);
        }
        else
        {
            Node *new_node = new Node;
            Node *temp;
            temp = head->prev;
            new_node->data = x;
            new_node->prev = temp;
            new_node->next = head;
            temp->next = new_node;
            head->prev = new_node;
            size++;
        }
    }

    void Insertafter(T element, T eleafter)
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

    int Insertat(T element, int pos)
    {
        if (pos == 1)
        {
            InsertatBeg(element);
        }
        else if (pos == size + 1)
        {
            InsertatEnd(element);
        }
        else if (pos > 1 && size > 0)
        {
            Node *new_node = new Node;
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                if (temp->next == head)
                {
                    cout << "Index out of range" << endl;
                    return 0;
                }
                temp = temp->next;
            }
            new_node->data = element;
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next = new_node;
            temp = new_node->next;
            temp->prev = new_node;
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
            Node *last;
            Node *first;
            first = head->next;
            first->prev = head->prev;
            head = first;
            last = head->prev;
            last->next = head;
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
            last = head->prev;
            temp = last->prev;
            temp->next = head;
            head->prev = temp;
            delete last;
            size--;
        }
        else
        {
            cout << "Linked List is Empty" << endl;
        }
    }

    int Remove(T element)
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
                if (temp->next == head)
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
            return 0;
        }
        else if (pos == size && size > 0)
        {
            RemoveatEnd();
            return 0;
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
            cout << temp->data << ", ";
            for (int i = 1; i < size; i++)
            {
                temp = temp->next;
                cout << temp->data << ", ";
            }
        }
        cout << endl;
    }

    void PrintReverse()
    {
        if (head != NULL)
        {
            Node *last = head->prev;
            for (int i = size; i > 0; i--)
            {
                cout << last->data << ", ";
                last = last->prev;
            }
        }
        cout << endl;
    }

    void Sort()
    {
        if (size > 0)
        {
            Node *i = head;
            Node *j = i->next;

            for (int x = 0; x < size; x++)
            {
                for (int y = x + 1; y < size; y++)
                {
                    if (j->data > i->data)
                    {
                        T temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                    j = j->next;
                }
                i = i->next;
                j = i->next;
            }
        }
        else
        {
            cout << "\nLinked List is Empty";
        }
    }

    CircularDoubleLinkedList operator+(CircularDoubleLinkedList dll2)
    {
        if (size > 0 && dll2.size > 0)
        {
            Node *last = head->prev;
            Node *temp = dll2.head;

            for (int i = 0; i < dll2.size - 1; i++)
            {
                Node *new_node = new Node;
                new_node->data = temp->data;
                new_node->prev = last;
                last->next = new_node;
                temp = temp->next;
                last = new_node;
            }

            Node *temp2 = new Node;
            temp2->prev = last;
            temp2->data = temp->data;
            temp2->next = head;
            head->prev = temp2;
            last->next = temp2;
            size += dll2.size;
        }
        else
        {
            cout << "\nOne or both Linked List is Empty";
        }
    }

    void user_interface()
    {
        int choice, pos;
        T element, eleaft;

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

            if (choice == 0)
            {
                Sort();
                cout << "Sorted Linked List: ";
                Print();
            }

            else if (choice == 1)
            {
                cout << "\nEnter the element: ";
                cin >> element;
                InsertatBeg(element);
                cout << "New Linked List: ";
                Print();
            }

            else if (choice == 2)
            {
                cout << "\nEnter the Position: ";
                cin >> pos;
                cout << "Enter the element: ";
                cin >> element;
                Insertat(element, pos);
                cout << "New Linked List: ";
                Print();
            }

            else if (choice == 3)
            {
                cout << "\nEnter the element after which you want to add: ";
                cin >> eleaft;
                cout << "Enter the element: ";
                cin >> element;
                Insertafter(element, eleaft);
                cout << "New Linked List: ";
                Print();
            }

            else if (choice == 4)
            {
                cout << "\nEnter the element: ";
                cin >> element;
                InsertatEnd(element);
                cout << "New Linked List: ";
                Print();
            }

            else if (choice == 5)
            {
                RemoveatBeg();
                cout << "New Linked List: ";
                Print();
            }

            else if (choice == 6)
            {
                cout << "\nEnter the Position to Remove: ";
                cin >> pos;
                Removeat(pos);
                cout << "New Linked List: ";
                Print();
            }

            else if (choice == 7)
            {
                cout << "\nEnter the element you want to remove: ";
                cin >> element;
                Remove(element);
                cout << "New Linked List: ";
                Print();
            }

            else if (choice == 8)
            {
                RemoveatEnd();
                cout << "\nNew Linked List: ";
                Print();
            }

            else
            {
                break;
            }

            cout << "Size: " << size << endl;
        }
    }
};

int main()
{
    int choice;
    CircularDoubleLinkedList <string> dll, dll2;

    while (true)
    {
        cout << "\n------------------------------------------------" << endl;
        cout << "          1-> First Linked List                 " << endl;
        cout << "          2-> Second Linked List                " << endl;
        cout << "          3-> Join Both Linked List             " << endl;
        cout << "------------------------------------------------" << endl
             << endl;

        cout << ">> ";
        cin >> choice;

        if (choice == 1)
        {
            dll.user_interface();
        }

        else if (choice == 2)
        {
            dll2.user_interface();
        }

        else if (choice == 3)
        {
            dll + dll2;
            cout << "\nNew Linked List: ";
            dll.Print();
            cout << "Reversed Linked List: ";
            dll.PrintReverse();
            cout << "Size: " << dll.Size() << endl;
        }

        else
        {
            exit(0);
        }
    }
}