/* 
Reverse nodes of a singly linked list in groups of size k.
• Example:
  Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
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
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void addNode(int v)
    {
        Node* n = new Node(v);
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
        Node* t = head;
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    Node* getHead()
    {
        return head;
    }

    void setHead(Node* h)
    {
        head = h;
    }

    static Node* reverseInGroups(Node* start, int k)
    {
        if (!start) return nullptr;

        Node* curr = start;
        Node* prev = nullp*
