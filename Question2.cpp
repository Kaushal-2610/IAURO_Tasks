#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;  
    Node *next; 
    Node(int x) : data(x), next(nullptr) {} 
};

// Solution class contains main function detectCycle
class Solution
{
public:
    bool detectCycle(Node *head)
    {
        // Condition : if list is empty or has only one node 
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        Node *slow = head; 
        Node *fast = head; 

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       
            fast = fast->next->next; 

            if (slow == fast)
            {
                return true; // Cycle detected
            }
        }
        return false; // No Cycle
    }
};

// Function to add a node at the end of linked list
Node *addNode(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        return newNode;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int main()
{
    // Example 1 : List containing Loop
    Node *head1 = new Node(20);
    head1 = addNode(head1, 30);
    head1 = addNode(head1, 40);
    head1 = addNode(head1, 60);
    head1 = addNode(head1, 80);

    // Creating a cycle where the last node points to the 3rd node (40)
    head1->next->next->next->next->next = head1->next->next;
    Solution solution;
    cout<< "Example 1 : [20,30,40,60,80] = " <<(solution.detectCycle(head1) ? "Loop Detected" : "No Loop Detected") <<endl;
    
    // Example 2 : List containing Loop
    Node* head2 = new Node(6);
    head2 = addNode(head2, 4);
    head2 = addNode(head2, 2);
    head2 = addNode(head2, 8);

    cout<< "Example 2 : [6,4,2,8] = " <<(solution.detectCycle(head2) ? "Loop Detected" : "No Loop Detected") <<endl;
    return 0;
}