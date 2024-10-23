### Question 1 : Use Case: Shipping Company Optimization
Source Code :

```bash
#include <bits/stdc++.h>
using namespace std;

// Here Vectors are used in place of array as input array size in not mentioned
int minContainersNeeded(vector<int> &shipments, vector<int> &containerLimits)
{
    sort(containerLimits.begin(), containerLimits.end(), greater<int>());
    int containerCount = 0;
    for (int i = 0; i < shipments.size(); i++)
    {
        int unitsToPlace = shipments[i];

        while (unitsToPlace > 0)
        {
            if (containerCount >= containerLimits.size())
            {
                return -1;
            }
            if (containerLimits[containerCount] >= unitsToPlace)
            {
                containerLimits[containerCount] -= unitsToPlace;
                unitsToPlace = 0;
            }
            else
            {
                unitsToPlace -= containerLimits[containerCount];
                containerLimits[containerCount] = 0;
                containerCount++;
            }
        }
    }
    return containerCount + 1;
}

int main()
{
    vector<int> shipments = {10, 20, 30};
    vector<int> containerLimits = {15, 15, 20, 10};

    int result = minContainersNeeded(shipments, containerLimits);

    if (result != -1)
    {
        cout << "Minimum number of containers needed: " << result << endl;
    }
    else
    {
        cout << "Insufficient container capacity" << endl;
    }

    return 0;
}
```

Output :

![image](https://github.com/user-attachments/assets/9fa90a38-6616-4ceb-bbf3-3914876c434a)


### Question 2 : UGiven the head of a linked list representing the stages of a package's journey, you need to determine if there is a structural issue causing an infinite loop.
Source Code :

```bash
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
                return true; 
            }
        }
        return false; 
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
```

Output :

![{991E5718-B845-4BB1-9F76-924ABCD74C28}](https://github.com/user-attachments/assets/e08f42eb-2a19-4972-8a3c-cc811ac7d3ef)

