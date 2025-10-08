#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// creating a new node
Node *createNewNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// insertion at last node
void insertAtEnd(Node *&head, Node *&tail, int value)
{

    // Better and Optimal version for singly linked list.
    Node *newNode = createNewNode(value);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// insertion at first node
void insertAtStart(Node *&head, Node *&tail, int value)
{
    Node *newNode = createNewNode(value);
    newNode->next = head;
    head = newNode;

    if (tail == NULL)
    {
        tail = newNode;
    }
}

// insertion at specific position
void insertAtPosition(Node *&head, int pos, int value)
{
    Node *newNode = createNewNode(value);

    if (pos <= 1 || head == NULL)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// insert in sorted linked list
void insertInSortedLL(Node *&head, int value)
{
    Node *newNode = createNewNode(value);

    if (head == NULL || value < head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// searching a target element
void searchElement(Node *head, int target)
{
    if (head == NULL)
    {
        cout << "Linked List is EMPTY!" << endl;
        return;
    }

    int count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            cout << "The Target Value: " << target << " is Found at position: " << count << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << "The Target Value: " << target << " is NOT Found in the Linked List!" << endl;
}

// Move-to-Head Approach
void MoveToFirst(Node *&head, int target)
{
    if (head == NULL)
    {
        cout << "The Linked List is EMPTY!" << endl;
        return;
    }

    if (head->data == target)
        return;

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL && curr->data != target)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Element not found!" << endl;
        return;
    }

    prev->next = curr->next;
    curr->next = head;
    head = curr;
}

// display all elements
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is EMPTY!" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// count nodes
int nodeCount(Node *head)
{
    if (head == NULL)
        return 0;
    return 1 + nodeCount(head->next);
}

// sum of all nodes
int sumOfNodes(Node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

// find max element
int maxElement(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is EMPTY!" << endl;
        return INT_MIN;
    }

    int max = head->data;
    while (head != NULL)
    {
        if (head->data > max)
            max = head->data;
        head = head->next;
    }
    return max;
}

// find min element
int minElement(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is EMPTY!" << endl;
        return INT_MAX;
    }

    int min = head->data;
    while (head != NULL)
    {
        if (head->data < min)
            min = head->data;
        head = head->next;
    }
    return min;
}

// delete from start
void deleteAtStart(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is EMPTY! Nothing to Delete." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

// delete from end
void deleteAtEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is EMPTY! Nothing to Delete." << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// reversing the linked list:
void reverse(Node *&head)
{
    // using sliding pointer.
    if (head == NULL)
    {
        cout << "The Linked List is Empty!" << endl;
        return;
    }
    else
    {
        Node *p = head;
        Node *q = NULL;
        Node *r = NULL;

        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        head = q;
    }
}

// middle node of the LL
void middleOfLL(Node *head)
{
    if (head == NULL)
    {
        cout << "The Linked list is EMPTY!" << endl;
        return;
    }

    Node *temp = head;
    Node *followup = head;

    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next->next;
        followup = followup->next;
    }

    cout << "The middle node of the Linked List :" << followup->data << endl;
}

// main function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int choice, value, pos, target;

    cout << "==============================" << endl;
    cout << "   Singly Linked List Menu" << endl;
    cout << "==============================" << endl;

    do
    {
        cout << "\n1. Insert at Start";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Specific Position";
        cout << "\n4. Insert in Sorted Linked List";
        cout << "\n5. Display Linked List";
        cout << "\n6. Count Nodes";
        cout << "\n7. Sum of Nodes";
        cout << "\n8. Find Maximum Element";
        cout << "\n9. Find Minimum Element";
        cout << "\n10. Search Element";
        cout << "\n11. Move Element to First (Move-to-Head)";
        cout << "\n12. Delete from Start";
        cout << "\n13. Delete from End";
        cout << "\n14. Reverse the Linked List";
        cout << "\n15. Middle of the Linked List";
        cout << "\n0. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at start: ";
            cin >> value;
            insertAtStart(head, tail, value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            insertAtEnd(head, tail, value);
            break;

        case 3:
            cout << "Enter position and value to insert: ";
            cin >> pos >> value;
            insertAtPosition(head, pos, value);
            break;

        case 4:
            cout << "Enter value to insert in sorted linked list: ";
            cin >> value;
            insertInSortedLL(head, value);
            break;

        case 5:
            cout << "Current Linked List: ";
            display(head);
            break;

        case 6:
            cout << "Number of Nodes: " << nodeCount(head) << endl;
            break;

        case 7:
            cout << "Sum of All Nodes: " << sumOfNodes(head) << endl;
            break;

        case 8:
            cout << "Maximum Element: " << maxElement(head) << endl;
            break;

        case 9:
            cout << "Minimum Element: " << minElement(head) << endl;
            break;

        case 10:
            cout << "Enter value to search: ";
            cin >> target;
            searchElement(head, target);
            break;

        case 11:
            cout << "Enter value to move to head: ";
            cin >> target;
            MoveToFirst(head, target);
            break;

        case 12:
            deleteAtStart(head);
            break;

        case 13:
            deleteAtEnd(head);
            break;
        case 14:
            reverse(head);
            break;

        case 15:
            middleOfLL(head);
            break;

        case 0:
            cout << "Exiting Program... Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
