/* 
Implement functions for conversion:
1. Convert a singly linked list into a doubly linked list.
2. Convert a singly linked list into a circular linked list.
• Demonstrate both conversions with sample input lists.
*/

#include <iostream>
using namespace std;

class SNode
{
public:
    int data;
    SNode* next;
    SNode(int v) { data = v; next = nullptr; }
};

class DNode
{
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int v) { data = v; next = nullptr; prev = nullptr; }
};

class SinglyList
{
    SNode* head;
public:
    SinglyList() { head = nullptr; }

    void add(int v)
    {
        SNode* n = new SNode(v);
        if (!head)
        {
            head = n;
            return;
        }
        SNode* t = head;
        while (t->next)
        {
            t = t->next;
        }
        t->next = n;
    }

    void show()
    {
        SNode* t = head;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    SNode* getHead() { return head; }

    DNode* toDoubly()
    {
        if (!head) return nullptr;
        SNode* t = head;
        DNode* dHead = nullptr;
        DNode* dPrev = nullptr;

        while (t)
        {
            DNode* dn = new DNode(t->data);
            if (!dHead) dHead = dn;
            dn->prev = dPrev;
            if (dPrev) dPrev->next = dn;
            dPrev = dn;
            t = t->next;
        }
        return dHead;
    }

    SNode* toCircular()
    {
        if (!head) return nullptr;
        SNode* t = head;
        while (t->next)
        {
            t = t->next;
        }
        t->next = head;
        return head;
    }
};

void showD(DNode* h)
{
    while (h)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

void showC(SNode* h, int n)
{
    SNode* t = h;
    for (int i = 0; i < n; i++)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main()
{
    SinglyList L;
    L.add(10);
    L.add(20);
    L.add(30);
    L.add(40);

    cout << "Singly: ";
    L.show();

    DNode* d = L.toDoubly();
    cout << "Doubly: ";
    showD(d);

    SNode* c = L.toCircular();
    cout << "Circular: ";
    showC(c, 8);

    return 0;
}
