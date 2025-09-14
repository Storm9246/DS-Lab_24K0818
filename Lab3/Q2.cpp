/* 
2. Merge Two Sorted Singly Linked Lists
Implement a function to merge two sorted singly linked lists into one sorted list.

Lab Manual 03

• Example:
  List A: 1 → 3 → 5
  List B: 2 → 4 → 6
  Output: 1 → 2 → 3 → 4 → 5 → 6
• Bonus: Solve without creating new nodes (rearrange pointers).
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int v)
    {
        data = v;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    void addNode(int val)
    {
        Node* n = new Node(val);
        if (!head)
        {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next)
        {
            t = t->next;
        }
        t->next = n;
    }

    void show()
    {
        Node* x = head;
        while (x)
        {
            cout << x->data << " ";
            x = x->next;
        }
        cout << endl;
    }

    static Node* mergeSorted(Node* h1, Node* h2)
    {
        if (!h1) return h2;
        if (!h2) return h1;

        Node* res = nullptr;
        Node* tail = nullptr;

        if (h1->data < h2->data)
        {
            res = h1;
            h1 = h1->next;
        }
        else
        {
            res = h2;
            h2 = h2->next;
        }

        tail = res;

        while (h1 && h2)
        {
            if (h1->data < h2->data)
            {
                tail->next = h1;
                h1 = h1->next;
            }
            else
            {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }

        if (h1)
        {
            tail->next = h1;
        }
        else
        {
            tail->next = h2;
        }

        return res;
    }
};

int main()
{
    LinkedList A, B;

    A.addNode(1);
    A.addNode(3);
    A.addNode(5);

    B.addNode(2);
    B.addNode(4);
    B.addNode(6);

    cout << "List A: ";
    A.show();
    cout << "List B: ";
    B.show();

    Node* merged = LinkedList::mergeSorted(A.head, B.head);

    cout << "Merged: ";
    Node* p = merged;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    return 0;
}
