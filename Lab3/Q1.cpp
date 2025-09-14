/* 
1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
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

    bool checkPalindrome()
    {
        if (!head || !head->next)
        {
            return true;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* prev = nullptr;
        Node* curr = slow;
        while (curr)
        {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        Node* first = head;
        Node* second = prev;
        while (second)
        {
            if (first->data != second->data)
            {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
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
};

int main()
{
    LinkedList l;
    l.addNode(1);
    l.addNode(2);
    l.addNode(3);
    l.addNode(2);
    l.addNode(1);

    l.show();

    if (l.checkPalindrome())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
