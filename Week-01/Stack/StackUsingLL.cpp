#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{

    Node *top;

public:
    // constructor
    Stack()
    {
        top = NULL;
    }
    Node *createNewNode(int);
    void push(int);
    void display();
    int pop();
    int peek();
    int peekAtPos(int);
    bool isEmpty();
    bool isFull();
    // destructor
    ~Stack()
    {
        Node *temp;
        while (top != NULL)
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }
};

Node *Stack::createNewNode(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void Stack::push(int val)
{

    Node *newNode = createNewNode(val);

    newNode->next = top;
    top = newNode;
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
        return;
    }
    else
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int Stack::pop()
{
    int x = -1;

    if (isEmpty())
    {
        cout << "Stack Undeflow!" << endl;
        return x;
    }

    else
    {
        Node *temp = top;
        x = top->data;
        top = top->next;
        delete temp;
    }
    return x;
}

int Stack::peek()
{
    int x = -1;
    if (isEmpty())
    {

        cout << "Stack Under Flow!" << endl;
        return x;
    }

    else
    {
        x = top->data;
    }

    return x;
}

int Stack::peekAtPos(int pos)
{
    Node *temp = top;
    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        return temp->data;
    }

    return -1;
}

bool Stack::isEmpty()
{
    return top == NULL;
}

bool Stack::isFull()
{
    Node *newNode = new Node;
    if (newNode == NULL)
    {
        // Heap is full, allocation failed
        return true;
    }
    else
    {
        // Allocation succeeded, so not full
        delete newNode; // Free the test node
        return false;
    }
}

int main()
{
    Stack s;
    int choice, value, position;

    cout << "\n--- C++ Stack Implementation (Linked List) ---" << endl;

    // A loop to make the menu interactive
    while (true)
    {
        cout << "\n********* MENU *********" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << " (Removes and returns top value)" << endl;
        cout << "3. Peek" << " (Views top value)" << endl;
        cout << "4. Peek at Position" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Check if Empty" << endl;
        cout << "7. Exit" << endl;
        cout << "************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            s.push(value);
            cout << value << " has been pushed onto the stack." << endl;
            break;

        case 2:
            if (s.isEmpty())
            {
                cout << "Stack Underflow! Cannot pop." << endl;
            }
            else
            {
                cout << "Popped value: " << s.pop() << endl;
            }
            break;

        case 3:
            if (s.isEmpty())
            {
                cout << "Stack is empty! Nothing to peek." << endl;
            }
            else
            {
                cout << "Top element is: " << s.peek() << endl;
            }
            break;

        case 4:
            cout << "Enter position to peek at (1 is the top): ";
            cin >> position;
            if (position <= 0)
            {
                cout << "Invalid position. Please enter a positive number." << endl;
            }
            else
            {
                value = s.peekAtPos(position);
                if (value == -1)
                { // Assuming -1 means not found or invalid
                    cout << "Position " << position << " is invalid or out of bounds." << endl;
                }
                else
                {
                    cout << "Value at position " << position << " is: " << value << endl;
                }
            }
            break;

        case 5:
            cout << "Stack elements (Top to Bottom): ";
            s.display();
            cout << endl;
            break;

        case 6:
            if (s.isEmpty())
            {
                cout << "The stack is EMPTY." << endl;
            }
            else
            {
                cout << "The stack is NOT EMPTY." << endl;
            }
            break;

        case 7:
            cout << "Exiting program. Goodbye!" << endl;
            return 0; // Exit the program

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}