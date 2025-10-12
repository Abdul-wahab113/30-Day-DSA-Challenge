#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class Stack
{
    Node<T> *top;

public:
    // constructor.
    Stack() : top(nullptr) {}

    // destructor.
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T val);
    T pop();
    bool isEmpty();
    T stackTop();
};

template <typename T>
void Stack<T>::push(T stackVal)
{
    Node<T> *newNode = new Node<T>(stackVal);
    newNode->next = top;
    top = newNode;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw runtime_error("Stack Underflow!");
    }

    Node<T> *temp = top;
    T popedItem = temp->data;
    top = top->next;
    delete temp;

    return popedItem;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

template <typename T>
T Stack<T>::stackTop()
{
    if (isEmpty())
    {
        throw runtime_error("Stack is empty!");
    }
    else
        return top->data;
}

// Stack class ends here

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
    {
        return true;
    }
    else
        return false;
}

bool isSpace(char c)
{
    if (c == ' ')
    {
        return true;
    }
    else
        return false;
}

int getPrecedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }

    else
        return 0;
}

bool isBalanced(string exp)
{
    Stack<char> st;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (st.isEmpty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    // if the stack is empty means the given expression was balanced else unbalanced.
    return st.isEmpty();
}

string infixToPostix(string infixExp)
{
    // stack object creation for conversion.
    // the postfix conversion's backbone
    Stack<char> st;

    // initially set to an empty string.
    string postfixExp = "";

    for (int i = 0; infixExp[i] != '\0'; i++)
    {
        char current = infixExp[i];

        // skips the blank spaces from the given expression.
        if (isSpace(current))
        {
            continue;
        }

        // multi digit and floating point numbers
        if (isdigit(current) || current == '.')
        {
            string number;
            while (i < infixExp.length() && (isdigit(infixExp[i]) || infixExp[i] == '.'))
            {
                number += infixExp[i];
                i++;
            }
            i--;                        // Adjust loop counter
            postfixExp += number + " "; // Add the full number
        }

        // if the current is opening bracket.
        else if (current == '(')
        {
            st.push(current);
        }

        // if current is cosing bracket.

        else if (current == ')')
        {
            while (!st.isEmpty() && st.stackTop() != '(')
            {
                postfixExp += st.stackTop();
                postfixExp += " ";
                st.pop();
            }

            if (st.isEmpty())
                throw runtime_error("Mismatched Brackets");
            st.pop(); // this will pop the '('
        }

        // if current is operator
        else if (isOperator(current))
        {
            while (!st.isEmpty() && st.stackTop() != '(' && ((getPrecedence(current) < getPrecedence(st.stackTop())) || (getPrecedence(current) == getPrecedence(st.stackTop()) && current != '^')))
            {
                postfixExp += st.stackTop();
                postfixExp += " ";
                st.pop();
            }

            st.push(current);
        }

        else
        {
            string invalid_char_str(1, current);
            throw runtime_error("Invalid character in the expression :" + invalid_char_str);
        }
    }

    while (!st.isEmpty())
    {
        if (st.stackTop() == '(')
        {
            throw runtime_error("Mismatched Brackets.");
        }

        else
        {
            postfixExp += st.stackTop();
            postfixExp += " ";
            st.pop();
        }
    }

    return postfixExp;
}

double evaluatePostfix(const string &postfix)
{
    Stack<double> st;
    string current_token;

    // Loop through each character in the postfix string
    for (char c : postfix)
    {
        // If it is a space, process the token we have built.
        if (isSpace(c))
        {
            if (!current_token.empty())
            {
                // -- This is the token processing logic --
                if (isOperator(current_token[0]) && current_token.length() == 1)
                {
                    double val2 = st.pop();
                    double val1 = st.pop();
                    switch (current_token[0])
                    {
                    case '+':
                        st.push(val1 + val2);
                        break;
                    case '-':
                        st.push(val1 - val2);
                        break;
                    case '*':
                        st.push(val1 * val2);
                        break;
                    case '/':
                        if (val2 == 0)
                            throw runtime_error("Error: Division by zero.");
                        st.push(val1 / val2);
                        break;
                    case '%':
                        if (val2 == 0)
                            throw runtime_error("Error: Division by zero.");
                        st.push(fmod(val1, val2));
                        break;
                    case '^':
                        st.push(pow(val1, val2));
                        break;
                    }
                }
                else // It's a number
                {
                    try
                    {
                        st.push(stod(current_token));
                    }
                    catch (const invalid_argument &)
                    {
                        throw runtime_error("Invalid number in expression: " + current_token);
                    }
                }
                // Reset the token for the next one
                current_token = "";
            }
        }
        // If it's not a space, just add the character to our current token.
        else
        {
            current_token += c;
        }
    }

    // This is necessary if the postfix string doesn't end with a space.
    if (!current_token.empty())
    {
        // (The token processing logic is duplicated here for the last token)
        if (isOperator(current_token[0]) && current_token.length() == 1)
        {
            double val2 = st.pop();
            double val1 = st.pop();
            switch (current_token[0])
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                if (val2 == 0)
                    throw runtime_error("Error: Division by zero.");
                st.push(val1 / val2);
                break;
            case '%':
                if (val2 == 0)
                    throw runtime_error("Error: Division by zero.");
                st.push(fmod(val1, val2));
                break;
            case '^':
                st.push(pow(val1, val2));
                break;
            }
        }
        else
        {
            st.push(stod(current_token));
        }
    }

    // Final check: a valid expression should leave exactly one result on the stack.
    double result = st.pop();
    if (!st.isEmpty())
    {
        throw runtime_error("Invalid postfix expression: too many operands left.");
    }
    return result;
}

int main()
{
    string infixExp;
    cout << "Enter an infix expression: ";
    getline(cin, infixExp);

    try
    {
        if (!isBalanced(infixExp))
        {
            throw runtime_error("Error: Unbalanced brackets.");
        }
        cout << "Brackets are balanced." << endl;

        string postfixExp = infixToPostix(infixExp);
        cout << "Postfix form: " << postfixExp << endl;

        double result = evaluatePostfix(postfixExp);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error &e)
    {
        // Catches any errors from any function and prints them gracefully.
        cerr << e.what() << endl;
    }

    return 0;
}