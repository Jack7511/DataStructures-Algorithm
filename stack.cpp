#include <iostream>
#define MAX 5
using namespace std;

struct stack
{
	int ele[MAX];
	int top;
};

typedef struct stack STACK;
STACK s;

int isEmpty(void);
int isFull(void);
void push(int new_ele);
int pop(void);
int peek(void);
void traverse(void);

int main()
{
	int option, choice = 1, num;
	s.top = -1;
	cout << "STACK OPERATIONS" << endl;

	while (choice)
	{
		cout << "------------------------------------------------" << endl;
		cout << "          1-->   PUSH                           " << endl;
		cout << "          2-->   POP                            " << endl;
		cout << "          3-->   PEEK                           " << endl;
		cout << "          4-->   TRAVERSE                       " << endl;
		cout << "          5-->   EXIT                           " << endl;
		cout << "-------------------------------------------------" << endl;

		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the number to be pushed: ";
			cin >> num;
			push(num);
			break;

		case 2:
			num = pop();
			if (num != -1)
				cout << "Number " << num << " is Popped from the stack";
			break;

		case 3:
			cout << "Top elements with PEEK operation: " << peek() << endl;
			break;

		case 4:
			traverse();
			break;

		case 5:
			return 0;

		default:
			cout << "Type 1 to continue: ";
			cin >> option;
		}
	}
}

int isEmpty(void)
{
	if (s.top == -1)
	{
		cout << "stack underflow" << endl;
		return 1;
	}
	return 0;
}

int isFull(void)
{
	if (s.top == MAX - 1)
	{
		cout << "stack overflow" << endl;
		return 1;
	}
	return 0;
}

void push(int new_ele)
{
	if (!isFull())
		s.ele[++s.top] = new_ele;
}

int pop(void)
{
	if (!isEmpty())
		return (s.ele[s.top--]);
	return -1;
}

int peek(void)
{
	return s.ele[s.top];
}

void traverse(void)
{

	if (s.top != -1)
	{
		cout << "status of the stack is: ";
		for (int i = s.top; i >= 0; i--)
		{
			cout << s.ele[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "stack is empty" << endl;
	}
}
