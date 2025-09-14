/* 
Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion.
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

class CircularList
{
    Node* head;

public:
    CircularList()
    {
        head = nullptr;
    }

    void create(int n)
    {
        if (n <= 0) return;

        Node* prev = nullptr;
        for (int i = 1; i <= n; i++)
        {
            Node* x = new Node(i);
            if (!head)
            {
                head = x;
            }
            else
            {
                prev->next = x;
            }
            prev = x;
        }
        prev->next = head;
    }

    int josephus(int k)
    {
        if (!head || head->next == head) return head->data;

        Node* curr = head;
        Node* prev = nullptr;

        while (curr->next != curr)
        {
            for (int count = 1; count < k; count++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        head = curr;
        return curr->data;
    }
};

int main()
{
    CircularList circle;
    circle.create(7);
    int survivor = circle.josephus(3);
    cout << "Survivor at position: " << survivor;
    return 0;
}
