#include <iostream>

using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *stackArray;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        this->stackArray = new int[size];
    }

    ~Stack()
    {
        delete[] stackArray;
    }

    void push(int value);
    int pop();
    int peekAtTop();
    int peekAtPosition(int position);
    bool isEmpty();
    bool isFull();
    void display();
};

void Stack::push(int value)
{
    if (top < size - 1)
    {
        top++;
        stackArray[top] = value;
    }
    else
    {
        cout << "Stack Overflow!" << endl;
    }
}

int Stack::pop()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
        return x;
    }
    else
    {
        x = stackArray[top];
        top--;
    }
    return x;
}

int Stack::peekAtTop()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "The Stack is EMPTY!" << endl;
        return x;
    }
    else
    {
        x = stackArray[top];
    }
    return x;
}

int Stack::peekAtPosition(int position)
{
    int x = -1;

    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return x;
    }
    else if (position < 1 || position > top + 1)
    {
        cout << "Invalid position! Enter a value between 1 and " << top + 1 << "." << endl;
        return x;
    }
    else
    {

        int index = top - position + 1;
        x = stackArray[index];
    }
    return x;
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == size - 1;
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int size;
    cout << "Enter the desired size of the stack: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size. The size must be a positive number. Exiting." << endl;
        return 1;
    }

    Stack stc(size);
    int choice, value, position;

    do
    {
        cout << "\n********* STACK MENU (CLASS VERSION) *********" << endl;
        cout << "1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
        cout << "3. Peek at the top element" << endl;
        cout << "4. Peek at a specific position" << endl;
        cout << "5. Display the stack" << endl;
        cout << "6. Check if empty" << endl;
        cout << "7. Check if full" << endl;
        cout << "0. Exit" << endl;
        cout << "********************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            stc.push(value);
            break;
        case 2:
            value = stc.pop();
            if (value != -1)
            {
                cout << "Popped value: " << value << endl;
            }
            break;
        case 3:
            value = stc.peekAtTop();
            if (value != -1)
            {
                cout << "The top element is: " << value << endl;
            }
            break;
        case 4:
            cout << "Enter position to peek at (1 is the top): ";
            cin >> position;
            value = stc.peekAtPosition(position);
            if (value != -1)
            {
                cout << "The value at position " << position << " is: " << value << endl;
            }
            break;
        case 5:
            cout << "Stack (from top to bottom): ";
            stc.display();
            break;
        case 6:
            if (stc.isEmpty())
                cout << "Result: The stack is EMPTY." << endl;
            else
                cout << "Result: The stack is NOT EMPTY." << endl;
            break;
        case 7:
            if (stc.isFull())
                cout << "Result: The stack is FULL." << endl;
            else
                cout << "Result: The stack is NOT FULL." << endl;
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number from 0 to 7." << endl;
        }
    } while (choice != 0);

    return 0;
}